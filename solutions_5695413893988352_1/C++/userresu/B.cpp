#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;

char str1[20],str2[20];
char n1[20],n2[20];
char s1[20],s2[20];
ll a = 2000000000, b=0;
int n ;
ll fix (char *x) {
	ll ret = 0;
	for (int i=0;i<n;++i) ret = ret * 10 + x[i] - '0';
	return ret;
}

void check () {
	ll x = fix(n1), y = fix(n2);
	if (abs(x-y) < abs(a-b) || abs(x-y)==abs(a-b) && (x < a || x == a && y < b)) {
		a = x;
		b = y;
		strcpy(s1, n1);
		strcpy(s2, n2);
	}
}

void solve () {
	for (int i=0;i<n;++i) {
		if (i && str1[i-1] != '?' && str2[i-1] != '?' && str1[i-1] != str2[i-1]) break;
		if (i) {
			if (str1[i-1] == '?') {
				if (str2[i-1] == '?') n1[i-1] = n2[i-1] = '0';
				else n1[i-1] = n2[i-1] = str2[i-1];
			}
			else if (str2[i-1] == '?') n1[i-1] = n2[i-1] = str1[i-1];
			else n1[i-1] = n2[i-1] = str1[i-1];
		}
		if (str1[i] == '?') {
			if (str2[i] == '?') {
				n1[i] = '0';
				n2[i] = '1';
			}
			else {
				if (str2[i] == '0') continue;
				n1[i] = str2[i] - 1;
				n2[i] = str2[i];
			}
		}
		else if (str2[i] == '?') {
			if (str1[i] == '9') continue;
			n1[i] = str1[i];
			n2[i] = str1[i] + 1;
		}
		else {
			if (str1[i] >= str2[i]) continue;
			n1[i] = str1[i];
			n2[i] = str2[i];
		}
		for (int j=i+1;j<n;++j) {
			if (str1[j] == '?') n1[j] = '9';
			else n1[j] = str1[j];
			if (str2[j] == '?') n2[j] = '0';
			else n2[j] = str2[j];
		}
		check();
	}
}
void solve3 () {
	for (int i=0;i<n;++i) {
		if (str1[i] != '?'){
			if (str2[i] != '?') {
				if (str1[i] != str2[i]) return;
			}
			n1[i] = n2[i] = str1[i];
		}
		else if (str2[i] != '?') n1[i] = n2[i] = str2[i];
		else n1[i] = n2[i] = '0';
	}
	check();
}

void solve2 () {
	for (int i=0;i<n;++i) {
		if (i && str1[i-1] != '?' && str2[i-1] != '?' && str1[i-1] != str2[i-1]) break;
		if (i) {
			if (str1[i-1] == '?') {
				if (str2[i-1] == '?') n1[i-1] = n2[i-1] = '0';
				else n1[i-1] = n2[i-1] = str2[i-1];
			}
			else if (str2[i-1] == '?') n1[i-1] = n2[i-1] = str1[i-1];
			else n1[i-1] = n2[i-1] = str1[i-1];
		}
		if (str1[i] == '?') {
			if (str2[i] == '?') {
				n1[i] = '1';
				n2[i] = '0';
			}
			else {
				if (str2[i] == '9') continue;
				n1[i] = str2[i] + 1;
				n2[i] = str2[i];
			}
		}
		else if (str2[i] == '?') {
			if (str1[i] == '0') continue;
			n1[i] = str1[i];
			n2[i] = str1[i] - 1;
		}
		else {
			if (str1[i] <= str2[i]) continue;
			n1[i] = str1[i];
			n2[i] = str2[i];
		}
		for (int j=i+1;j<n;++j) {
			if (str1[j] == '?') n1[j] = '0';
			else n1[j] = str1[j];
			if (str2[j] == '?') n2[j] = '9';
			else n2[j] = str2[j];
		}
		check();
	}
}

int main () {
	int T;
	scanf("%d",&T);
	for (int z=1;z<=T;++z) {
		a = 2000000000, b=0;
		scanf("%s %s",str1,str2);
		n = strlen(str1);
		n1[n] = n2[n] = 0;
		solve3();
		solve2();
		solve();
		printf("Case #%d: %s %s\n",z,s1,s2);
	}
	return 0;
}
