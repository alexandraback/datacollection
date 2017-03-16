#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

#define mp(a,b) make_pair((a),(b))
#define MS( a,n ) memset( a,0,sizeof(a)*n)
#define MSV( a,v ) memset( a,v,sizeof(a))
typedef long long ll;
typedef pair<int,int> pii;
#define ALL(C) (C).begin(), (C).end()
#define forIter(I,C) for(auto I=(C).begin(); I!=(C).end(); ++I)
#define forNF(I,S,C) for(int I=(S); I<int(C); ++I)
#define forN(I,C) forNF(I,0,C)
#define forEach(I,C) forN(I,(C).size())
typedef vector<pii> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;


int dp[1000001];

int reverse(int n){
	int res = 0;
	while(n){
		res=res*10+n%10;
		n/=10;
	}
	return res;
}

void insert(){
	forN(i,1000001){
		dp[i]=-1;
	}
	dp[1]=1;
	int count =1;
	queue<int> q;
	q.push(1);
	while(count<1000000){
		int cur = q.front();
		q.pop();
		int more = cur+1;
		if(more<=1000000&&dp[more]==-1){
			count++;
			dp[more]=dp[cur]+1;
			q.push(more);
		}
		int r = reverse(cur);
		if(r<=1000000&&dp[r]==-1){
			count++;
			dp[r]=dp[cur]+1;
			q.push(r);
		}
	}
}


int main()
{
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int TC, T;
	cin>>TC;
	insert();
	for (T = 1; T <= TC; T++){
		int N;
		cin>>N;
		printf("Case #%d: ", T);
		
		cout<<dp[N]<<endl;

	}
}