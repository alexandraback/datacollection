#include<iostream>
#include<string>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)
#define MAXL 200

int T, l, dp[MAXL][2];
char c[2] = {'-', '+'};


int main(){
	cin >> T;
	REP(t, 1, T+1){
		string s;
		cin >> s;
		l = s.size();
		REP(i, 0, l){
			REP(j, 0, 2){
				if(i){
					if(s[i]==c[j]) dp[i][j] = dp[i-1][j];
					else dp[i][j] = dp[i-1][1-j]+1;
				}else{
					if(s[i]==c[j]) dp[i][j] = 0;
					else dp[i][j] = 1;
				}
			}
		}
		cout << "Case #" << t << ": " << dp[l-1][1] << "\n";
	}
	return 0;
}
