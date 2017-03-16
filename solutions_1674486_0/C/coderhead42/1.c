/************************************************************************************************************

	FILE NAME : 1.c
	
	CREATION DATE : Sun 06 May 2012 02:37:00 PM IST

	LAST MODIFIED : Sun 06 May 2012 03:16:01 PM IST
			
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
#define i1s(d,n) ({int i=0;for(i=0;i<n;i++){scanf("%d",&d[i])};d;}) 
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
int G[1000][1000];

int main(){
	int test;is(test);
	int i;
	for(i=1;i<=test;i++){
		int n;is(n);
		int j,k;
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				G[j][k]=0;
			}
		}
		for(j=0;j<n;j++){
			int s,t;is(s);
			for(k=0;k<s;k++){
				is(t);
				G[j][t-1]=1;
			}
		}
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				if(j==k)
					continue;
				int A[n];
				int F[n];
				int l;
				for(l=0;l<n;l++){
					F[l]=0;
				}
				int start=0;
				int end=0;
				A[end++]=k;
				while(start<end){
					for(l=0;l<n;l++){
						if(G[l][A[start]]==1){
							if(F[l]==1){
								goto label;
							}
							if(F[l]==0){
								A[end++]=l;
								F[l]=1;
							}
						}
					}
					start++;
				}
			}
		}
		goto label1;
		
label : 	if(i!=test)
			printf("Case #%d: Yes\n",i);
		else
			printf("Case #%d: Yes",i);
		continue;

label1 :	if(i!=test)
			printf("Case #%d: No\n",i);
		else
			printf("Case #%d: No",i);
		continue;	
	}
return 0;
}
