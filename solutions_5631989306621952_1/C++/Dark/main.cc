#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

const int maxn = 1 << 20;
int ans[maxn]={};
int main(){
	int T;
	cin >> T;
	for(int t = 0; t<T; t++){
		printf("Case #%d: ", t+1);
		string str, ans;
		cin >> str;
		for(int i=0;i<str.size();i++){
			string tmp = str[i] + ans;
			string tmp2 = ans + str[i];
			if(tmp<tmp2) ans = tmp2;
			else ans = tmp;
		}
		cout << ans << endl;
	}
}