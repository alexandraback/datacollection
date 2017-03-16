#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int pow10[9];

int help(){
	pow10[0] = 1;
	for(int i = 1; i < 9; i++){
		pow10[i] = 10*pow10[i-1];
	}
}

int comp(int num, int i, int ndigits){
	int tail = num % pow10[ndigits-i];
	int ret = (num-tail)/pow10[ndigits-i]+tail*pow10[i];
	return ret;
}

int main(){
	help();
	freopen("C-large.in", "r", stdin);
	freopen("C-large-out.out", "w", stdout);
	int T, a, b;
	set<int> S;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		scanf("%d %d", &a, &b);
		int len = 0, tmp = a;
		while(tmp){
			tmp/=10;
			len++;
		}

		int ans = 0;
		for(int i = a; i < b; i++){
			S.clear();
			for(int j = 1; j < len; j++){
				int newNum = comp(i, j, len);
				if(newNum <= b && i < newNum){
					S.insert(newNum);
				}
			}
			ans += S.size();
		}

		cout << "Case #" << t << ": " << ans;
		if(t < T) cout << endl;
	}

	return 0;
}
