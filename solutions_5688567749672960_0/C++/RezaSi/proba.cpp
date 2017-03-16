#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>


using namespace std;

ifstream fin("in.txt");
ofstream fout("out.txt");

#define cin fin
#define cout fout

int rev(int x){
	vector<int> v;
	while(x % 10 == 0) x /= 10;
	while(x > 0){
		v.push_back(x % 10);
		x /= 10;
	}
	int res = 0;
	for(int i = 0 ; i < v.size() ; ++i){
		res = res * 10 + v[i];
	}
	return res;
}

int dp[1000100];
int main(){
	dp[1] = 1;
	for(int i = 2; i < 1000010; ++i){
		if(i % 10 != 0) {int x = rev(i);
		if(i > x) dp[i] = min(dp[i - 1] + 1 , dp[x] + 1);
		else dp[i] = dp[i - 1] + 1;
		}else{
			dp[i] = dp[i - 1] + 1;
		}	
	}


	int t;
	cin >> t;
	for(int o = 0 ; o < t ; ++o){
		int n;
		cin >> n;
		cout << "Case #" << o + 1 << ": " ;
		cout << dp[n] << endl;
	}
	return 0;
}
