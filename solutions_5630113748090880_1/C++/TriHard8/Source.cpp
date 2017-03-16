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
	input.open("B-large.in");

	int T(0), N(0), num, max(0);
	vi count, vec;
	count.resize(2501);
		
	input >> T;

	forn(i, T){
		input >> N;
		vec.resize(0);
		forn(j, count.size())
			count[j] = 0;
		forn(j, 2*N - 1){
			forn(k, N){
				input >> num;
				count[num] += 1;
			}
		}
		forn(j, count.size()){
			if (count[j] % 2 != 0)
				vec.push_back(j);
		}
		output << "Case #" << i + 1 << ": ";
		forn(j, vec.size())
			output << vec[j] << " ";
			
		output << endl;
	}

	return 0;
}

