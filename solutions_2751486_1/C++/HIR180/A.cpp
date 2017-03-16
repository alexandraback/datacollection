//Waai GCJR1C Akari GCJR1C Daisuki
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
bool flag(char s)
{
	if(s=='a') return true;
	if(s=='i') return true;
	if(s=='u') return true;
	if(s=='e') return true;
	if(s=='o') return true;
	return false;
}
int main(){
	int t;
	scanf("%d",&t);
	for(int q=1;q<=t;q++)
	{
		string str;
		int L;
		cin >> str >> L;
		int st;
		int len=0;
		bool con=false;
		vector<P>beg;
		vector<int>za;
		for(int i=0;i<str.size();i++)
		{
			if(con)
			{
				if(flag(str[i]))
				{
					if(len>=L)
					{
						beg.pb(mp(st,len));
						za.pb(st);
					}
					len=0;
					con=false;
				}
				else
				{
					len++;
				}
			}
			else
			{
				if(!flag(str[i]))
				{
					st=i;
					len++;
					con=true;
				}
			}
		}
		if(len>=L)
		{
			beg.pb(mp(st,len));
			za.pb(st);
		}
		long long ret=0;
		if(!za.size())
		{
			goto rn;
		}
		for(int i=0;i<str.size();i++)
		{
			int p=lower_bound(za.begin(),za.end(),i)-za.begin();
			int po=beg[p].first;
			po+=L-1;
			if(p==za.size())
			{
				po=INF;
			}
			if(p)
			{
				p--;
				while(p>=0 && za[p]+beg[p].second-i>=L)
				{
					po=i+L-1;
					p--;
				}
			}
			ret+=(long long)max((int)str.size()-po,0);
		}
		rn:;
		printf("Case #%d: %lld\n",q,ret);
	}
}