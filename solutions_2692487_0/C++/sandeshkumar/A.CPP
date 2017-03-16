#include<iostream.h>
#include<stdio.h>
#include<search.h>
#include<stdlib.h>
#define unsigned long long int ulli
#define FRm(i, m, n)     for( int i = m; i <=n; i++)
#define FRrev(i, n)         for( int i = n; i >= 0; i-- )
#define FRrevm(i,n,m)         for( int i = n; i >= m; i-- )
#define max(a,b) ((a)>(b)?(a):(b))
#define S(a) scanf("%d",&(a))
#define P(a) printf("%d",(a))
int main(){
    int tc,cs=1,mote,n,c,curr,i;
    freopen("","r",stdin);
    freopen("","w",stdout);
    S(tc);
    while(tc--){
	c=0;
	S(mote);
	scanf("%d",&n);
	curr=mote;
	int a[100];
	for(i=0;i<n;i++)
	    scanf("%d",a+i);
	sort(a,a+n);
	for(i=0;i<n;i++){
	    if(curr<=a[i]){
		if(curr+curr-1>a[i])
		    curr+=curr-1+a[i];
		c++;
	    }
	    else
		curr+=a[i];
	}
	printf("Case #%d: %d\n",cs++,c);
    }
    return 0;
}
