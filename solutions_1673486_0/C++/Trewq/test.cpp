#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	int a,b;
	double pcor[101]={1},exp,minexp;
	cin>>t;
	for(int cs=1;cs<=t;cs++)
	{
		cin>>a>>b;
		minexp=b+2;
		for(int i=1;i<=a;i++)
		{
			cin>>pcor[i];
			pcor[i]*=pcor[i-1];
			exp=pcor[i]*(a+b-2*i+1)+(1-pcor[i])*(a+2*b-2*i+2);
			if(exp<minexp)minexp=exp;
		}
		printf("Case #%d: %.6f\n",cs,minexp);
	}
	return 0;
}