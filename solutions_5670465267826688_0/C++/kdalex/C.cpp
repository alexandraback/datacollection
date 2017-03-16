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
};
bool operator==(const v&a, const v&b) {
	return a.x == b.x && a.y == b.y && a.z == b.z;
}
bool operator==(const quat&a, const quat&b) {
	return a.w == b.w && a.vec == b.vec;
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
vector<quat> dataq;

int main() {
	quat T[4] = {{1, {0, 0, 0}}, {0, {1, 0, 0}}, {0, {0, 1, 0}}, {0, {0, 0, 1}}};
	char Tc[4] = {'1', 'i', 'j', 'k'};
	int N = 10000;
	data.resize(N);
	dataq.resize(N);
	string data2;
	int L, X;
	int TT;
	cin >> TT;
	for(int t = 0; t < TT; ++t) {
		cin >> L >> X >> data2;
		N = L * X;
		assert(data2.size() == L);
		for(int i = 0; i < N; ++i)
			data[i] = data2[i % L];
		quat mc = {1, {0, 0, 0}};
		for(int i = 0; i < N; ++i)
			mc = dataq[i] = mc * quat::u(data[i]);
		bool found = false;
		if(mc == quat({-1, {0, 0, 0}}))
		for(int i = 0; i < N; ++i) {
			for(int j = i + 1; j < N; ++j) {
#if 0
				cout << "(";
				for(int k = 0; k <= i; ++k)
					cout << data[k];
				cout << ") ";
				cout << "(";
				for(int k = i + 1; k <= j; ++k)
					cout << data[k];
				cout << ") ";
				cout << "(";
				for(int k = j + 1; k < N; ++k)
					cout << data[k];
				cout << ") ";
				cout << " = " << dataq[i] << " " << dataq[j]/dataq[i] << " " << dataq[N-1]/dataq[j] << endl;
#endif
				if(dataq[i] == T[1] && dataq[j]/dataq[i] == T[2] && dataq[N-1]/dataq[j] == T[3]){
#if 0
					cout << i << " "  << j << endl;
#endif
					found = true;
					break;
				}

			}
			if(found) break;
		}
		cout << "Case #" << t+1 << ": " << (found ? "YES" : "NO") << endl;
	}
	return 0;
}
