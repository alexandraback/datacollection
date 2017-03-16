#include <stdio.h>
int fyi;
long long int arr[1000010];
int length(long long knum)
{
	int x=0;
		while(knum){
         x++;
         knum=knum/10;
    }
    return x;
}
long long reverse(long long knum)
{
	long long kreverse=0,kr;
	fyi=0;
	while(knum){
         kr=knum%10;
         kreverse=kreverse*10+kr;
         knum=knum/10;fyi++;
    }
    return kreverse;
}
int main()
{
	freopen( "in.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
	long long int n,test,i,sum,rsv,lola,time,j,k,l;
	arr[1]=1;
	for(i=2;i<=1000005;i++)
	{
		rsv=reverse(i);
		if(rsv<i&&arr[rsv]<arr[i-1]&&fyi==length(rsv))
		{
			arr[i]=arr[rsv]+1;
		}
		else
		arr[i]=arr[i-1]+1;
	}
	scanf("%lld",&test);
	for(lola=1;lola<=test;lola++)
	{
		sum=0;
		scanf("%lld",&n);
		printf("Case #%lld: %lld\n",lola,arr[n]);
	}
}			
		
