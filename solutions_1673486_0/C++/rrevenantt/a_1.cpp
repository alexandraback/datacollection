#include <stdlib.h>
#include <stdio.h>
#include <set>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
	freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);
	int h=0;
	scanf("%d\n",&h);
	for(int t=0;t<h;t++){
		int a,b;
		scanf("%d %d",&a,&b);
		double *p=new double[a];
		for(int i=0;i<a;i++)
			scanf("%lf",&p[i]);
		double *pr = new double[a+1];
		double temp = 1;
		for(int i=0;i<a;i++)
		{
			pr[i]=temp*(1-p[i]);
			temp*=p[i];
		}
		pr[a]=temp;
		double suml=0;
		double sumr=1;
		double min = b+2;
		for(int k=0;k<=a;k++){
			sumr-=pr[a-k];
			suml+=pr[a-k];
			double aaa =sumr*(2*k+b-a+2+b)+suml*(2*k+b-a+1);
			/*
			for(int j=0;j<=a;j++)
			{
				aaa+=pr[j]*((a-j<=k)?(2*k+b-a+1):(2*k+b-a+2+b));
			}*/
			if(min>aaa) min=aaa;
		}
		printf("Case #%d: %llf\n",t+1,min);
	}
	return 0;
}