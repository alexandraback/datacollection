#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>

#define f first
#define s second
#define pb push_back

using namespace std;

typedef pair<int,int> pr;
typedef long long ll;

//freopen("in.txt","r",stdin); 
//freopen("out.txt","w",stdout); 
int c,d,v,val;
int D[10];
int mark[40],mark1[20];


int func1(int val1)
{

	int i,x,j,sum;

	memset(mark,0,sizeof(mark));

	for(i = 1;i <= val;i++)
	{
		if((i&val1) == i)
		{
			sum = 0;
			x = 1;
			for(j = 0;j <= 8;j++)
			{
				if(i&x)
					sum = sum + (j+1);
				x = x*2;
			}
			mark[sum] = 1;
		}

	}


	for(i = 1;i <= v;i++)
	{
		if(!mark[i])
		{
			break;
		}
	}
	if(i <= v)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}


int func()
{
	int i,x,cnt,key,ans,j;

	ans = 10000000;
	for(i = 1;i <= val;i++)
	{
		x = 1;
		cnt = 0;
		for(j = 0;j <= 8;j++)
		{
			if(x&i)
			{
				if(!mark1[j+1])
				{
					cnt++;
				}
								

			}
			x = x*2;
		}		
		key = func1(i);
		if(key == 1)
		{
			//if(cnt == 0)
			//	printf("%d %d\n",cnt,i);
			ans = min(ans,cnt); 
		}

	}
	return ans;	

}



int main()
{
	int t,j,i,sol,idx;
	

	scanf("%d",&t);
	val = 1;
	for(j = 1;j <= 8;j++)
	{
		val = val*2;
	}
	val = val - 1;
	idx = 1;
	while(t--)
	{
		scanf("%d %d %d",&c,&d,&v);
		for(i = 1;i <= d;i++)
		{
			scanf("%d",&D[i]);
			mark1[D[i]] = 1;
		}		
		sol =func();
		printf("Case #%d: %d\n",idx,sol);  
		memset(mark1,0,sizeof(mark1));
		idx++;
	}

	return 0;
}

	
