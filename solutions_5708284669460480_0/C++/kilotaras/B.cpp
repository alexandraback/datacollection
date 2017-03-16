//#pragma comment(linker, "/stack:1000000")

#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>

using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)

#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define ABS(A) ((A) < 0 ? (-(A)) : (A))
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()
#define pb push_back
#define mp make_pair
#define MP make_pair
const double EPS=1e-7;
const double Pi=acos(-1.0);
#define FILL(a,v) memset(a,v,sizeof(a))
#define INF 1000000000

typedef long long Long;
typedef unsigned long long ULong;
typedef unsigned int Uint;
typedef unsigned char Uchar;
typedef vector <int> VI;
typedef pair <int, int> PII;

vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

#define FOR_LETTER(x) for(char x = 'A'; x<='Z'; ++x)

string S, T;
int n;
int len;

int g[200][256];


double res;

vector<double> probs;
vector<double> moves;

void init() {
	len = S.length();
	n = S.length()+1;
	FILL(g,0);

	FOR(i,0,n) {
		string prefix = S.substr(0, i);
		FOR_LETTER(c) {
			string next = S + '$' + prefix + c;
			int next_pos = prefix_function(next).back();

			g[i][c] = next_pos;
		}
	}

	probs.clear();
	probs.resize(n, 0);
	probs[0] = 1;

	moves.clear();
	moves.resize(256, 0);

	double p = 1.0/T.size();
	REP(i, T.size())
	{
		moves[T[i]] += p;
	}
}

int get_max(int l) {
	REP(j, S.length()) {
		bool was = false;
		REP(i, T.length()) 
			if (T[i] == S[j])
				was = true;
		if (!was)
			return 0;
	}

	if (l < len)
		return 0;
	int pr = prefix_function(S).back();
	int left = len-pr;
	
	return (l-len)/left + 1;
}

void move_once() {
	vector<double> next_p(n, 0);
	REP(i,n)
		FOR_LETTER(move) {
			int next_pos = g[i][move];
			double m_prob = moves[move];
			double prob = probs[i]*m_prob;

			next_p[next_pos] += prob;
		}
	/*REP(i,n)
		cout<< probs[i] << " ";*/
	//cout<<endl;
	res -= next_p[len];
	
	probs = next_p;
}

int main(int argc, char** argv)
{
//	freopen("gazmyas.in","r",stdin);
//  freopen("gazmyas.out","w",stdout);
	int t;
	cin>>t;
	//t = 100;
	REP(tt, t) {
		int k,l,s;
	
		cin >> k >> l >> s >> T >> S;
	
		init();
		res = get_max(s);
		REP(i, s)
			move_once();
		
		printf("Case #%d: %.9lf\n", tt+1, res);
	}
	return 0;}