#include <iostream>
#include <vector>
using namespace std;
vector<long long> A,B;
vector<long long> An,Bn;
int n,m;
int cn;
long long ans=0;
void dfs(int i, int j, long long sum)
{
	if(i>=n||j>=m)
	{
		if(sum>ans)
			ans = sum;
		return;
	}
	if(A[i]==B[j])
	{
		if(An[i]>Bn[j])
		{
			An[i]-=Bn[j];
			dfs(i, j+1, sum+Bn[j]);
			An[i]+=Bn[j];
		}
		else
		{
			Bn[j]-=An[i];
			dfs(i+1, j, sum+An[i]);
			Bn[j]+=An[i];
		}
	}
	else
	{
		dfs(i, j+1, sum);
		dfs(i+1, j, sum);
	}
}
int main(){
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	cin>>cn;
	for (int cs=1;cs<=cn;cs++){
		cin>>n>>m;
		A.reserve(n+2);
		An.reserve(n+2);
		B.reserve(m+2);
		Bn.reserve(m+2);
		for (int j=1;j<=n;j++)
		{
			cin>>An[j-1]>>A[j-1];
		}
		for (int j=1;j<=m;j++)
		{
			cin>>Bn[j-1]>>B[j-1];
		}
		ans=0;
		dfs(0,0,0);
		printf("Case #%d: %lld\n", cs, ans);
	}

	return 0;
}