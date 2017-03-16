#include <bits/stdc++.h>

using namespace std;

/*
 * 0 -> [1]
 * 1 -> [i] 
 * 2 -> [j]
 * 3 -> [k]
 */
class quaternion_t {
	static quaternion_t m_tab[4][4];
public:
	int k;
	char s;

	quaternion_t(int k_ = 0, char s_ = 0) : k(k_), s(s_) { }
	bool operator == (const quaternion_t & x) const {
		return k == x.k && s == x.s;
	}
	bool operator != (const quaternion_t & x) const {
		return k != x.k || s != x.s;
	}
	quaternion_t operator - () const {
		return { k, 1 - s };
	}
	quaternion_t & operator *= (const quaternion_t & x) {
		char my_s = s;
		*this = m_tab[k][x.k];
		s ^= my_s ^ x.s;
		return *this;
	}
	quaternion_t operator * (const quaternion_t & x) const {
		return quaternion_t(*this) *= x;
	}
	quaternion_t inverse() const {
		return *this * *this * *this;
	}
};

quaternion_t quaternion_t::m_tab[4][4] = {
	{ 0, 1, 2, 3 },
	{ 1, {0, 1}, 3, {2, 1} },
	{ 2, {3, 1}, {0, 1}, 1 },
	{ 3, 2, {1, 1}, {0, 1} }
};

const quaternion_t O = 0, I = 1, J = 2, K = 3;

quaternion_t Q[20010], P[20010];
void solve(int t) {
	int L, X;
	scanf("%d %d\n", &L, &X);
	for(int l = 0; l < L; ++l)
		Q[l] = Q[l + L] = getchar() - 'h';
	P[0] = O;
	for(int l = 1; l <= 2 * L; ++l)
		P[l] = P[l - 1] * Q[l - 1];
	for(int p1 = 1; p1 <= L; ++p1) {
		auto prod = P[p1];
		int usedX1 = 0;
		while(usedX1 < 4 && prod != I) {
			prod *= P[p1].inverse() * P[L + p1];
			++usedX1;
		}
		if(usedX1 == 4 || usedX1 >= X) continue;
		for(int p2 = p1 + 1; p2 < 2 * L; ++p2) {
			prod = P[p1].inverse() * P[p2];
			int usedX2 = 0;
			while(usedX2 < 4 && prod != J) {
				prod *= P[p2 % L].inverse() * P[L + (p2 % L)];
				++usedX2;
			}
			if(usedX2 == 4 || usedX1 + usedX2 + int(p2 >= L) >= X) continue;
			if(p2 >= L)
				++usedX2;
			prod = O;
			int usedX3 = X - 1 - usedX1 - usedX2;
			while(usedX3 % 4) {
				prod *= P[p2 % L].inverse() * P[L + (p2 % L)];
				--usedX3;
			}
			prod *= P[p2 % L].inverse() * P[L];
			if(prod != K) continue;
			printf("Case #%d: YES\n", t);
			return;
		}
	}
	printf("Case #%d: NO\n", t);
}

int main() {
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
		solve(t);
}
