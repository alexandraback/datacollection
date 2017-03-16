#include<stdio.h>
#include<stdlib.h>
//#include<math.h>
int a,b;
double ans;

double probs[100000];

void get_probs ()
{
	int l;
	for(l=0;l<a;l++)
		scanf("%lf",&probs [l]);
}

double get_first (int n)
{
	int l;
	double ret=1.0;
	for(l=0;l<a-n;l++)
	{
		ret*=probs[l];
	}
	return ret;
}

int main()
{
	int t,l,l1;
	double tmp,na;
	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%d %d",&a,&b);
		get_probs();
		ans = (double)(b+2);
		for (l1=0;l1 <= a;l1++)
		{
			tmp = get_first (l1);
			na = (2*l1) + (tmp*(b-a+1)) + ((1.0-tmp)*((2*b)-a+2));
			if (na < ans)
				ans=na;
		}
		printf("Case #%d: %.6lf\n",l+1, ans);
	}
}
