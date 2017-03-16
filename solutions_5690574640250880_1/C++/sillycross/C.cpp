#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define SIZE(x) (int((x).size()))
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

#ifndef ONLINE_JUDGE
#define debug(x) { cerr<<#x<<" = "<<(x)<<endl; }
#else
#define debug(x) {}
#endif

const int delx[8]={-1,-1,-1,0,0,1,1,1};
const int dely[8]={-1,0,1,-1,1,-1,0,1};

char ans[100][100];

int check(int n, int m, int s)
{
	rep(k,1,n*m)
		rep(i,1,n)
			rep(j,1,m)
				if (ans[i][j]=='c')
				{
					int flag=1;
					rep(t,0,7)
					{
						int ni=i+delx[t], nj=j+dely[t];
						if (1<=ni && ni<=n && 1<=nj && nj<=m)
							if (ans[ni][nj]=='*') flag=0;
					}
					if (flag) 
						rep(t,0,7)
						{
							int ni=i+delx[t], nj=j+dely[t];
							if (1<=ni && ni<=n && 1<=nj && nj<=m && ans[ni][nj]=='.') ans[ni][nj]='c';
						}
				}
	
	int cn=0;
	rep(i,1,n)
		rep(j,1,m)
		{
			if (ans[i][j]=='.') return 0;
			if (ans[i][j]=='c') cn++;
		}
	return cn==s;
}
		
void lemon()
{
	int n,m,s; scanf("%d%d%d",&n,&m,&s);
	s=n*m-s;
	int swapflag=0;
	if (n>m) { swap(n,m); swapflag=1; }
	
	int found=0;
	if (n==1) 
	{
		rep(i,1,m) if (i==1) ans[1][i]='c'; else if (i<=s) ans[1][i]='.'; else ans[1][i]='*';
		found=1;
	}
	else  if (s==1)
	{
		rep(i,1,n) rep(j,1,m) ans[i][j]='*';
		ans[1][1]='c';
		found=1;
	}
	else  
	{
		rep(k,2,m)
			if (s%k!=1 && s/k+(s%k>0)<=n && s/k>1)
			{
				rep(i,1,n) rep(j,1,m) ans[i][j]='*';
				rep(i,1,s/k) rep(j,1,k) ans[i][j]='.';
				rep(i,1,s%k) ans[s/k+1][i]='.';
				ans[1][1]='c';
				found=1;
				break;
			}
		
		if (!found)
		{
			rep(k,3,m)
				if (s%k==1 && s/k+(s%k>0)<=n && s/k>2)
				{
					rep(i,1,n) rep(j,1,m) ans[i][j]='*';
					rep(i,1,s/k) rep(j,1,k) ans[i][j]='.';
					rep(i,1,s%k+1) ans[s/k+1][i]='.';
					ans[s/k][k]='*';
					ans[1][1]='c';
					found=1;
					break;
				}
		}
	}
	if (!found) 
	{
		printf("Impossible\n");
		return;
	}
	
	//if (!check(n,m,s)) printf("fail!\n");
	//return;

	if (swapflag)
	{
		rep(i,1,m)
		{
			rep(j,1,n) printf("%c",ans[j][i]);
			printf("\n");
		}
	}
	else
	{
		rep(i,1,n)
		{
			rep(j,1,m) printf("%c",ans[i][j]);
			printf("\n");
		}
	}	
}

int main()
{
	ios::sync_with_stdio(true);
	#ifndef ONLINE_JUDGE
		freopen("C.in","r",stdin);
	#endif
	int tcase; scanf("%d",&tcase);
	rep(nowcase,1,tcase) 
	{
		printf("Case #%d:\n",nowcase);
		lemon();
	}
	return 0;
}

