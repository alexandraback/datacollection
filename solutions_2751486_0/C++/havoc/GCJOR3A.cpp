#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<map>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<set>
#include<stack>
#include<queue>
#include<sstream>
#include<fstream>
#include<functional>
using namespace std;

int main()
{
	ifstream cin("A-small-attempt1.in");
	ofstream cout("A-small.out");
	int T;
	cin>>T;
	for (int i = 0; i < T ; i++)
	{
		string word;
		cin>>word;
		int n;
		cin>>n;
		int L = word.length();
		int solution=0;
		for (int j = 0; j < L ; j++)
		{
			for (int k = j+1; k <= L ; k++)
			{
				string temp = word.substr(j,k-j);
				int countCon=0;
				bool isVowel=true;
				bool bb = false;
				int st =0;
				while(st<temp.size()){
					int loc = temp.find_first_of("aeiou",st);
					if(loc==-1)
					{
						countCon = max (countCon,(int)temp.size() - st);
						break;
					}
					countCon = max(countCon,loc-st);
					st = loc+1;
				}
				if(countCon>=n)
					solution++;
			}
		}
		cout<<"Case #"<<i+1<<": "<<solution<<endl;
	}
	return 0;
}