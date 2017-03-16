#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
//#include <unordered_map>

using namespace std;

const int MAXL = 1000000;
typedef long long LL;
LL dp[MAXL];

bool check(string str, int n){
	bool flag = false;
	int i, pos;
	for(i = 0, pos = -1; i < str.size(); i++){
		if(str[i] == 'a' || str[i] == 'i' || str[i] == 'e' || str[i] == 'o' || str[i] == 'u'){
			if(pos >= 0){
				if(i-pos >= n)
					flag = true;
			}
			pos = -1;
		}else{
			if(pos == -1)
				pos = i;
		}
	}

	if(pos != -1 && i-pos >= n)
		flag =true;

	//cout<<str<<" : "<<flag<<endl;
	return flag;
}

LL work(string str, int n){
	LL ret = 0;
	for(int i = 0; i < str.size(); i++){
		for(int j = i+n-1; j < str.size(); j++){
			string sub = str.substr(i, j-i+1);
			if(check(sub, n))
				ret ++;
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