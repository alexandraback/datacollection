//AAA
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long LL;
const int MAX=1000+10;

int N;
double total;



struct NODE
{
	int id;
	double a;
	double ans;
}nod[MAX];
bool cmp(NODE x,NODE y)
{
	return x.a<y.a;
}
bool cmp1(NODE x,NODE y)
{
	return x.id<y.id;
}

double getAv()
{
	double all=total;
	for(int i=N-1;i>=0;i--)
	{
		double av=(all+total)/(i+1);
		if(nod[i].a>=av) {total-=nod[i].a;continue;}
		return av;
	}
	return nod[0].a;
}
int main()
{
	int CN=0;
	int T;scanf("%d",&T);
	
	while(T--)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++) 
		{
			scanf("%lf",&nod[i].a);
			nod[i].id=i;
		}
		sort(nod,nod+N,cmp);
		total=0;
		
		for(int i=0;i<N;i++) total+=nod[i].a;
		double all=total;
		
		double av=getAv();
		for(int i=0;i<N;i++)
		{
			nod[i].ans=(av-nod[i].a)*100/all;
			if(av<=nod[i].a) nod[i].ans=0;
		}
		sort(nod,nod+N,cmp1);
		
		printf("Case #%d:",++CN);
		for(int i=0;i<N;i++) printf(" %.6f",nod[i].ans);
		printf("\n");
	}
	
	//system("pause");
	
	return 0;
}
