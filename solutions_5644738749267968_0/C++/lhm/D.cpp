#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int T;
double number1[100000],number2[10000];
bool vis[100000];
int n;

int main()
{
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small-attempt0.out","w",stdout);
	scanf("%d",&T);
	for ( int cas = 1; cas <= T; ++cas ){
		scanf("%d",&n);
		for ( int i = 1; i <= n; ++i ) scanf("%lf",&number1[i]);
		for ( int i = 1; i <= n; ++i ) scanf("%lf",&number2[i]);
		sort(number1+1,number1+1+n);
		sort(number2+1,number2+1+n);
		memset(vis,0,sizeof(vis));
		int res1 = 0, res2 = 0;
		bool flag = 0;
		/*
		for ( int i = 1; i <= n; ++i )
			  cout << number1[i] << " ";
			cout << endl;
		for ( int i = 1; i <= n; ++i )
			 cout << number2[i] << " ";
			cout << endl;
		*/
		for ( int i = 1; i <= n; ++i )
		{
			flag = 0;
			for ( int j = 1; j <= n; ++j )
				if ( number1[i] > number2[j] && vis[j] == 0 )
				{
					vis[j] = 1; flag = 1;break;
				}
			if ( flag == 1 ) ++ res1;
		}

		memset(vis,0,sizeof(vis));
		for ( int i = 1; i <= n; ++i )
		{
			flag = 0;
			for ( int j = 1; j <= n; ++j )
				if ( number2[j] > number1[i] && vis[j] == 0 )
				{
					vis[j] = 1; flag = 1; break;
				}
			if ( flag == 0 ) ++res2;
		}
		printf("Case #%d: %d %d\n",cas,res1,res2);
	}
	return 0;
}