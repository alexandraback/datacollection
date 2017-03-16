#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define MAXN 100010

double p[MAXN],p1,p2,p3,e1,e2,e3;
int T,t,A,B;

int main()
{
	cin>>T;
	while(T--)
	{
		e2=1e30;
		cin>>A>>B;
		double tmp=1;
		for(int i=1;i<=A;i++) 
		{
			scanf("%lf",p+i);
			tmp*=p[i];
			e2=min(e2,B-A+2*(A-i)+1+(1-tmp)*(B+1));
		}
		e1=B-A+1+(1-tmp)*(B+1);
		e3=B+2;
		cout<<"Case #"<<++t<<": ";
		printf("%.12lf\n",min(e1,min(e2,e3)));
	}
	return 0;
}
