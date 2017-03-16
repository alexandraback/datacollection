#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<functional>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

int solve1(int A, int B, int K) {
	int ans = 0;
	for(int a = 0; a < A; ++a)
		for(int b = 0; b < B; ++b) {
			if ((a & b) < K)
				ans++;
		}
	return ans;
}
int c1() {
	int k = 3827;
	int zeros = 0;
	int _k = k;
	while(_k) {
		zeros += !(_k & 1);_k>>=1;
	}
	int ans = 0;
	for(int a = 0; a <= 10*k; ++a)
		for(int b = 0; b <= 10*k; ++b)
			if ((a & b) == k)
				ans++;
	cout << "zeros= " << zeros << ", ans=" << ans << endl;
}
vector<int> av, bv, kv;
int n;
unordered_map<int, long long> cache;

long long getsol1(int ii, int sma, int smb, int smk) {
	long long ans = 0;
	int key = (ii << 4) + sma * 4 + smb * 2 + smk;
	if (cache.find(key) != cache.end())
		return cache[key];
	if (ii == 32)
		return cache[key] = smk && sma && smb;
	//cout << ii << " " << sma << " " << smb << " " << smk << endl;
	if (kv[ii] == 1 || smk) {
		if ((sma || (av[ii] == 1)) && (smb || (bv[ii] == 1))) {
			ans += getsol1(ii + 1, sma, smb, smk);
		}
	}
	if (kv[ii] == 1) smk = 1;
	if (av[ii] == 1 || sma) {
		ans += getsol1(ii + 1, sma, (bv[ii] == 1) || smb, smk);
	}
	if (bv[ii] == 1 || smb) {
		ans += getsol1(ii + 1, sma || (av[ii] == 1), smb, smk);
	}

	ans += getsol1(ii + 1, sma || (av[ii] == 1), smb || (bv[ii] == 1), smk);
	return cache[key] = ans;
}
vector<int> split(int a) {
	vector<int> ret;
	while(a) {
		ret.push_back(a & 1);
		a >>= 1;
	}
	while(ret.size() < 32)
		ret.push_back(0);
	std::reverse(ret.begin(), ret.end());
	return ret;
}
int main() {
	int T, A, B, K;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cin >> A >> B >> K;
		cout << "Case #" << t << ": ";
//		cout << solve1(A, B, K) << endl;
		av = split(A), bv = split(B), kv = split(K);
		cache.clear();
		cout << getsol1(0, 0, 0, 0) << endl;
	}
	return 0;
}
