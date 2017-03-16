#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cstdio>
using namespace std;

const int N = 11000000;

int ver[N];
vector<long long> v;

void sol(int pas) {
	cout << "Case #" << pas << ": ";
	
	long long a, b;
	cin>> a >> b;
	
	cout << upper_bound(v.begin(), v.end(), b) - lower_bound(v.begin(), v.end(), a);
	
	cout << "\n";
}

bool ve(long long nu) {
	int cif[11], nr = 0;
	while(nu) {
		cif[++nr] = nu % 10;
		nu /= 10;
	}
	for(int i = 1; i <= nr; ++i)
		if(cif[i] != cif[nr - i + 1])
			return 0;
	return 1;
}

void calc() {
	int i;
	
	for(i = 1; i <= N; ++i)
		if(ve(i) && ve(1LL * i * i))
			v.push_back(1LL * i * i);
}

int main() {
	
	freopen("ttt", "r", stdin);
	freopen("tttt", "w", stdout);
	calc();
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i)
		sol(i);
	
	return 0;
}
