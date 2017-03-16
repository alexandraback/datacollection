#include<stdio.h>
#include<queue>

using namespace std;

long long step[1100000];


long long reverse(long long n)
{
	long long rev = 0;
	while(n>0)
	{
		int mod = n%10;
		n/=10;
		rev = rev * 10 + mod;
	}
	return rev;
}

void counter()
{
	for(long long i=0;i<=1000000;i++)
		step[i]=-1;
	step[0]=0;
	step[1]=1;
	queue<long long> q;
	q.push(1);
	while(!q.empty())
	{
		long long node = q.front();
		q.pop();
		long long n1 = node + 1;
		if(step[n1]==-1)
		{
			step[n1] = step[node]+1;
			if(n1<=1000000)
				q.push(n1);
		}
		else
		{
			if(step[node]+1<step[n1])
			{
				step[n1] = step[node]+1;
				if(n1<=1000000)
					q.push(n1);
			}
		}


		n1 = reverse(node);
		if(step[n1]==-1)
		{
			step[n1] = step[node]+1;
			if(n1<=1000000)
				q.push(n1);
		}
		else
		{
			if(step[node]+1<step[n1])
			{
				step[n1] = step[node]+1;
				if(n1<=1000000)
					q.push(n1);
			}
		}
	}
}

void main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	counter();
	int T;
	long long N;
	scanf("%d",&T);
	for(int c=1;c<=T;c++)
	{
		scanf("%lld",&N);
		
		long long res = step[N];
		printf("Case #%d: %lld\n",c,res);
	}
}