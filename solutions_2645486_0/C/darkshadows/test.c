#include<stdio.h>
int mini(int a, int b)
{
    if(a<=b)
	return a;
	else return b;
}
int maxi(int a, int b)
{
    if(a>=b)
	return a;
	else return b;
}
int arr[20],max=-1;
void abc(int index, int e, int n, int E, int r, int sum)
{
    int i;
    if(index==n)
    {
	if(sum>max)
	    max=sum;
    }
    else
    {
	for(i=0; i<=e; i++)
	{
	    abc(index+1,mini(e-i+r,E),n,E,r,sum+(i*arr[index]));
	}
    }
}
int main()
{
    int t,i,p;
    scanf("%d",&t);
    p=t;
    while(t--)
    {
	max=-1;
	int e,r,n;
	scanf("%d%d%d",&e,&r,&n);
	for(i=0; i<n; i++)
	    scanf("%d",&arr[i]);
	abc(0,e,n,e,r,0);
	printf("Case #%d: %d\n",p-t,max);
    }
    return 0;
}
