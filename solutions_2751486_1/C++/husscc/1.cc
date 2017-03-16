#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <memory.h>

using namespace std;

const int MAXL = 1000000;
typedef long long LL;
LL dp[MAXL];
bool start[MAXL], end[MAXL];

bool checkv(char c){
	return (c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u');
}	


LL work(string str, int n){
	memset(start, 0, sizeof((start)));
	memset(end, 0, sizeof(end));
	memset(dp, 0, sizeof(start));

	dp[0] = checkv(str[0]) ? 0 : 1;
	for(int i = 1; i < str.size(); i++){
		if(!checkv(str[i]))
			dp[i] = dp[i-1]+1;
	}

	for(int i = n-1; i < str.size(); i++){
		if(dp[i] >= n){
			end[i] = true; start[i-n+1] = true;
		}
	}

	LL ret = 0, left, right;
	for(int i = 0; i < str.size(); i++){
		if(start[i]){
			left = i;
			right = i+n;
			for(; !end[right] && right < str.size(); right++) {}
			right = right-(i+n);

			ret += (left+1)*(right+1);
		}
	}
	return ret;
}

int main(){
	int T; cin>>T;
	string str;
	int n;
	for(int i = 1; i <= T; i++){
		cin>>str>>n;
		cout<<"Case #"<<i<<": ";
		cout<<work(str, n)<<endl;
	}
}