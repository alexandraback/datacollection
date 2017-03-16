#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

const int N = 111;
int t, n, a[N], ans;
string s;

char tanx(char c){
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return 0;
	return 1;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	cin >> t;
	for(int tc = 1; tc <= t; tc++){
		cin >> s >> n;
		fill(a, a + N, 0);
		ans = 0;
		for(int i = 0; i < s.size(); i++)
			for(int j =  i; j < s.size(); j++){
				int cnt = 0, k = i, ok = 0;
				while(k <= j){
					while(k <= j && tanx(s[k]))k++, cnt++;
					if(cnt >= n){
						ok = 1;
						break;
					}
					cnt = 0;
					while(k <= j && !tanx(s[k]))k++;
				}
				if(ok)ans++;
			}
		printf("Case #%d: %d\n", tc, ans);
	}

	return 0;
}