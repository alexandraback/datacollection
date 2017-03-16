#include<cstdio>
#include<iostream>
using namespace std; 
int main() 
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
    int test,j;
    scanf("%d",&test);
    j=1;
    double C,F,X;
    double total,rate;
    while (test--)
	{
	    total=0.0;
	    rate=2.0;
	    cin>>C>>F>>X;
	    while ((X/rate) > ((C/rate)+(X/(rate+F))))
		{
		    total += (C/rate);
		    rate+=F;
	    }
	    total += (X/(rate));
	    printf("Case #%d: %0.7lf\n",j,total);
	    j++;
    }
    return 0;
}
