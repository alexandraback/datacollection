#include <iostream>
#include <cstdio>
using namespace std;
struct st {
	char v;
	int sgn;
	st(int sg,char va):sgn(sg),v(va) {};
	st():sgn(1), v('1') {};
	bool operator==(const st &x) {
		return v==x.v&&sgn==x.sgn;
	}
};

st d[3][3] = {
	{st(-1,'1'), st(1,'k'), st(-1,'j')},
	{st(-1,'k'), st(-1,'1'), st(1,'i')},
	{st(1,'j'), st(-1,'i'), st(-1, '1')}
};

st mul(char c, st s) {
	if (s.v == '1') {
		s.v = c;
		return s;
	}
	int j = c-'i';
	int i = s.v-'i';
	st res = d[j][i];
	res.sgn *= s.sgn;
	return res;
}

st mul(st s, char c) {
	if (s.v == '1') {
		s.v = c;
		return s;
	}
	int j = c-'i';
	int i = s.v - 'i';
	st res = d[i][j];
	res.sgn *= s.sgn;
	return res;
}

int main() {
	int t;
	cin>>t;
	const int N = 10007;
	const int MN = 16*N;
	char a[MN];
	st ss[MN];
	const st kk(1,'k');
	const st ii(1,'i');
	for(int K=1;K<=t;++K){
		int l;
		long long x;
		cin>>l>>x;
		if (x > 12) x = x%4 + 12;
		int sz = x*l;
		cin>>a;
		for (int i=l;i<sz;++i)a[i]=a[i%l];
		ss[sz] = st(1,'1');
		for (int i = sz-1; i >= 0; --i) {
			ss[i] = mul(a[i], ss[i+1]);
		}
		st sum(1,'1');
		int i1 = -1;
		int i2 = -1;
		for (int i=0;i<sz;++i) {
			sum = mul(sum, a[i]);
			if (sum == ii && ss[i+1] == ii) {
				i1 = i;
				break;
			}
		}
		if (i1 >= 0) {
			for (int i=i1+1; i < sz; ++i) {
				sum = mul(sum, a[i]);
				if (sum == kk && ss[1+i] == kk) {
					i2 = i;
					break;
				}
			}
		}
		printf("Case #%d: %s\n", K, i2 >= 0 ? "YES" : "NO");
	}
}
