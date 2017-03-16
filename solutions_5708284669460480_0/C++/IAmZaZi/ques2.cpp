#include<iostream>
#include<stdio.h>
using namespace std;
string dest;
string chabi;
int maximum;
int total;
int k,l,s;
int arr[10000000]={0};
char per[1000000];
void perm(int i)
{
	if(i>=s)
	{
		total++;
		int same=0;
		for(int kkkk=0; kkkk<(s-l+1); kkkk++)
		{
			int f=1;
			for(int tapas=0;(tapas+kkkk)<(s) && (tapas<l) ;tapas++)
				if(per[tapas+kkkk]!=dest[tapas])
					f=0;
			if(f==1)
				same++;
		}
		arr[total-1]=same;
		if(maximum<same)
			maximum=same;
	}
	else
	{
		for(int point=0; point<k; point++)
		{
			per[i]=chabi[point];
			perm(i+1);
		}
	}
}
void myFunc()
{
	cin>>k>>l>>s;
	cin>>chabi;
	cin>>dest;
	maximum=0;
	total=0;
	perm(0);
	float finalanswer=0;
	for(int i=0;i<total;i++)
		finalanswer+=(maximum-arr[i]);
	finalanswer/=((double)(total));
	printf("%0.7f",finalanswer);
}
int main()
{
	int t;
		cin>>t;
	for(int i=1;i<=t;i++)
	{
		cout<<"Case #"<<i<<": ";
		myFunc();
		cout<<"\n";
	}
}
