#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define  MAXN  110
int c[MAXN], b[MAXN], a[MAXN];
char s[MAXN];
int debug = false;
long long ai00(int len, int index, int end, int sum, int less){
	if (debug)cout<<len<<' '<<index<<' '<<end<<' '<<sum<<' '<<less<<endl;
	if (index == end){
		if (less) return 1;
		else return 0;
	}
	int t = 2, i = 0;
	if ((len % 2)&&(index == end + 1)) t = 1;
	if (index == len) i = 1;
	long long ret = 0;
	for (; i * i * t + sum < 10; ++i)//{
		//cout<<i<<' '<<less<<' '<<i<<' '<<b[
		if (less) ret += ai00(len, index - 1, end, sum + i * i * t, less);
		else if (i < b[index]) ret += ai00(len, index - 1, end, sum + i * i * t, true);
		else if (i == b[index]) ret += ai00(len, index - 1, end, sum + i * i * t, false);
	return ret;
}
int ai00(int len){
	int sum = 0;
	for (int j = 1; j <= len; ++j)
		c[j] = b[max(j, len - j + 1)];
	for (int i = len; i > 0; --i)
		if (b[i] < c[i]) return 0;
		else if (b[i] > c[i]) break;
	for (int i = 1; i <= len; ++i)
		sum += c[i] * c[len - i + 1];
	if (sum > 9) return 0;
	return (sum > 0);
}
void ai00(){
	for (int i = 1; i < 100; ++i){
		b[i] = 9;
		a[i] = ai00(i, i, i / 2, 0, 0);
		a[i] += ai00(i);
		//cout<<i<<' '<<a[i]<<endl;
	}
}
int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out2.txt", "w", stdout);
	ai00();
	//debug = true;
	int t, tt;
	for (scanf("%d ", &tt), t = 0; t < tt; ++t){
		scanf("%s", s);
		int n = strlen(s);
		for (int i = 1; i <= n; ++i)
			b[i] = s[n - i] - '0';
		/*
		--b[1];
		for (int i = 1; i < n; ++i)
			if (b[i] < 0){
				--b[i + 1];
				b[i] += 10;
			}else break;
		while ((n > 0)&&(b[n] == 0)) --n;
		*/
		long long ans = 0;
		if (n){
			for (int i = 1; i < n; ++i)
				ans -= a[i];
			ans -= ai00(n, n, n / 2, 0, 0);
			ans -= ai00(n);
		}
		//cout<<"   "<<-ans<<endl;
		scanf("%s", s);
		n = strlen(s);
		for (int i = 1; i <= n; ++i)
			b[i] = s[n - i] - '0';
		if (n){
			for (int i = 1; i < n; ++i)
				ans += a[i];
			ans += ai00(n, n, n / 2, 0, 0);
			//cout<<ans<<endl;
			ans += ai00(n);
			//cout<<ans<<endl;
		}
		cout<<"Case #"<<t + 1<<": "<<ans<<endl;
	}
}
