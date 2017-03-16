#include<stdio.h>
#include<iostream>
#include<cmath>
#include<cstdlib>
#define FOR(i,x) for(i=1;i<=x;i++)
using namespace std;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

bool SS(int set[], int n, int sum)
{
   if (sum == 0)
     return true;
   if (n == 0 && sum != 0)
     return false;

   if (set[n-1] > sum)
     return SS(set, n-1, sum);
     
   return SS(set, n-1, sum) || SS(set, n-1, sum-set[n-1]);
}

int power(int x)
{
	int count=0;
	if(x==1)
		return 0;
	while(x!=0)
	{
		x/=2;
		count++;
	}
	return count-1;
}

int main()
{
	int it,t;
	cin>>t;
	FOR(it,t)
	{
		long long c,d,v;
		int i;
		cin>>c>>d>>v;
		int denom[100],poss[31];
		FOR(i,d)
			cin>>denom[i-1];
		qsort(denom,d,sizeof(int),compare);
		if(c==1)
		{
			int ans=0;
			
			FOR(i,6)
			{
				qsort(denom,d,sizeof(int),compare);
				int k=0;
				int x;
				FOR(x,v)
				{
					if(SS(denom,d,x)==false)
						poss[k++]=x;
				}
				if(k==0)
				{
					cout<<"Case #"<<it<<": "<<ans<<endl;
					break;
				}
				x=power(poss[0]);
				denom[d++]=pow(2,x);
				//cout<<denom[d-1]<<endl;
				ans++;
			}
			
		}
	}
	
	return 0;
}
