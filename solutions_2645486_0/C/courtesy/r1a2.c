#include<stdio.h>
typedef long long ll;
int a[10005];
int Qsort(int left,int right)
{
	int mid,i,j,tmp;


	i=left;
	j=right;
	mid=a[(left+right)/2];
	do
	{
		while(a[i]<mid)
		i++;
		while(mid<a[j])
		j--;
		if(i<=j)
		{
			tmp=a[i];
			a[i]=a[j];
			a[j]=tmp;
			i++;
			j--;
		}
	}while(i<=j);
	if(left<j)
	Qsort(left,j);
	if(i<right)
	Qsort(i,right);
}
int main()
{
    freopen("C:\\TC\\BIN\\codejam2013\\in.txt","r",stdin);
    freopen("C:\\TC\\BIN\\codejam2013\\out.txt","w",stdout);

    int t,cs,i,j,k,e,r,n,mx;
    ll g,s;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
        scanf("%d %d %d",&e,&r,&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        Qsort(0,n-1);
        g=e*a[n-1];
        if(r>=e)
        {
            for(i=0;i<(n-1);i++)g=g+e*a[i];
        }
        else
        {
            mx=2*r-e;
            if(mx>=0)
            {
                for(i=n-2,j=0;i>j;i--,j++)g=g+e*a[i]+mx*a[j];
                if(i==j)
                g=g+e*a[i];
            }
            else
            {
                for(i=n-2,j=0;i>j;i--,j++)
                {
                    k=r;
                    for(;i>j;j++)
                    {
                        if((k+r)>=e)break;
                        k+=r;
                    }
                    if(j==i)
                    {
                        g=g+k*a[i];i++;
                        break;
                    }
                    else
                    {
                        g=g+e*a[i]+(k+r-e)*a[j];
                    }
                }
                if(i==j)g=g+r*a[i];
            }
        }
        printf("Case #%d: %lld\n",cs,g);
    }
    return 0;
}
