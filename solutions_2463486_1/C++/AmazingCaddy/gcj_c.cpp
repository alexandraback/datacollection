#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

const ll root = 1000000000LL;
//const ll maxn = root * root;
//const int maxm = 104;

const int palind_len = 39;
ll palind [] = {1LL, 4LL, 9LL, 121LL, 484LL, 10201LL, 12321LL, 14641LL, 40804LL, 44944LL, 1002001LL, 1234321LL, 4008004LL, 100020001LL, 102030201LL, 104060401LL, 
	121242121LL, 123454321LL, 125686521LL, 400080004LL, 404090404LL, 10000200001LL, 10221412201LL, 12102420121LL, 12345654321LL, 40000800004LL, 1000002000001LL, 
	1002003002001LL, 1004006004001LL, 1020304030201LL, 1022325232201LL, 1024348434201LL, 1210024200121LL, 1212225222121LL, 1214428244121LL, 1232346432321LL, 
	1234567654321LL, 4000008000004LL, 4004009004004LL};

//int num[maxm];
int num_len;
/*
int is_palindromes (ll n) {
	num_len = 0;
	while (n) {
		num[num_len ++] = n % 10;
		n /= 10;
	}
	for (int i = 0; i < num_len; i ++) {
		if (num[i] != num[num_len - i - 1]) {
			return 0;
		}
	}
	return 1;
}

void init () {
	for (int i = 1; (ll)i * i < maxn; i ++) {
		if (is_palindromes (i) && is_palindromes ((ll)i * i)) {
			cout << "i = " << i << " i^2 = " << (ll)i * i << endl;
		}
	}
}
*/
int get_ans (ll a, ll b) {
	int ans = 0;
	for (int i = 0; i < palind_len; i ++) {
		if (palind[i] >= a && palind[i] <= b) {
			ans ++;
		}
	}
	return ans;
}

int main(int argc, char *argv[]) {
	freopen ("C-large-1.in", "r", stdin);
	freopen ("out.txt", "w", stdout);
	int cas;
	//init ();
	scanf ("%d", &cas);
	for (int t = 1; t <= cas; t ++) {
		ll a, b;
		cin >> a >> b;
		int ans = get_ans (a, b);
		printf ("Case #%d: %d\n", t, ans);
	}
	return 0;
}
