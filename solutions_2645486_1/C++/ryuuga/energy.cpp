#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,b) FOR(i,0,b)

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef pair<int, int> pii;


ll fast_solve() {
	int e, r;
	int n;

	cin >> e >> r >> n;
	r = min(r, e);

	vi v(n);
	REP(i,n)
		cin >> v[i];

#define gain first
#define i second
	vector<pii> choices;
	for(int i=0; i<n; i++) {
		choices.push_back(pii(v[i], i));
	}

	sort(choices.rbegin(), choices.rend());

	set<int> chosen;
	long long total = 0;
	for(const pii& choice: choices) {
		// there may be something which takes as much as possible before/after this
		const int i = choice.i;
		const ll gain = choice.gain;

		auto it = chosen.lower_bound(i);
		// a cap on how much is in position i
		ll cap = e;

		if(chosen.size() > 0) {
			if(it != chosen.begin()) {
				auto bit = it;
				bit--;
				const ll dx = i - *bit;
				//cerr << "dx=" << dx << endl;

				cap = min(cap, r * dx);
			}
		}

		int leave_amount;
		if(it == chosen.end())
			leave_amount = 0;
		else {
			const ll dx = *it - i;
			const ll regenerated = r * dx;
			leave_amount = max(ll(0), e - regenerated);
		}
		const ll take_amount = max((ll)0, cap - leave_amount);
		chosen.insert(i);
		total += take_amount * v[i];
		//cerr << i <<":" << v[i] << "\t" << cap << "\t" << leave_amount << "=\t" << take_amount << endl;
	}

	return total;
}

int main() {
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	REP(i,t) {
		cout << "Case #" << (i+1) << ": " << fast_solve() << endl;
	}
}
