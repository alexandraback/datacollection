#include <stdio.h>
#include <iostream>
#include <set>
#include <math.h>
using namespace std;

int main()
{

	FILE* in;
	FILE* out;
	
	int t;
	double n;
	double s[300],sum,avg,m[300],ts;
	int i,j,k,l,u;
	
	in=fopen("A-small-attempt2.in","r");
	out=fopen("A-small-attempt2.out","w");
	
	fscanf(in,"%d",&t);
	
	for(i=1;i<=t;i++)
	{
		fprintf(out,"Case #%d:",i);
		fscanf(in,"%lf",&n);
		sum=0;
		for(j=0;j<n;j++){
			fscanf(in,"%lf",&s[j]);
			sum+=s[j];
			m[j]=-1;
		}
		
		ts=sum;k=n;l=n+1;
		while(k!=l){
			l=k;
			avg=(sum+ts)/k;
			for(j=0;j<n;j++)if(m[j]<0){
				if(avg-s[j]<=0){
					m[j]=0;
					ts=ts-s[j];
					k--;
				}
			}
		}
		
		if(k!=0)
		for(j=0;j<n;j++){
			if(	m[j]<0){
				m[j]=(avg-s[j])*100/sum;
			}
		}
		
		for(j=0;j<n;j++){
			fprintf(out," %lf",m[j]);
		}
		fprintf(out," \n");
	}
	
	fclose(in);
	fclose(out);
	return 0;
}

