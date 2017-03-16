#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i(0); i < (int)(n); ++i)
#define for1(i, n) for (int i(1); i < (int)(n); ++i)
#define ford(i, n) for (int i((int)(n)); i >= 0; --i)
#define fore(i, a, b) for (int i((int)(a)), i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef	vector<pii> vpi;
typedef	vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

int main(){
	ofstream output;
	output.open("output.txt");
	ifstream input;
	input.open("A-large.in");

	int T(0);
	string word, last_word;
	input >> T;

	forn(i, T){
		last_word.erase();
		input >> word;
		forn(j, word.length()){
			if (last_word.empty())
				last_word.push_back(word[j]);
			else if (word[j] >= last_word[0])
				last_word.insert(last_word.begin(), word[j]);
			else
				last_word.push_back(word[j]);
		}
		output << "Case #" << i + 1 << ": " << last_word << endl;
	}

	return 0;
}

