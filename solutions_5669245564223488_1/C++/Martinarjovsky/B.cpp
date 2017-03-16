#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <utility>
using namespace std;

ifstream fin ("B.in");
ofstream fout ("B.out");
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define pb push_back
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define abs(x) ((x)<0 ? -(x) : (x))
#define MODRES 1000000007

ll fact(ll a) {
	if (a == 0) return 1;
	else return ((fact(a-1)*a) % MODRES);
}

int main() {

	ll T, c, N, i, j;
	fin >> T;
	vector<ll> middle;
	vector<string> trains;
	vvll E, tE;
	vvll parent, tparent;
	string S;
	set<char> A;
	vll visited;
	bool consec, isdif;
	bool badchain;
	for (c = 1; c <= T; c++) {
		trains.clear();
		middle.clear();
		E.clear();
		tparent.clear();
		parent.clear();
		tE.clear();
		visited.clear();
		tparent.resize(26, vll(0));
		parent.resize(26, vll(0));
		tE.resize(26, vll(0));
		E.resize(26, vll(0));
		middle.resize(26, 0);
		visited.resize(26, 0);
		fin >> N;
		for (i = 0; i < N; i++) {
			fin >> S;
			trains.pb(S);
		}
		consec = true;
		for (i = 0; i < N; i++) {
			S = trains[i];
			A.clear();
			for (j = 0; j < sz(trains[i]); j++) {
				if (A.count(S[j]) == 0) A.insert(S[j]);
				else if (S[j-1] != S[j]) {
					consec = false;
					break;
				}
			}
			if (!consec) break;
		}

		if (!consec) {
			fout << "Case #" << c << ": " << 0 << endl;
			continue;
		}

		for (i = 0; i < N; i++) {
			isdif = false;
			S = trains[i];
			for (j = 1; j < sz(S); j++) {
				if (S[j] != S[j-1]) isdif = true;
			}
			if (!isdif) middle[(int) S[0] - (int) 'a']++;
		}
		for (i = 0; i < N; i++) {
			S = trains[i];
			for (j = 1; j < sz(S); j++) {
				if (S[j-1] != S[j]) {
					E[(int) S[j-1] - (int) 'a'].pb((int) S[j] - (int) 'a');
					parent[(int) S[j] - (int) 'a'].pb((int) S[j-1] - (int) 'a');
					tparent[(int) S[j] - (int) 'a'].pb(i);
					tE[(int) S[j-1] - (int) 'a'].pb(i);
				}
			}
		}
		badchain = false;
		for (i = 0; i < 26; i++) {
			if (sz(E[i]) > 1) badchain = true;
			if (sz(parent[i]) > 1) badchain = true;
			if (sz(parent[i]) == 1 && sz(E[i]) == 1) if(tE[i][0] == tparent[i][0] && middle[i] > 0) badchain = true;
		}
		if (badchain) {
			fout << "Case #" << c << ": " << 0 << endl;
			continue;
		}

		ll act;
		for (i = 0; i < 26; i++) {
			if (visited[i] == 1) continue;
			act = i;
			visited[act] = 1;
			while (sz(E[act]) == 1) {
				act = E[act][0];
				if (visited[act] == 1) {
					badchain = true;
					break;
				}
				visited[act] = 1;
			}
			if (badchain) break;
			act = i;
			while (sz(parent[act]) == 1) {
				act = parent[act][0];
				if (visited[act] == 1) {
					badchain = true;
					break;
				}
				visited[act] = 1;
			}
			if (badchain) break;
		}
		if (badchain) {
			fout << "Case #" << c << ": " << 0 << endl;
			continue;
		}

		ll chains = 0;
		ll res = 1;
		for (i = 0; i < 26; i++) {
			res *= fact(middle[i]);
			res %= MODRES;
			if (sz(parent[i]) == 0 && (middle[i] > 0 || sz(E[i]) > 0)) chains++;
		}
		res *= fact(chains);
		res %= MODRES;


		fout << "Case #" << c << ": " << res << endl;




	}

	return 0;
}
