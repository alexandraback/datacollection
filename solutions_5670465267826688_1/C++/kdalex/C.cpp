#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cassert>

using namespace std;

struct v {
	int x;
	int y;
	int z;
	static v zero() {
		return {0, 0, 0};
	}
};

v operator*(const int& a, const v &b) {
	return {a*b.x, a*b.y, a*b.z}; 
}

v operator*(const v& b, const int &a) {
	return {a*b.x, a*b.y, a*b.z}; 
}

v operator+(const v &a, const v& b) {
	return {a.x + b.x, a.y + b.y, a.z + b.z};
}

v operator*(const v &a, const v& b) {
	return {a.y * b.z - a.z * b.y, -a.x * b.z + a.z * b.x, a.x * b.y - a.y * b.x};
}

int operator^(const v &a, const v&b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

v operator-(const v &a) {
	return -1 * a;
}

v operator-(const v &a, const v &b) {
	return a + (-b);
}

struct quat {
	int w;
	v vec;
	static quat zero() {
		return {0, v::zero()};
	}
	static quat u(char c) {

		if(c == 'i')
			return {0, {1, 0, 0}};
		if(c == 'j')
			return  {0, {0, 1, 0}};
		if(c == 'k')
			return {0, {0, 0, 1}};
	}
	quat reciproc() {
		return quat({w, -vec});
	}
};
bool operator==(const v&a, const v&b) {
	return a.x == b.x && a.y == b.y && a.z == b.z;
}
bool operator==(const quat&a, const quat&b) {
	return a.w == b.w && a.vec == b.vec;
}
bool operator!=(const quat&a, const quat&b) {
	return !(a == b);
}
quat operator*(const quat& a, const quat &b) {
	return {a.w * b.w - (a.vec^ b.vec), a.w * b.vec + a.vec * b.w + a.vec * b.vec};
}
quat operator/(const quat& a, const quat &b) {
	quat res =quat({b.w, -b.vec})*a;
	assert(b*res==a);
	return res;
}
ostream& operator<<(ostream& os, const v& a) {
	return os << a.x << "i " << a.y << "j "  << a.z << "k";
}
ostream& operator<<(ostream& os, const quat& a) {
	return os << a.w << " " << a.vec;
}

string data;
vector<quat> dataq, dataqr, dataf;

int main() {
	quat T[4] = {{1, {0, 0, 0}}, {0, {1, 0, 0}}, {0, {0, 1, 0}}, {0, {0, 0, 1}}};
	char Tc[4] = {'1', 'i', 'j', 'k'};
	int N;// = 10000;
	string data2;
	long long L, X;
	int TT;
	cin >> TT;
	quat dqp[4];
	quat dqpr[4];
	for(int t = 0; t < TT; ++t) {
		cin >> L >> X >> data2;
		N = L * X;
//		cout << L << " " <<  data2.size() << endl;
		assert(data2.size() == L);
		quat mc = {1, {0, 0, 0}};
		quat mcr = {1, {0, 0, 0}};


		dataq.resize(L);
		dataqr.resize(L);
		for(long long i = 0; i < L; ++i) {
			mc = dataq[i] = mc * quat::u(data2[i]);
			mcr = dataqr[i] = quat::u(data2.rbegin()[i]) * mcr;
		}

		dqp[0] = {1, {0, 0, 0}};
		dqpr[0] = {1, {0, 0, 0}};
		for(long long i = 1; i < 4; ++i) {
			dqp[i] = dqp[i - 1] * mc;
			dqpr[i] = mcr*dqpr[i - 1];
		}
		assert(dqp[3]*mc == quat({1,{0,0,0}}));
		assert(mcr*dqpr[3] == quat({1,{0,0,0}}));

		bool found = false;
		mc = dqp[X % 4LL];
		mcr = dqpr[X%4LL];
		assert(mcr == mc);
		if(mc == quat({-1, {0, 0, 0}}))
			for(long long i = 0; i < L*8LL && i < N && !found; ++i) {
				quat left = dqp[(i/L)%4LL]*dataq[i%L];
				if(left != T[1])
					continue;
				for(long long j = 0; j < L*8LL && (i+j+2LL)<N && !found;++j) {
					quat right = dataqr[j%L]*dqpr[(j/L)%4LL];

					quat mid = left.reciproc() * mc * right.reciproc();
					if(mid == T[2] && right == T[3]) {
						found = true;
					}
				}
			}
		cout << "Case #" << t+1 << ": " << (found ? "YES" : "NO") << endl;
	}
	return 0;
}
