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

const int maxn = 201 ;
const double precision = 1e-9 ;
int n , a[maxn] ;
double x[maxn] , suma , sum1 , ans ;

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

int main()
{
    //freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
    int t , i , j , k ;
    get(t);  
    for( i = 1 ; i <= t ; i++)
    {
       get(n);
       for(j=suma=0;j<n;j++)
       {
         get(a[j]);
         x[j]=1.*a[j];
         suma+=1.*a[j];
       }
       sort(x,x+n);
       x[n]=1000000;
       for(ans=sum1=j=0;j<n;j++)
       {
		   if((x[j+1]-x[j])*(j+1)+sum1>=suma)
		   {
			   ans=x[j]+(suma-sum1)/(j+1);
			   break;
		   }
		   else		sum1+=(x[j+1]-x[j])*(j+1);
       }
       printf("Case #%d: ",i);
       for( j = 0 ; j < n-1 ; j++)
       {
		   if( a[j] >= ans )	printf("0 ");
		   else		printf("%.6lf ",100*(ans-a[j])/suma);
       }
	   if( a[j] >= ans )	printf("0\n");
		else		printf("%.6lf\n",100*(ans-a[j])/suma);
    }
}

