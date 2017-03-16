#pragma warning(disable : 4996)
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

vector<int> A, B;

long long d10(int degree){
	long long res = 1;
	for (int i = 0; i < degree; i++)
		res *= 10;
	return res;
}

long long evalmin(const vector<int> &s, int degree){
	long long res = 0;
	for (int i = degree; i >= 0; i--){
		long long a;
		if (s[i] == -1)
			a = 0;
		else
			a = s[i];
		res = res * 10 + a;
	}
	return res;
}

long long evalmax(const  vector<int>  &s, int degree){
	long long res = 0;
	for (int i = degree; i >= 0; i--){
		long long a;
		if (s[i] == -1)
			a = 9;
		else
			a = s[i];
		res = res * 10 + a;
	}
	return res;
}

//long long abs(long long a){
//	return a < 0 ? -a : a;
//}

pair<long long, long long> f(int degree){
	if (degree < 0)
		return make_pair(0LL, 0LL);
	if (A[degree] != -1 && B[degree] != -1){
		if (A[degree] == B[degree]){
			auto r = f(degree - 1);
			return make_pair(d10(degree) * A[degree] + r.first, d10(degree) * B[degree] + r.second);
		}
		else{
			if (A[degree] > B[degree]){
				return make_pair(d10(degree) * A[degree] + evalmin(A, degree - 1), d10(degree) * B[degree] + evalmax(B, degree - 1));
			}
			else{
				return make_pair(d10(degree) * A[degree] + evalmax(A, degree - 1), d10(degree) * B[degree] + evalmin(B, degree - 1));
			}
		}
	}
	else{
		vector<pair<long long, long long>> v;
		if (A[degree] == -1){
			if (B[degree] == -1){
				v.push_back(make_pair(d10(degree) * 0 + evalmax(A, degree - 1), d10(degree) * 1 + evalmin(B, degree - 1)));
				v.push_back(make_pair(d10(degree) * 1 + evalmin(A, degree - 1), d10(degree) * 0 + evalmax(B, degree - 1)));
				auto r = f(degree - 1);
				v.push_back(make_pair(d10(degree) * 0 + r.first, d10(degree) * 0 + r.second));
			}
			else{
				if (B[degree] - 1 >= 0)
					v.push_back(make_pair(d10(degree) * (B[degree] - 1) + evalmax(A, degree - 1), d10(degree) * B[degree] + evalmin(B, degree - 1)));
				if (B[degree] + 1 <= 9)
					v.push_back(make_pair(d10(degree) * (B[degree] + 1) + evalmin(A, degree - 1), d10(degree) * B[degree] + evalmax(B, degree - 1)));
				auto r = f(degree - 1);
				v.push_back(make_pair(d10(degree) * B[degree] + r.first, d10(degree) * B[degree] + r.second));
			}
		}
		else{
			if (A[degree] - 1 >= 0)
				v.push_back(make_pair(d10(degree) * (A[degree]) + evalmin(A, degree - 1), d10(degree) * (A[degree]-1) + evalmax(B, degree - 1)));
			if (A[degree] + 1 <= 9)
				v.push_back(make_pair(d10(degree) * (A[degree]) + evalmax(A, degree - 1), d10(degree) * (A[degree]+1) + evalmin(B, degree - 1)));
			auto r = f(degree - 1);
			v.push_back(make_pair(d10(degree) * A[degree] + r.first, d10(degree) * A[degree] + r.second));
		}
		pair<long long, long long> res = v[0];
		for (int i = 1; i < v.size(); i++){
			if (abs(res.first - res.second) > abs(v[i].first - v[i].second)){
				res = v[i];
			}
			else{
				if (abs(res.first - res.second) == abs(v[i].first - v[i].second)){
					if (v[i].first < res.first || v[i].first == res.first && v[i].second <= res.second)
						res = v[i];
				}
			}
		}
		return res;
	}

}

void print(long long a, int len){
	vector<int> v;
	while (a != 0){
		v.push_back(a % 10);
		a /= 10;
	}
	while (v.size() < len)
		v.push_back(0);
	reverse(v.begin(), v.end());
	for (int i = 0; i < len; i++)
		cout << v[i];
}

void process(int t){
	string a, b;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	A.clear();
	B.clear();
	for (int i = 0; i < a.size(); i++){
		if (a[i] != '?')
			A.push_back(a[i] - '0');
		else
			A.push_back(-1);
		
		if (b[i] != '?')
			B.push_back(b[i] - '0');
		else
			B.push_back(-1);
	}
	cout << "Case #" << t << ": ";
	auto p = f(A.size() - 1);
	print(p.first, A.size());
	cout << " ";
	print(p.second, A.size());
	cout << "\n";

}

int main()
{
	freopen("d:\\acm\\CodeJam\\2016\\Round1B\\B\\B.in", "r", stdin);
	freopen("d:\\acm\\CodeJam\\2016\\Round1B\\B\\B.out", "w", stdout);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++){
		process(t + 1);
	}
	return 0;
}