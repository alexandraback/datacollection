#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

char V[] = "aeiou";

bool is_v(char x){
    for(int i = 0;i < 5;i++){
	if(V[i] == x)return true;
    }
    return false;
}

int cont[1050000];
int dp[1050000];

int solve(string str, int n){
    int res = 0;
    fill(cont, cont + 10500, 0);
    fill(dp, dp + 10500, 0);
    for(int i = 1;i <= str.size();i++){
	if(is_v(str[i - 1]))cont[i] = 0;
	else cont[i] = cont[i - 1] + 1;
    }
    for(int i = 1;i <= str.size();i++){
	dp[i] = dp[i - 1];
	if(cont[i] == n){
	    dp[i] = i - n + 1;
	}
	if(cont[i] > n){
	    dp[i]++;
	}
	res += dp[i];
    }
    return res;
}

int main(){
    int T, n;
    string str;
    cin >> T;
    for(int t = 1;t <= T;t++){
	cin >> str >> n;
	cout << "Case #" << t << ": " << solve(str, n) << endl;
    }
    return 0;
}
