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
char s[40005];
char op(char a,char b)
{
	bool f=0;
	if (a!='1' && a!='i' && a!='j' && a!='k') f=!f,a-=5;
	if (b!='1' && b!='i' && b!='j' && b!='k') f=!f,b-=5;
	char c;
	if (a=='1' && b=='1') c='1';
	if (a=='1' && b=='i') c='i';
	if (a=='1' && b=='j') c='j';
	if (a=='1' && b=='k') c='k';
	if (a=='i' && b=='1') c='i';
	if (a=='i' && b=='i') c='1',f=!f;
	if (a=='i' && b=='j') c='k';
	if (a=='i' && b=='k') c='j',f=!f;
	if (a=='j' && b=='1') c='j';
	if (a=='j' && b=='i') c='k',f=!f;
	if (a=='j' && b=='j') c='1',f=!f;
	if (a=='j' && b=='k') c='i';
	if (a=='k' && b=='1') c='k';
	if (a=='k' && b=='i') c='j';
	if (a=='k' && b=='j') c='i',f=!f;
	if (a=='k' && b=='k') c='1',f=!f;
	if (f) c+=5;
	return c;
}
char mp(char x,int n)
{
	char s='1';
	int i;
	rep(i,n) s=op(s,x);
	return s;
}
int main()
{
	int TT,z;
	cin(TT);
	fo(z,1,TT)
	{
		int L,X,i,j,k,l;
		cin(L); cin(X);
		scanf("%s",s);
		char P='1',ss;
		rep(i,L) P=op(P,s[i]);
		ss=mp(P,X%4);
		if (ss!='1'+5) {printf("Case #%d: NO\n",z); continue;}
		char s1='1';
		rep(j,4)
		{
			rep(i,L)
			{
				s1=op(s1,s[i]);
				if (s1=='i') break;
			}
			if (s1=='i') break;
		}
		char s2='1';
		rep(l,4)
		{
			for (k=L-1;k>=0;k--)
			{
				s2=op(s[k],s2);
				if (s2=='k') break;
			}
			if (s2=='k') break;
		}
		if (s1=='i' && s2=='k' && j*L+i<(X-l-1)*L+k)
		{
			printf("Case #%d: YES\n",z);
		}
		else
		{
			printf("Case #%d: NO\n",z);
		}
	}
}
