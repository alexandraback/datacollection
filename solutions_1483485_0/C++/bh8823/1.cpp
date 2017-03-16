#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define PI 3.141592653589793238462643
#define MOD 1000000009
#define eps 1e-8
const int inf = 1000000005;
const int dr[]={0,1,0,-1,1,1,-1,-1};
const int dc[]={1,0,-1,0,1,-1,1,-1};

typedef long long ll;
typedef vector<int> vi; 
typedef vector<vi> mat; 
typedef pair<int,int> pii;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n) 
#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define mp make_pair

char mapping[26] = {'y', 'h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
char S[101];

char decode(char c) {
	int ind = c - 'a';
	return mapping[ind];
}

int main() {
	int T, N, M;
	cin >> T;
	cin.getline(S, 101);
	int loop = 1;
	
	
	
	while (loop <= T) {
		cin.getline(S, 101);
		//cout << mapping[0] << mapping[25] << endl;
		int i = 0;
		char c;
		while ( (c = S[i]) != '\0') {
			if (c != ' ') {
				S[i] = decode(c);
			}
			i++;
		}
		cout << "Case #" << loop << ": ";
		cout << S << endl; 
		loop++;
	}

	return 0;
}