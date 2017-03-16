#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	freopen("D-large.in","r",stdin);
	freopen("D-large.out","w",stdout);
    int test,n,i,j,m,k,cnt;
    scanf("%d",&test);
    cnt=1;
    while(test--) 
	{
	    scanf("%d",&n);
	    double a[n],b[n];
	    for(i=0;i<n;i++)
	    scanf("%lf",&a[i]);
	    for(i=0;i<n;i++)
	    scanf("%lf",&b[i]);
	    sort(a,a+n);
	    sort(b,b+n);
	    i=j=0;
	    m=k=0;
	    for(;i<n && j<n;)
	    {
		    if(a[i]<b[j])
		    {
			    i++;
			    j++;
			    m++;
		    }
		    else
		     j++;
	    }
	    i=j=0;
	    for(;i<n && j<n;)
	    {
		    if(a[i]>b[j])
		    {
			    i++;
			    j++;
			    k++;
		    }
		    else
		      i++;
	    }
	    printf("Case #%d: %d %d\n",cnt,k,n-m);
	    cnt++;
    }
    return 0;
}
