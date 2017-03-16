#include<stdio.h>
#include<algorithm>
long long int a[100010];
using namespace std;

long long int dpartition(long long int p,long long int r)
	{
		long long int pivot,temp,i,j;
		pivot=a[r];	//choosing the last element as pivot always.
		i=p-1;
		for(j=p;j<=r;j++)
		{
			if(a[j]<=pivot)
			{
				i++;
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		/*temp=a[i+1];
		a[i+1]=a[r];
		a[r]=temp;*/

		return i;
	}

	void dquicksort(long long int p,long long int r)//Deterministic quicksort without tail recusion
	{
		long long int q;
		if(p<r)
		{
			q=dpartition(p,r);
			dquicksort(p,q-1);
			dquicksort(q+1,r);
		}
	}
int main()
{
    long long int n,k,i,j,t,temp;
    scanf("%lld",&n);
    scanf("%lld",&k);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    dquicksort(0,n-1);
    long long int minv;
    for(i=0;i<=n-1-k;i++)
    {
        if(i==0){minv=a[i+k-1]-a[i];continue;}
        if(a[i+k-1]-a[i]<minv){minv=a[i+k-1]-a[i];}
    }
    //printf("minv=%d\n",minv);
    for(i=0;i<=n-1-k;i++)
    {
        if(a[i+k-1]-a[i]==minv){temp=i;}
    }
    //printf("temp=%d\n",temp);

    /*for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }*/

    /*long long int cnt=0;
    if(k==1){printf("%lld\n",a[temp]);return 0;}

    for(i=temp;i<=temp+k-2;i++)
    {
        for(j=i+1;j<=temp+k-1;j++)
        {
            cnt=cnt+a[j]-a[i];
        }
    }
    printf("%lld\n",cnt);*/


    return 0;
}
