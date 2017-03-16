#include<stdio.h>
#include "stdafx.h"
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	FILE *fp=fopen("a-small-attempt1.in","r");
	FILE *fp2=fopen("out.txt","w");
	int data;
	fscanf(fp,"%d",&data);
	for(int i=1;i<=data;i++)
	{
		int ald,pas;
		fscanf(fp,"%d%d",&ald,&pas);
		vector<double>vec;
		for(int j=0;j<ald;j++)
		{
			double zan;
			fscanf(fp,"%lf",&zan);
			vec.push_back(zan);
		}
		double mini=1000000000.0;
		double rui=1.0;
		for(int k=0;k<ald;k++)
		{
			rui*=vec[k];
			mini=min(mini,rui*(pas-k+ald-k-1)+(1.0-rui)*(pas-k+ald-k+pas));
		}
		mini=min(mini,double(2+pas));
		fprintf(fp2,"Case #%d: ",i);
		fprintf(fp2,"%lf\n",mini);
	}
}