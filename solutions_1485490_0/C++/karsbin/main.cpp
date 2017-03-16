#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <set>
#include <queue>

using namespace std;

typedef __int64 ll ;
const int maxn = 101 ;
int n , m , A[maxn] , B[maxn] , AA[maxn] ;
ll a[maxn] , b[maxn] , suma[maxn] , sumb[maxn] , sumc[maxn] , aa[maxn] ;

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

inline ll get_min(ll a,ll b)    {   return a < b ? a : b ;   }
inline ll get_max(ll a,ll b)    {   return a > b ? a : b ;   }

inline ll solve()
{
    ll ans , t ;
    int i , j , k ;
	if( n == 1 )
	{
	    ans = t = 0 ;
	    for( i = 0 ; i < m ; i++) if( B[i] == A[0] ) t += b[i] ;
	    ans = get_min(t,a[0]);
	}
	else if( n == 2 )
	{
	    if( B[0] == A[0] ) suma[0] = b[0] ;
	    else suma[0] = 0 ;
	    for( i = 1 ; i < m ; i++)
	    {
	        suma[i] = suma[i-1] ;
	        if( B[i] == A[0] ) sumb[i] += b[i] ;
	    }
	    if( B[0] == A[1] ) sumb[0] = b[0] ;
	    else sumb[0] = 0 ;
	    for( i = 1 ; i < m ; i++)
	    {
	        sumb[i] = sumb[i-1] ;
	        if( B[i] == A[1] ) sumb[i] += b[i] ;
	    }
	    ans = get_min(a[1],sumb[m-1]);
        for( t = ans = 0 , i = 1 ; i < m ; i++)
        {
            ans = get_max(ans,get_min(suma[i-1],a[0])+get_min(sumb[m-1]-sumb[i-1],a[1])) ;
        }
	}
	else
	{
	    if( B[0] == A[0] ) suma[0] = b[0] ;
	    else suma[0] = 0 ;
		if( B[0] == A[1] ) sumb[0] = b[0] ;
	    else sumb[0] = 0 ;
		if( B[0] == A[2] ) sumc[0] = b[0] ;
	    else sumc[0] = 0 ;
		for( i = 1 ; i < m ; i++)
	    {
	        suma[i] = suma[i-1] ;
			sumb[i] = sumb[i-1] ;
			sumc[i] = sumc[i-1] ;
	        if( B[i] == A[0] ) suma[i] += b[i] ;
			if( B[i] == A[1] ) sumb[i] += b[i] ;
			if( B[i] == A[2] ) sumc[i] += b[i] ;
	    }

	    for( i = ans = 0 ; i < m ; i++)
            for( j = i+1 ; j < m ; j++)
			{
                t = get_min(a[0],suma[i])+get_min(a[1],sumb[j]-sumb[i])+get_min(a[2],sumc[m-1]-sumc[j]) ;
                ans = get_max(ans,t);
            }

		//printf("\n-----------%d,%I64d\n",n,ans);
        for( i = 0 ; i < n ; i++) aa[i] = a[i] , AA[i] = A[i] ;
        n = 2 ;
        ans = get_max(ans,solve());

        a[1] = aa[2] ; A[1] = AA[2] ;
        if( A[1] == A[0] )
        {
            a[0] += a[1] ;
            n = 1 ;
        }
        ans = get_max(ans,solve());

        n = 2 ;
        a[0] = aa[1] ; A[0] = AA[1] ;
        ans = get_max(ans,solve());
        n = 1 ;
        ans = get_max(ans,solve());
        a[0] = aa[1] ; A[0] = AA[1] ;
        ans = get_max(ans,solve());
        a[0] = aa[2] ; A[0] = AA[2] ;
        ans = get_max(ans,solve());
	}
	/*puts("-----------");
	for( i = 0 ; i < n ; i++) printf("%I64d,%d ",a[i],A[i]);
	puts("");
	printf("%d,%I64d\n",n,ans);
	puts("-----------");*/
	return ans ;
}

int main()
{
    //freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
    int t , i , j , k ;
    get(t);
    for( j = 1 ; j <= t ; j++)
    {
        get(n); get(m);
        for( i = 0 ; i < n ; i++) scanf("%I64d%d",&a[i],&A[i]);
        for( i = 0 ; i < m ; i++) scanf("%I64d%d",&b[i],&B[i]);
		printf("Case #%d: ",j);
		printf("%I64d\n",solve());
    }
}

