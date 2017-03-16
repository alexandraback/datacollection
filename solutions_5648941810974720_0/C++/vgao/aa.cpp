#include <bits/stdc++.h>

using namespace std;

int F[256];

void init(const string & s)
{
	for (char c = 'A'; c <= 'Z'; ++c)
		F[c] = 0;
	for (char c : s)
		++F[c];
}

bool check(const char * s)
{
	while (*s)
		if (!F[*s++])
			return false;
	return true;
}

void take(const char * s, int x = 1)
{
	while (*s)
		F[*s++] -= x;
}

bool clear()
{
	for (char c = 'A'; c <= 'Z'; ++c)
		if (F[c])
			return false;
	return true;
}

const char * S[] = {
	"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX",
	"SEVEN", "EIGHT", "NINE"
};

vector<int> T;
bool search(int i)
{
	if (!check(S[i]))
		return false;
	take(S[i]);
	if (clear()) {
		T.push_back(i);
		return true;
	}
	for (int j = i; j < 10; ++j)
		if (search(j)) {
			T.push_back(i);
			return true;
		}
	take(S[i], -1);
}


int main()
{
	size_t n; cin >> n;
	for (size_t i = 0; i < n; ++i) {
		cout << "Case #" << i << ": ";
		
		string s; cin >> s;
		init(s);

		for (int x = 0; x < 10; ++x)
			if (search(x))
				break;
		while (!T.empty()) {
			cout << T.back();
			T.pop_back();
		}
		
		cout << endl;
	}
	return 0;
}
