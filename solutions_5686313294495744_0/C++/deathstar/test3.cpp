#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <stdlib.h>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
 
using namespace std;
 
#define fi first
#define sc second
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
#define pb push_back
#define mp make_pair
#define ll long long
#define dl double
#define ison(a,b) (a&(1<<b))
#define bitcnt __builtin_popcount
#define MOD 1000000007 
#define INF 1000000000
 
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> wadj;


int main(int argc, char const *argv[])
{
//freopen("inp.txt","r",stdin);
  //freopen("out.txt","w",stdout);
	int t;
	cin>>t;
	for(int x=1;x<=t;x++)
	{
		printf("Case #%d: ",x);
		int n;
		cin>>n;
		vector<pair<string,string> > v;
		vector<pair<int,pair<string,string> > >v1;
		for(int i=0;i<n;i++)
		{
			string a,b;
			cin>>a>>b;
			v.pb(mp(a,b));
		}
		int mx=0;
		for(int i=1;i<(1<<n);i++)
		{
			v1.clear();
			for(int j=0;j<n;j++)
			{
				if(i&(1<<j))
					v1.pb(mp(j,v[j]));
			}
			int cnt=0;
			for(int j=0;j<v1.size();j++)
			{
				string s=v1[j].sf,s1=v1[j].ss;
				bool f1=0,f2=0;
				for(int k=0;k<v.size();k++)
				{
					if(i&(1<<k))
						continue;
					if(v[k].fi==s)
					{
						f1=true;
						break;
					}
				}
				for(int k=0;k<v.size();k++)
				{
					if(i&(1<<k))
						continue;
					if(v[k].sc==s1)
					{
						f2=true;
						break;
					}
				}
				if(f1&&f2)
					cnt++;
			}
			mx=max(mx,cnt);
		}
		printf("%d\n",mx);
	}
 
    return 0;
}
 