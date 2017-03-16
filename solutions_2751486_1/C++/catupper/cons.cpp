#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

char V[] = "aeiou";

bool is_v(char x){
    for(long long i = 0;i < 5;i++){
	if(V[i] == x)return true;
    }
    return false;
}

long long cont[1050000];
long long dp[1050000];

long long solve(string str, long long n){
    long long res = 0;
    fill(cont, cont + 10500, 0);
    fill(dp, dp + 10500, 0);
    for(long long i = 1;i <= str.size();i++){
	if(is_v(str[i - 1]))cont[i] = 0;
	else cont[i] = cont[i - 1] + 1;
    }
    for(long long i = 1;i <= str.size();i++){
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
    long long T, n;
    string str;
    cin >> T;
    for(long long t = 1;t <= T;t++){
	cin >> str >> n;
	cout << "Case #" << t << ": " << solve(str, n) << endl;
    }
    return 0;
}
