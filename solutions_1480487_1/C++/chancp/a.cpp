
//Problem A. 

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <cmath>

using namespace std;

int n;
int s[200];
double minp[200];
int v[200];

void compute(){
	int i,j,k;
	int sum=0;
	double avg=0;
	for (i=0;i<n;i++) {
		minp[i]=0;
		v[i]=1;
		//printf("%d ",s[i]);

	}
	//printf("sum...%d\n",sum);
	for (i=0;i<n;i++) {
		sum+=s[i];
		//printf("%d %d sum...%d\n",i,s[i],sum);
	}
	avg=sum*2.0/n;
	//printf("\n");
	//printf("sum: %d, avg: %f\n",sum, avg);
	j=0;
	k=0;
	for (i=0;i<n;i++)
		if (s[i]>=avg) {
			j++;
			v[i]=0;
		}
		else k+=s[i];

	avg=(k+sum)*1.0/(n-j);
	//printf("sum: %d, k: %d, j: %d, avg: %f\n",sum, k,j,avg);
	for (i=0;i<n;i++){
		if (v[i]){
			minp[i]=(avg-s[i])*100.0/sum;
		}
	}
	
}

int main(){
	int t;
	int i,j,k;
	
	cin>>t;
	for (i=0;i<t;i++){
		cin>>n;
		for (j=0;j<n;j++) cin>>s[j];

			
		compute();
		cout<<"Case #"<<(i+1)<<":";
		//for (j=0;j<n;j++) cout<<rpi[j]<<endl;
		//cout<<compute();
		for (j=0;j<n;j++) printf(" %.7f",minp[j]);
		cout<<endl;
		//for (j=0;j<n;j++) printf("%f %f %f %.10f\n",wp[j],owp[j],oowp[j],rpi[j]);
	}
}
