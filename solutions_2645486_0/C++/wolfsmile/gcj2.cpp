#include<iostream>
using namespace std;
int value[100];
int Max = 0;
int e,r,n;
void compute(int step,int E,int v)
{
	if(step == n)
	{
		v = v+value[n-1]*E;
		if(v>Max)
			Max = v;
		return;
	}
	for(int i=0;i<=E;i++)
	{
		int temp;
		temp = E-i+r;
		if(temp > e)
			temp = e;
		compute(step+1,temp,v+i*value[step-1]);
	}
	return;
}
int main()
{
	FILE *in;
	FILE *out;
	in = fopen("in.txt","r");
	out = fopen("out.txt","w");
	int T;
	int Case = 1;
	fscanf(in,"%d",&T);
	while(Case <=T)
	{
		fscanf(in,"%d%d%d",&e,&r,&n);
		for(int i=0;i<n;i++)
		{
			fscanf(in,"%d",&value[i]);
		}
		compute(1,e,0);
		fprintf(out,"Case #%d: %d\n",Case,Max);
		Case ++;
	}	
	return 0;
}