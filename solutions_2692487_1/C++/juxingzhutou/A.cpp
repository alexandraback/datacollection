#include<stdio.h>
#include<vector>
#include<algorithm>


using namespace std;

int main()
{
	int T,abc;
	scanf("%d",&T);
	FILE * out;
	out = fopen("C:/Users/lvhh/Desktop/outputA.out","w");
	for(abc=1;abc<=T;++abc)
	{
		long long A;
		int N;
		scanf("%lld %d",&A,&N);
	
		vector<long long> vec;	
		long long t;
		int i;
		for(i=1;i<=N;++i)
		{
			scanf("%lld",&t);
			vec.push_back(t);
		}
		
		/*if(A==1) {
			printf("Case #%d: %d\n",abc,N);
		//fprintf(out,"Case #%d: %d\n",abc,N);
		continue;
		}*/
		
		sort(vec.begin(),vec.end());
		
		long long sum=0;
		int max=N;
		int count=0;
		for(i=0;i<vec.size();++i)
		{
			if(A<=vec[i]) {
			if(count+vec.size()-i<max)max=count+vec.size()-i;
			A+=A-1;
			--i;
			count++;
			if(count>max) {count=max;break;}
			}
			else 
			{
				A+=vec[i];
			}
		}
		fprintf(out,"Case #%d: %d\n",abc,count);
		//printf("Case #%d: %d\n",abc,count);
	}
	return 0;
}
