#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>

using namespace std;

int T;
long long N, PN;
int mmax;
long long DP[10000000];

long long reverse(long long num)
{
	string temp;
	temp = to_string(num);
	reverse(temp.begin(), temp.end());
	return stoi(temp, nullptr, 10);
}


int main()
{
	int t;
	long long i, num, temp;

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d", &T);

	for(t=1; t<=T; t++)
	{
		scanf("%d", &N);
		if(PN >= N)
		{
			printf("Case #%d: %lld\n", t, DP[N]);
			continue;
		}
		
		for(i=PN+1; i<=N; i++)
		{
			temp=reverse(i);
			if(temp < i && i%10!=0)
				DP[i]=min(DP[i-1]+1, DP[temp] + 1);
			else
				DP[i]=DP[i-1]+1;
		}
		PN=N;
		printf("Case #%d: %lld\n", t, DP[N]);
	}

	return 0;
}