//============================================================================
// Name        : google2012-1B1.cpp
// Author      : ezhache
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

void sort(int a[], int num)
{
	int tmp;
	for (int i=0;i<num;i++)
	{
		for(int j=i+1;j<num;j++)
		{
			if(a[i]<a[j])
			{
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
};

int main() {
	int round=0;
	int N,s[200];
	int tmp[200],tmpN;
	double sum,sum2,avg;
	int i,j;
	cin >>round;
	for (i=1;i<=round;i++)
	{
		scanf("%d",&N);
		sum=0;
		avg=0;
		for(j=0;j<N;j++)
		{
			scanf("%d",&s[j]);
			tmp[j]=s[j];
			sum+=s[j];
		}
		avg=(sum*2)/N;
		sum2=sum;
		sort(tmp,N);
		tmpN=N;
		for(j=0;j<N;j++)
		{
			if(s[j]>=avg)
			{
				sum2-=s[j];
				avg=(sum2+sum)/(--tmpN);
			}
		}
		cout<<"Case #"<<i<<": ";
		for(j=0;j<N;j++)
		{
			if(s[j]>=avg)
			{
				printf("%f ",0.0);
			}
			else
			{
				printf("%f ",(avg-s[j])/sum*100);
			}
		}
		cout<<endl;
	}

	return 0;
}
