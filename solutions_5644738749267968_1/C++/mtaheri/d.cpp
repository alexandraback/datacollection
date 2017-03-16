#include<iostream>
#include<stdio.h>
using namespace std;


int cmp(const void* pa,const void* pb)
{
	double a=*(double*) pa;
	double b=*(double*) pb;
	if(a>b) return 1;
	if(a<b) return -1;
	return 0;
}


int calc(double* arr,double* arr2,int n)
{
	int pj=0;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		while(pj<n && arr[i]>arr2[pj])
		{
			sum++;
			pj++;
		}
		if(pj==n)return sum;
		pj++;
	}
	return sum;
}

int calc2(double* arr,double* arr2,int n)
{
	int sum=0;
	int pj=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]<arr2[pj])continue;
		sum++;
		pj++;
	}
	return sum;
}


void main()
{
	double arr[2000];
	double arr2[2000];
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cout<<"Case #"<<i+1<<": ";
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		for(int i=0;i<n;i++)
			cin>>arr2[i];
		qsort(arr,n,sizeof(double),cmp);
		qsort(arr2,n,sizeof(double),cmp);
		cout<<calc2(arr,arr2,n)<<" ";
		cout<<calc(arr,arr2,n)<<endl;

	}
}