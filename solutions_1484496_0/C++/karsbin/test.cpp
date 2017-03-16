#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

////// soj 3116

const int maxn = 20*100000+10 ;
int n , vis[maxn] , a[20] ;

inline bool get(int &t)
{
	bool flag = 0 ;
	char c;
	while(!isdigit(c = getchar())&&c!='-') if( c == -1 ) break ;
	if( c == -1 ) return 0 ;
	if(c=='-') flag = 1 , t = 0 ;
	else t = c ^ 48;
	while(isdigit(c = getchar()))	t = (t << 1) + (t << 3) + (c ^ 48) ;
	if(flag) t = -t ;
	return 1 ;
}

inline int get_min(int a,int b) {   return a < b ? a : b ;  }

inline void solve()
{
	int i , j , k ;
	for( i = 0 ; i < maxn ; i++) vis[i] = -1 ;
	for( i = 0 ; i < (1<<n) ; i++)
	{
		for( j = k = 0 ; j < n ; j++) if( i & (1<<j) ) k += a[j] ;
		if( vis[k] != -1 ) break ;
		vis[k] = i ;
	}
	if( i == (1<<n) ) 
	{
		puts("Impossible");
		return ;
	}
	for( j = 0 ; j < n ; j++) if ( vis[k] & (1<<j) ) printf("%d ",a[j]);
	puts("");
	for( j = 0 ; j < n ; j++) if ( i & (1<<j) ) printf("%d ",a[j]);
	puts("");
}

int main()
{
	int i , j , t ;
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	get(t);
    for( i = 1 ; i <= t ; i++)
    {
		get(n);
		for( j = 0 ; j < n ; j++) get(a[j]);
		printf("Case #%d:\n",i);
		solve();
    }
}
