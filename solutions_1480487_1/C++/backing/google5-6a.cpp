#include<iostream>
#include<stdio.h>
using namespace std;

int googlea()
{
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int t,n;
	int i,j;
	int data[200];
	double sum;
	double per[200];

	cin>>t;
	for(j=0;j<t;j++){
		cin>>n;
		sum = 0;
		for(i = 0;i<n;i++){
			cin>>data[i];	
			sum += data[i];
		}
		//total points
		
		printf("Case #");
		printf("%d:",(j+1));
		double min = 2 * sum / n;
		double ss = sum * 2;
		int count=0;
		for(i=0;i<n;i++){
			
			if(data[i] >= min){
				per[i] = 0;
				ss -= data[i];
				
			}else{
				count++;
			}
		}
		double min2 = ss / count;
		for(i=0;i<n;i++){
			if(data[i]<min){
				per[i] = (min2 - data[i]) / sum;
			}
			printf(" %.6f",per[i]*100);		
		}
		printf("\n");
	}
	cin>>i;
	return 0;

}