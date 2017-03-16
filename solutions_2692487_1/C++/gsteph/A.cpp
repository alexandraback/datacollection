#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int T,A,N,m[105];//,dp[5000000][105];
int recurse(int a, int i){
	if (i==N) return 0;
	//if (dp[a][i]!=-1)return dp[a][i];
	if (a<=m[i]){
		int m1=0,tmp=a;
		while(tmp<=m[i]){
			tmp+=(tmp-1);
			m1++;
		}
		return min(m1+recurse(tmp+m[i],i+1), 1+recurse(a,i+1));
	}else return recurse(a+m[i],i+1);
}

int main(){
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	cin >> T;
	for (int t = 0; t < T; t++){
		//memset(dp,-1,sizeof(dp));
		cin >> A >> N;
		for (int i = 0; i < N; i++) cin >> m[i];
		if (A==1) cout << "Case #" << t+1 << ": " << N << endl;
		else{
			sort(m,m+N);
			cout << "Case #" << t+1 << ": " << recurse(A,0) << endl;
		}
	}
	return 0;
}
