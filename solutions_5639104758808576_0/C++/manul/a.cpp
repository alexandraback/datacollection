#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int t;
	cin>>t;
	int u = 1;
	while(t--)
	{
		int mx = 0, li, sum = 0;
		cin>>li;
		for (int i = 0; i < li + 1; i++)
		{
			if (sum < i)
			{
				sum++;
				mx++;
			}
			char x;
			cin>>x;
			sum += (x -'0');	
		}
		cout<<"Case #"<<u<<": "<<mx<<endl;
		u++;
	}
	return 0;
}