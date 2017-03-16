#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define popb pop_back
#define del erase
#define sz size
#define ins insert
#define FOR(a,b,c) for(int a = b; a < c; a++)
#define FORS(a,b,c) for(int a = b; a <= c; a++)
#define FORN(a,b) for(int a = 0; a < b; a++)
#define FORD(a,b,c) for (int a = b; a >= c; a--)
#define RES(a,b) memset(a,b,sizeof(a))
#define LL long long
#define PII pair<int,int>
#define PLL pair<long long,long long>
#define PDD pair<double,double>
#define PCC pair<char,char>
#define PSS pair<string,string>
using namespace std;
int n,s,p,ans,x,T;
int main () {
	scanf("%d",&T);
	for (int j=1;j<=T;j++)	{
		ans=0;
		scanf("%d %d %d",&n,&s,&p);
		for (int i=0;i<n;i++)	{
			scanf("%d",&x);
			if (((x-1)/3)+1>=p && x!=0){
				ans++;}
			else
				if (s>0 && ((x+1)/3)+1>=p && x!=0) {
					ans++;s--;}
				else
					if (p==0) {ans++;}
		}
		printf("Case #%d: %d\n",j,ans);
	}
return 0;}
