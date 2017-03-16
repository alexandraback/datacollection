#pragma comment (linker, "/STACK:64000000")
#include <memory.h>
#include <cstdio> 
#include <sstream> 
#include <iostream> 
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <cstring>
#include <list>
#include <cmath>

using namespace std;

typedef long long lint;
#define pb push_back
#define sz(a) (int)((a).size())


void prepare(string s){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen((s + ".in").c_str(), "r", stdin); 
	freopen((s + ".out").c_str(), "w", stdout);
#endif
}

map<char, char> m;
set<char> all;

char s[1000];
char t[1000];

bool solve(){
	for (int j= 0; j < 3; ++ j)
	{
		fgets(s, 100000, stdin);
		fgets(t, 100000, stdin);

		for (int i=  0; s[i]; ++ i)
		{
			m[s[i]] = t[i];
			all.insert(t[i]);
		}
	}
	m['z'] = 'q';
	m['q'] = 'z';
	//m;
	int n;
	scanf("%d\n", &n);
	for (int j= 0; j < n; ++ j)
	{
		fgets(s, 100000, stdin);
		//fgets(t, 100000, stdin);
		cout << "Case #" << j + 1  << ": ";
		for (int i=  0; s[i]; ++ i)
		{
			cout << m[s[i]];
		}
	}
	return false;
}

int main(){

	prepare("problema");
	while (solve());



	return 0;
}