#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
const int MAXN = 3;
int a[MAXN+1][MAXN+1][MAXN+1];
int count[10];


int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("C-small-attempt0.in");
	fout.open("C-small-attempt0.out");
	int T;
	fin>>T;
	for (int i = 1;i<=T;i++)
	{
		for (int j1 = 0;j1<=MAXN;j1++)
			for (int j2 = 0;j2<=MAXN;j2++)
				for (int j3 = 0;j3<=MAXN;j3++)
					a[j1][j2][j3] = 0;
		int J,P,S,K;
		fin>>J>>P>>S>>K;
		int count = 0;
		string ans = "";
		for (int j1 = 1;j1<=J;j1++)
			for (int j2 = 1;j2<=P;j2++)
				for (int j3 = 1;j3<=S;j3++)
				{
					if (a[j1][j2][0]<K && a[j1][0][j3]<K && a[0][j2][j3]<K)
					{
						char c1 = j1+'0';
						char c2 = j2+'0';
						char c3 = j3+'0';
						a[j1][j2][0]++;
						a[j1][0][j3]++;
						a[0][j2][j3]++;
						count++;
						ans = ans+c1+" "+c2+" "+c3+"\n";
					}
				}
		fout<<"Case #"<<i<<": "<<count<<"\n"<<ans;
	}
	fin.close();
	fout.close();
	return 0;
}