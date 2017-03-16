#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <sstream>
using namespace std ;
string f[1<<20] ;
int key[30] ;
int g[30][30] ;
int n , k ;
int ini ;
int sum[30] ;
int check(int state,int k)
{
	int s[30] ;
	memset(s,0,sizeof(s)) ;
	for (int i=1;i<=20;i++)
		s[i] += sum[i] ;
	for (int i=0;i<n;i++)
	{
		if (((1<<i)&state)>0)
		{
			for (int j=1;j<=g[i][0];j++)
				s[g[i][j]]++ ;
			s[key[i]]-- ;
		}
	}
	if (s[k]>0) return true ;else return false ;
}
void output()
{
	cout<<k<<" "<<n<<endl ;
	for (int i=1;i<=20;i++)
		cout<<sum[i]<<" " ;
	cout<<endl ;
	for (int i=0;i<n;i++)
	{
		cout<<i<<" "<<key[i]<<" "<<g[i][0]<<" " ;
		for (int j=1;j<=g[i][0];j++)
			cout<<g[i][j]<<" " ;
		cout<<endl ;
	}
}
int main()
{
	int cs ;
	cin>>cs ;
	for (int t=1;t<=cs;t++)
	{
		
		cin>>k>>n ;
	//	cout<<n<<endl ;
		ini = 0 ;
		memset(sum,0,sizeof(sum)) ;
		memset(g,0,sizeof(g)) ;
		for (int i=0;i<k;i++)
		{
			int x ;
			cin>>x ;
			sum[x]++ ;
		}
		for (int i=0;i<n;i++)
		{
			cin>>key[i] ;
			cin>>g[i][0] ;
			for (int j=1;j<=g[i][0];j++)
				cin>>g[i][j] ;
		}
	//	if (t!=4) continue ;
	//	output() ;
		for (int i=0;i<(1<<n);i++)
			f[i] = "#" ;
		f[0] = "" ;
		for (int i=0;i<(1<<n);i++)
		{
			if (f[i]!="#")
			{
				for (int j=0;j<n;j++)
				{
					if (((1<<j)&i)==0)
					{
						if (check(i,key[j]))
						{
							int ns = i + (1<<j) ;
							if (f[ns]=="#")
							{
								f[ns] = f[i]+ char('a'+j) ;
							}
							else
							{
								f[ns] = min(f[ns],f[i]+char('a'+j)) ;
							}
						}
					}
				}
			}
		}
		cout<<"Case #"<<t<<": " ;
		if (f[(1<<n)-1]=="#")
		{
			cout<<"IMPOSSIBLE"<<endl ;
			continue ;
		}
		for (int i=0;i<n-1;i++)
		{
			printf("%d ",f[(1<<n)-1][i]-'a'+1) ;
		}
		printf("%d\n",f[(1<<n)-1][n-1]-'a'+1) ;
	}
}