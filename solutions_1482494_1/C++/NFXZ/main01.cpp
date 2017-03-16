#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;
#define MAXN 1001
int one[MAXN];
int two[MAXN];

int sortOne[MAXN];
int sortTwo[MAXN];

int ocmp(const void* a ,const void* b)
{
	if(one[*((int *)a)]-one[*((int *)b)]==0)
	return two[*((int *)b)]-two[*((int *)a)];
	return one[*((int *)a)]-one[*((int *)b)];
}

int tcmp(const void* a ,const void* b)
{
	return two[*((int *)a)]-two[*((int *)b)];	
}

int main()
{
	FILE * rfp;
	FILE * wfp;
	
	int n,t,i,j,k,l,h,p,q,f,hit,star,m;
	
	rfp=fopen("B-large.in","r");
	wfp=fopen("B-large.out","w");
	
	fscanf(rfp,"%d",&t);
	
	for(i=1;i<=t;i++){
		fscanf(rfp,"%d",&n);
		fprintf(wfp,"Case #%d: ",i);
		
		for(j=0;j<n;j++){
			fscanf(rfp,"%d %d",&one[j],&two[j]);
			sortOne[j]=j;
			sortTwo[j]=j;
		}
		f=1;hit=0;star=0;
		k=0;l=0;
		
		qsort(sortOne,n,sizeof(int),ocmp);
		qsort(sortTwo,n,sizeof(int),tcmp);
		
		while(star<2*n){
			h=0;
			while(k<n&&star>=two[sortTwo[k]])
			{
				h=1;
				if(one[sortTwo[k]]>=0){
					star+=2;
					hit++;
					two[sortTwo[k]]=-1;
					k++;
				}
				else{
					star+=1;
					hit++;
					two[sortTwo[k]]=-1;
					k++;
				}
			}
			
			if(k>=n)break;
			while(one[sortOne[l]]<0&&l<n)l++;
			if(l>=n)break;
			
			if(star>=one[sortOne[l]]){
				for(p=l,q=-1,m=0;p<n&&star>=one[sortOne[p]];p++){
					if(one[sortOne[p]]>=0&&two[sortOne[p]]>=m){
						q=p;m=two[sortOne[p]];
					}
				}

				if(q>=0){
					star+=1;
					hit++;
					one[sortOne[q]]=-1;
				}
				else{
					if(h==0)break;	
				}
			}
			else{
				if(h==0)break;
			}
		}
		
		if(star>=2*n){
			fprintf(wfp,"%d\n",hit);
		}
		else
		fprintf(wfp,"Too Bad\n");
	}

	fclose(rfp);
	fclose(wfp);
	return 0;
}