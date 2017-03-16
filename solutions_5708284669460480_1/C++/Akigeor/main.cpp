// Template by Akigeor
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define ff first
#define ss second
#define pb push_back
#define PII pair<int,int>
#define rep(i,n) for (i=0;i<(n);i++)
#define fo(i,L,R) for (i=(L);i<=(R);i++)
#define cls(x) memset(x,0,sizeof(x))
#define cin(x) scanf("%d",&x)
#define mINF 0x3f
#define INF 0x3f3f3f3f
#define MOD7 1000000007
#define MOD9 1000000009
#define PI acos(-1.0)
using namespace std;
char key[105],word[105];
int fail[105],K,L,S;
int getX()
{
	int i,j;
	fail[1]=0;
	fo(i,2,L)
	{
		j=fail[i-1];
		while (j>0 && word[j+1-1]!=word[i-1]) j=fail[j];
		if (word[j+1-1]==word[i-1]) j++;
		fail[i]=j;
	}
	return fail[L];
}
int main()
{
	int T,z;
	cin(T);
	fo(z,1,T)
	{
		int i,j,k,l,cnt[26];
		double ans=1.0;
		cin(K); cin(L); cin(S);
		scanf("%s",key);
		scanf("%s",word);
		cls(cnt);
		rep(i,K) cnt[key[i]-'A']++;
		bool flag=1;
		rep(i,L) if (cnt[word[i]-'A']==0) {flag=0; break;}
		if (flag)
		{
			rep(i,L) ans*=1.0*cnt[word[i]-'A']/K;
			ans*=(S-L+1);
			ans=1+(S-L)/(L-getX())-ans;
		}
		else
		{
			ans=0;
		}
		printf("Case #%d: %.10lf\n",z,ans);
	}
}
