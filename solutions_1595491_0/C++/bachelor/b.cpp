#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dp[110][110];
int record[31][11][2];
int sum[110];

void calc_record(){
	memset(record, 0, sizeof(record));
	for(int i = 0; i <= 10; ++i)
		for(int j = i; j <= min(i + 2, 10); ++j)
			for(int k = i; k <= j; ++k){
				int s = i + j + k;
				record[s][j][(i+2) == j] = 1;
			}
/*	for(int s = 30; s >= 1; --s){
		for(int i = 9; i >= 0; --i)
			for(int k = 0; k < 2; ++k)
				if(record[s][i+1][k])record[s][i][k] = 1;

		for(int i = 0; i <= 9; ++i){
			if(record[s][i][0] || record[s][i][2])
				record[s][i+1][2] = 1;
			if(record[s][i][1] || record[s][i][3])
				record[s][i+1][3] = 1;
		}
*/
//	}
}

int main()
{
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("B-small-attempt2.out", "w", stdout);
	int T, N, S, p;
	calc_record();
	cin>>T;
	for(int tt = 1; tt <= T; ++tt){
		cin>>N>>S>>p;
		for(int i = 1; i <= N; ++i)
			cin>>sum[i];
		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;
		for(int i = 0; i < N; ++i){
			for(int j = 0; j <= S; ++j){
				if(dp[i][j] == -1)continue;
				int t = sum[i + 1];
				for(int m = 0; m <= 10; ++m){
					int f = (m >= p);
					if(record[t][m][0])
						dp[i+1][j] >?= dp[i][j] + f;
					if(record[t][m][1])
						dp[i+1][j+1] >?= dp[i][j] + f;
				}
			}
		}
//		if(tt == 3)cout<<record[0][1][2]<<endl;
		cout<<"Case #"<<tt<<": "<<max(0, dp[N][S])<<endl;
	}
	
	return 0;
}	
