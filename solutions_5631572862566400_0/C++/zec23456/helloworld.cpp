#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include<iomanip>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <bitset>
using namespace std;
#define MOD 1000000007
int a[1111];
int b[1111];
vector<int> v[1111];
int main(void){
	ifstream cin("C-small-attempt0.in");
	ofstream cout("output.txt");
	std::ios::sync_with_stdio(false);cin.tie(0);
	int t,T;
	int i,j,n;
	int m;
	int x,y;
	int re;
	cin>>T;
	for(t=1;t<=T;t++)
	{
		cin>>n;
		for(i=1;i<=n;i++)
			v[i].clear();
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			v[a[i]].push_back(i);
			b[i]=0;
		}
		cout<<"Case #"<<t<<": ";
		re=0;
		for(i=1;i<=n;i++)
		{
			if(b[i]==1)
				continue;
			m=n+1;
			x=i;
			while(m--)
			{
				x=a[x];
				if(x==i)
					break;
			}
			//cout<<i<<"www"<<m<<'\n';
			if(m>0)
			{
				x=i;
				m=n+1;
				while(m--)
				{
					re++;
					b[x]=1;
					x=a[x];
					if(x==i)
						break;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(a[i]==j&&a[j]==i)
				{
					if(v[i].size()>1||v[i].size()>1)
						re++;
				}
			}
		}
		cout<<re<<'\n';
	}
	system("pause");
	return 0;
}