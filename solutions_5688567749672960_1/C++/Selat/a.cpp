#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

ull toNumber(const vector <int> &a)
{
	ull res = 0;
	for(int i = (int)a.size() - 1; i >= 0; --i) {
		res = res * 10 + a[i];
	}
	return res;
}

vector <int> toVector(ull n)
{
	vector <int> a;
	a.clear();
	while(n > 0) {
		a.push_back(n % 10);
		n /= 10;
	}
	if(a.empty()) {
		a.push_back(0);
	}
	return a;
}

bool powerOfTen(const vector <int> &a)
{
	bool ok = (a[a.size() - 1] == 1);
	for(int i = 0; (i + 1 < a.size()) && ok; ++i) {
		if(a[i] != 0) {
			ok = false;
		}
	}
	return ok;
}

ull stepsNum(ull n)
{
	if(n <= 9ull) {
		return n;
	}
	vector <int> a = toVector(n);
	if(a[a.size() - 1] == 1) {
		if(powerOfTen(a)) {
			return 1 + stepsNum(n - 1);
		}
	}
	if(a[0] == 0) {
		return 1 + stepsNum(n - 1);
	}

	int mid_id = (a.size() + 1) / 2 - 1;
	vector <int> left_part(a.begin() + mid_id + 1, a.end());
	vector <int> right_part(a.begin(), a.begin() + mid_id + 1);
	ull res = toNumber(right_part);
	if(!powerOfTen(left_part)) {
		reverse(left_part.begin(), left_part.end());
		res += toNumber(left_part);
	}
	++res;

	vector <int> b(a.size() - 1);
	for(int i = 0; i < b.size(); ++i) {
		b[i] = 9;
	}
	res += stepsNum(toNumber(b));
	return res;
}

int main()
{
	int t;
	ull n;
	cin >> t;
	for(int i = 1; i <= t; ++i) {
		cin >> n;
		cout << "Case #" << i << ": " << stepsNum(n) << endl;
	}
	return 0;
}
