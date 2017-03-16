#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;

struct node{
	int index;
	int nowe;
	int point;
};

int dp[10][6];


int main(){
	ifstream ifs("B-small-attempt7.in");
	ofstream ofs("ans_b_8.txt");

	int loop;
	ifs >> loop;
	for(int l=0;l<loop;l++){
		memset(dp,0,sizeof(dp));
		int e,r,n;
		ifs >> e >> r >> n;
		int len[10]={0};
		for(int i=0;i<n;i++){
			ifs >> len[i];
		}

		int ans = 0;

		int nowe = e;
		int point = 0;
		for(int i=0;i<=e;i++){
			dp[0][i] = (e-i) * len[0];
		}

		for(int i=0;i<n-1;i++){
			for(int j=0;j<=e;j++){
				for(int k=0;k<j+r;k++){
					if(k < e){
						int usemax = j+r-k;
						if(usemax > e){
							usemax = e;
						}
						dp[i+1][k] = max(dp[i+1][k],dp[i][j] + len[i+1]*usemax);
					}
				}
				if(j+r < e){
					dp[i+1][j+r] = max(dp[i+1][j+r], dp[i][j]);
				}
			}
		}
		ofs << "Case #" << (l+1) << ": " << dp[n-1][0] << endl;

	}
}