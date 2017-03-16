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
typedef long long ll ;
const int maxn = 101 ;
int n , m , A[maxn] , B[maxn] , AA[maxn] ;
ll a[maxn] , b[maxn] , suma[maxn] , sumb[maxn] , sumc[maxn] , aa[maxn] ;

ll mn(ll a,ll b)    
{   return a < b ? a : b ;   }
ll mx(ll a,ll b)    
{   return a > b ? a : b ;   }

ll work()
{
    ll ans , t ;
    int i , j , k ;
	if( n == 1 )
	{
	    ans = t = 0 ;
	    for( i = 0 ; i < m ; i++) if( B[i] == A[0] ) t += b[i] ;
	    ans = mn(t,a[0]);
	}
	else if( n == 2 )
	{
		if( B[0] == A[0] ) suma[0] = b[0] ;
		else suma[0] = 0 ;
		if( B[0] == A[1] ) sumb[0] = b[0] ;
		else sumb[0] = 0 ;

		for( i = 1 ; i < m ; i++)
	    {
	        suma[i] = suma[i-1] ;
	        if( B[i] == A[0] ) suma[i] += b[i] ;
			sumb[i] = sumb[i-1] ;
			if( B[i] == A[1] ) sumb[i] += b[i] ;
	    }

		ans = mn(a[1],sumb[m-1]);	//all use a[1]
        for( t = ans = 0 , i = 1 ; i < m ; i++)
        {
            ans = mx(ans,mn(suma[i-1],a[0])+mn(sumb[m-1]-sumb[i-1],a[1])) ;
        }
		ans = mx(ans,mn(a[0],suma[m-1]));
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
                t =mn(a[0],suma[i])+mn(a[1],sumb[j]-sumb[i])+mn(a[2],sumc[m-1]-sumc[j]) ;
               ans = mx(ans,t);
            }
			
			//printf("\n-----------%d,%I64d\n",n,ans);
			for( i = 0 ; i < n ; i++) aa[i] = a[i] , AA[i] = A[i] ;
			n = 2 ;
			ans = mx(ans,work());
			
			a[1] = aa[2] ; A[1] = AA[2] ;
			if( A[1] == A[0] )
			{
				a[0] += a[1] ;
				n = 1 ;
			}
			ans = mx(ans,work());
			
			n = 2 ;
			a[0] = aa[1] ; A[0] = AA[1] ;
			ans = mx(ans,work());
			n = 1 ;
			ans = mx(ans,work());
			a[0] = aa[1] ; A[0] = AA[1] ;
			ans = mx(ans,work());
			a[0] = aa[2] ; A[0] = AA[2] ;
			ans = mx(ans,work());
	}
	return ans ;
}

int main()
{
	freopen("n.txt","w",stdout);
    int t , i ;
    cin>>t;
    for(int j = 1 ; j <= t ; j++)
    {
       cin>>n>>m;
        for( i = 0 ; i < n ; i++) 
          cin>>a[i]>>A[i];
        for( i = 0 ; i < m ; i++)
          cin>>b[i]>>B[i];
		printf("Case #%d: ",j);
		cout<<work()<<endl;
    }
}
