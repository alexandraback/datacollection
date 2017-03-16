/************************************************************************************************************

	FILE NAME : 1.c
	
	CREATION DATE : Sat 05 May 2012 09:35:24 PM IST

	LAST MODIFIED : Sat 05 May 2012 11:35:17 PM IST
			
*************************************************************************************************************/


#include<assert.h>
#include<complex.h>
#include<ctype.h>
#include<errno.h>
#include<fenv.h>
#include<float.h>
#include<limits.h>
#include<locale.h>
#include<math.h>
#include<signal.h>
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<wchar.h>
#include<wctype.h>



#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)>a:b
#define cs(c) ({scanf("%c",&c);c;})
#define is(d) ({scanf("%d",&d);d;})
#define ss(c) ({scanf("%s",c);c;})
#define i1s(d,n) ({int i=0;for(i=0;i<n;i++){scanf("%d",&d[i]);};d;}) 
#define i2s(d,m,n) ({int i,j;for(i=0;i<n;i++){for(j=0;j<n;j++){scanf("%d",&d[i][j]);}};d;})
#define swap(a,b) ({*a=*a+*b-(*b=*a)})
#define cp(a) ({printf("%c",a);})
#define ip(a) ({printf("%d",a);})
#define sp(a) ({printf("%s",a);})
#define i1p(a,n) ({int i;for(i=0;i<n;i++){printf("%d%s",a[i],i==n-1?"":" ");}})
#define i2p(a,m,n) ({int i,j;for(j=0;j<m;j++){for(i=0;i<n;i++){printf("%d%s",a[i],i==n-1?"":" ");}printf("\n");};})



int compare(const void *a,const void *b)
	{ return *((int*)a)-*((int*)b); }


int compare1(const void *a,const void *b)
	{ return *((int*)b)-*((int*)a); }




/****************************************************************************************************************************/

int main(){
	int test,j;is(test);
	for(j=1;j<=test;j++){
	int n;is(n);
	int A[n];float B[n];i1s(A,n);
	int i,k;
	float s=0;float s1=0;
	for(i=0;i<n;i++){
		s+=A[i];
	}
	float w=s/n;
	for(i=0;i<n;i++){
		s1+=(A[i]+w);
	}
	s1=s1/n;
	printf("Case #%d: ",j);
	int fl=0,cnt=0;
	for(k=0;k<n;k++){
		B[k]=((s1-A[k])/s)*100;
		if(B[k]<0.0){
			fl=1;
			cnt++;
			B[k]=0.0;
		}
	}
	if(fl==1){
		float w=s/(n-cnt);
		int s2=0;
		for(i=0;i<n;i++){
			if(B[i]==0.0)
				continue;
			s2+=A[i];
		}
		s1=(s+s2)/(n-cnt);
		for(i=0;i<n;i++){
			if(B[i]==0.0)
				continue;
			else
				B[i]=((s1-A[i])/s)*100;
		}
	}
	for(k=0;k<n;k++){
		if(k!=n-1)
			printf("%f ",B[k]);
		else
			printf("%f\n",B[k]);
		}
	}
return 0;
}
