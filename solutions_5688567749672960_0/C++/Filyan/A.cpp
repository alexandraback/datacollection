#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
using namespace std;

int const N = 1e6 + 1;
set< pair<int,int> > q;
int dp[N];

int getRev(int v){
	string s = to_string(v);
	reverse(s.begin(), s.end());
	int r = 0;
	int n = s.size();
	for(int i=n-1,j =1;i>=0;--i,j*=10){
		r += j * (s[i] - '0');
	}
	return r;	
}

void calcDp(){
	q.insert(make_pair(1, 1));
	while(q.size()){
		pair<int,int> cur = *(q.begin());
		q.erase(q.begin());
		int value = cur.first;
		int number = cur.second;
		if(number >= N)
			continue;
		dp[number] = min(dp[number], value);
		int number1 = number+1;
		int value1 = value+1;
		if(number1 < N && dp[number1] == N){
			dp[number1] = value1;
			q.insert(make_pair(value1, number1));
		}
		
		int number2 = getRev(number);
		int value2 = value+1;
		if(number2 < N && dp[number2] == N){
			dp[number2] = value2;
			q.insert(make_pair(value2, number2));
		}
	}
}

int main(){

	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);

	dp[1] = 1;
	for(int i=2;i<N;++i){
		dp[i] = N;
	}
	calcDp();

	int test;
	scanf("%d",&test);
	for(int t=1;t<=test;++t){
		int n;
		scanf("%d",&n);
		printf("Case #%d: %d\n",t,dp[n]);
	}

	return 0;
}