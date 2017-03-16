#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef vector<int> Vint;
typedef vector<LL> VLL;

void printV(Vint& v)
{
	for (int i=0;i<v.size();i++) {
		printf("%d\n", v[i]);
	}
}

void solve()
{
	char S[1001];
	scanf("%s", S);
	string s(S);
	list<char> result;


	for (int i=0;i<s.length();i++) {
		if (result.empty()) {
			result.push_back(s[i]);
		} else {

			if (s[i] >= result.front()) {
				result.push_front(s[i]);
			} else {
				result.push_back(s[i]);
			}

		}
	}

	for (char x : result) {
		printf("%c", x);
	}
	printf("\n");
}

int main() 
{
	int T=0;
	scanf("%d", &T);
	for (int i=1;i<=T;i++) {
		printf("Case #%d: ", i);
		solve();
	}
	
	return 0;
}
