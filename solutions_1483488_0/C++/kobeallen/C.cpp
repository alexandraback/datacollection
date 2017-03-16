#include<iostream>
#include<cmath>
using namespace std;
const int N=2000010;

bool hash[N];
int sum[101];

int Cal(int num, int A, int B)
{
	int i=num;
	int length=0, result=1;
	while(i>0)
	{
		length++;
		i/=10;
	}
	int mov;
	for(mov=1;mov<length;mov++)
	{
		int mod=pow(10, mov);
		int val=num/mod+(num%mod)*pow(10,length-mov);
		if(val>=A&&val<=B&&hash[val]==false)
		{
			result++;
			hash[val]=true;
		}
	}
	return sum[result];
}

int main()
{
	freopen("C-small.in","r",stdin);
	freopen("output.txt","w+",stdout);
	int A,B;
	int c, cas;
	int i;
	int ans;	
	sum[1]=0;
	for(i=2;i<=100;i++)
		sum[i]=sum[i-1]+i-1;
	scanf("%d",&cas);
	for(c=1;c<=cas;c++)
	{
		ans=0;
		memset(hash,0,sizeof(hash));
		scanf("%d%d",&A,&B);
		for(i=A;i<=B;i++)
		{
			if(hash[i]==false)
			{
				hash[i]=true;
				ans+=Cal(i, A, B);
			}
		}
		printf("Case #%d: %d\n", c, ans);
	}
	return 0;
}