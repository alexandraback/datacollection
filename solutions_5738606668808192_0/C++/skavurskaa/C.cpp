#include <bits/stdc++.h>
using namespace std;

// any number with odd amount of 1's in even indexes and all 0's in odd indexes (except last index) is even in any base from 2 to 10
// so just generate enough numbers with this property
map<string,vector<long long>> used;
vector<long long> v;
int T,N,J;

long long fact(long long N)
{
	long long sqr = sqrt(N);
	for (int i = 2; i <= sqr; i++)
		if (N%i==0) return i;
	return -1;
}

string genRandomSolution()
{
	v.clear();
	string s;
	s += '1';
	for (int i = 0; i < N-2; i++)
	{
		if (rand()%2) s += '1';
		else s += '0';
	}
	s += '1';
	if (used.find(s) != used.end()) return genRandomSolution();
	for (int i = 2; i <= 10; i++)
	{
		long long x = fact(strtoll(s.c_str(),NULL,i));
		if (x == -1) return genRandomSolution();
		else v.push_back(x);
	}
	return s;
}

int main()
{
	srand(time(NULL));
	cin >> T >> N >> J;
	printf("Case #1:\n");
	while (used.size() != J)
	{
		string s = genRandomSolution();
		used[s] = v;
	}
	for (auto s : used)
	{
		cout << s.first;
		for (auto n : s.second)
			cout << " " << n;
		cout << endl;
	}
}
