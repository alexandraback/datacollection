#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string str;
int n, t;
int p[10800];

int solve(){
	cin >> n;
	int res = 1 << 30;
	for(int i = 0;i < n;i++)cin >> p[i];
	for(int i = 1;i <= 1000;i++){
		int tmp = i;
		for(int j = 0;j < n;j++){
			tmp += p[j] / i + (p[j] % i != 0) - 1;
		}
		res = min(res, tmp);
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