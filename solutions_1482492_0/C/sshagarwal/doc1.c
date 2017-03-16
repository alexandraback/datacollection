#include<stdio.h>
#include<math.h>
int main()
{
	int t,n,aa,i,j,k;
	float tt,a[10],d,ti[2],x[2],time,l,m;
	scanf("%d",&t);
	for(i=1;i<=t;i++) {
		scanf( "%f %d %d",&d,&n,&aa );
		for( j = 0; j < n; j++ ) 
			scanf( "%f %f",&ti[j],&x[j] );
		for( k = 0; k < aa; k++ )
			scanf( "%f",&a[k] );
		if(n==2 && x[0]<d) {
		l = x[n-1] - x[n-2];
		m = ti[n-1] - ti[n-2];
		time=(m*(d-x[0]))/l;
		}
		else
		time=ti[0];
		
		printf( "Case #%d:\n",i );
		for(k = 0;k < aa; k++) {
			tt = sqrtf ( 2 * d / a[k] );
			
			if( tt > time )
				printf( "%f\n",tt );
			else
				printf( "%f\n",time );
		}
	}
	return 0;
}
