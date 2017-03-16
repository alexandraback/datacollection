#include<iostream>
#include<algorithm>
#include<vector>
#define MAX_SUM 10000000
using namespace std;
int K[MAX_SUM];
vector<int> F[MAX_SUM];
int S[MAX_SUM];
int answer;
int N;
int FirstMask;
int SecondMask;
void check(int sum,int mask)
{
	for(int i=0;i<K[sum];i++)
		if((F[sum][i]&mask)==0)
		{
			FirstMask=F[sum][i];
			SecondMask=mask;
			answer=sum;
			return;
		}
	F[sum].push_back(mask);
	K[sum]++;
}
void rec(int num,int sum,int mask)
{
	check(sum,mask);
	if(answer) return;
	if(num==N) return;
	rec(num+1,sum,mask);
	rec(num+1,sum+S[num],mask|(1<<num));
}
void solve()
{
	int i;

	scanf("%d",&N);
	for(i=0;i<N;i++) scanf("%d",&S[i]);
	sort(S,S+N);
	answer=0;
	rec(0,0,0);
//	printf("Case #%d:\n",T);
	if(answer)
	{
//		printf("s=%d\n",answer);
		for(i=0;FirstMask;i++)
		{
			if(FirstMask%2) printf("%d ",S[i]);
			FirstMask/=2;
		}
		printf("\n");
		for(i=0;SecondMask;i++)
		{
			if(SecondMask%2) printf("%d ",S[i]);
			SecondMask/=2;
		}
	}
	else printf("Impossible");
	printf("\n");
}
int main() 
{
	int i,T=1;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	solve();

	return 0;
}