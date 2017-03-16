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
const int INF = 1000000000 ;
int n , m ;
int a[200][200] ;
bool check(int x,int y)
{
	int hx = 0 ;
	for (int i=0;i<m;i++)
		hx = max(a[x][i],hx) ;
	int hy = 0 ;
	for (int i=0;i<n;i++)
		hy = max(a[i][y],hy) ;
	if (a[x][y]<hy&&a[x][y]<hx) return false ;
	return true ;
}
int main()
{
	int cs ;
	cin>>cs ;
	for (int t=1;t<=cs;t++)
	{
		cin>>n>>m ;
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				cin>>a[i][j] ;
		bool flag = true ;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				if (!check(i,j))
				{
					flag = false ; 
					break ;
				}
			}
			if (!flag) break ;
		}
		string res = "" ;
		if (flag) res = "YES" ;else res="NO" ;
		printf("Case #%d: ",t) ;
		cout<<res<<endl ;
	}
}