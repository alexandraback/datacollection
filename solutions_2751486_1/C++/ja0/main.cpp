#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

const int N = (int)1e6+10;
ll len, t, n, m;
int x[N], y[N];
string s;

char xmov(char c){
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')return 1;
	return 0;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	cin >> t;
	for(int tc = 1; tc <= t; tc++){
		cin >> s >> n;
		m = s.size();
		len = 0;
		{
			int i = 0;
			while(i < m){
				while(i < m && xmov(s[i]))i++;
				int L = i, cnt = 0;
				while(i < m && !xmov(s[i]))cnt++, i++;
				if(cnt >= n){
					x[++len] = L;
					y[len] = i - 1;
				}
			}
		}
		/*
		cout << len << endl;
		for(int i = 1; i <= len; i++)
			cout << x[i] << " " << y[i] << endl;
		*/
		ll ans = 0;
		if(len == 0){
			cout << "Case #" << tc << ": " << ans << endl;
			continue;
		}
		int last = 1;
		for(int i = x[1] + n - 1; i < m; i++){
			if(last + 1 <= len && i >= x[last + 1] + n - 1)last++;
			ll k = min(y[last], i) - n + 1;
			ans += (k + 1);
		}
		cout << "Case #" << tc << ": " << ans << endl;
	}

	return 0;
}