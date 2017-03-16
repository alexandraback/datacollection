#include<stdio.h>
#include<vector>
#include<algorithm>


using namespace std;

int main()
{
	freopen("A-large.in", "r", stdin);
 	freopen("A-large.out", "w", stdout);
	int T,cnt;
	scanf("%d",&T);
	for(cnt=1;cnt<=T;++cnt)
	{
		long long A;
		int N;
		scanf("%lld %d",&A,&N);
		vector<long long> v;	
		long long t;
		int i;
		for(i=1;i<=N;++i)
		{
			scanf("%lld",&t);
			v.push_back(t);
		}
		
		sort(v.begin(),v.end());
		
		long long sum=0;
		int max=N;
		int oper=0;
		for(i=0;i<v.size();++i)
		{
			if(A<=v[i])
			{
				if(oper+v.size()-i<max)max=oper+v.size()-i;
				A+=A-1;
				--i;
				oper++;
				if(oper>max) {oper=max;break;}
			}
			else 
				A+=v[i];
		}
		printf("Case #%d: %d\n",cnt,oper);
	}
	return 0;
}
