/*
 * 1A.cpp
 *
 *  Created on: Apr 28, 2012
 *      Author: ezhache
 */
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;


int main() {
	int round=0;
	int A,B;
	float P[100000];
	double P2[100000];
	float temp,result;
	int i,j;
	cin >>round;
	for (i=1;i<=round;i++)
	{
		scanf("%d",&A);
		scanf("%d",&B);
		P2[0]=1;
		temp=0;
		for(j=0;j<A;j++)
		{
			scanf("%f",&P[j]);
			P2[j+1]=P[j]*P2[j];
		}
		result=B+2;



		for(j=0;j<=A;j++)
		{
			temp=0;
			temp+=(B-A+1+2*j)*P2[A-j];
			temp+=(2*B-A+2+2*j)*(1-P2[A-j]);
			if(temp<result)
			{
				result=temp;
			}
		}


		cout<<"Case #"<<i<<": ";
		printf("%f\n",result);
	}

	return 0;
}
