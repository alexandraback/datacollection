#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string str;
int n, t;

int solve(){
	cin >> n;
	cin >> str;
	int cnt = 0;
	int res = 0;
	for(int i = 0;i <= n;i++){
		if(cnt < i){
			res += i - cnt;
			cnt = i;
		}
		cnt += str[i] - '0';
	} 
	return res;
}

int main(){
	cin >> t;
	for(int i = 1;i <= t;i++){
		cout << "Case #" << i << ": " << solve() << endl;
	}
	return 0;
}