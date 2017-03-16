#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
#include <cassert>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for(__typeof__((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define mp make_pair
#define pb push_back
typedef struct node {
	double left, right;
	node * l, * r, *m;
	ll height;
	node(): l(0), r(0) {}
} node;

node * head;
typedef struct tribe {
	int fd;
	int dd;
	ll left, right;
	int n;
	ll dp;
	int ds;
	int str;
} tribe;

void kill(node * n) {
	if (n == NULL) return;
	kill(n->l);
	kill(n->r);
	kill(n->m);
	delete n;
}

bool su(tribe * t, node * n) {
	assert(n != NULL);
	if (n->height >= 0) {
		if (n->height < t->str) return true;
		else return false;
	}
	// split up
	bool b1 = false, b2 = false, b3 = false;
	if (n->l && t->left <= n->l->right) b1 = su(t, n->l);
	if (n->m && t->left <= n->m->right && t->right >= n->m->left) b2 = su(t, n->m);
	if (n->r && t->right >= n->r->left) b3 = su(t, n->r);
//	cout << "Node from " << n->left << " bis " << n->right << " succeeding: " << b1 << b2 << b3 << " | " << (n->l && b1) << (n->m && b2) << (n->r && b3) <<endl;
//	return (n->l && b1) || (n->m && b2) || (n->r && b3);
	return b1 || b2 || b3; 	
}

void reb(tribe * t, node * n) {
	assert(n != NULL);
	if (n->height >= 0) {
		if (n->height < t->str) {
			n->m = new node();
			n->m->left = t->left - 0.1;
			n->m->right = t->right + 0.1;
			n->m->height = t->str;
			n->m->l = n->m->r = n->m->m = NULL;
			
			if (t->left > n->left) {
				n->l = new node();
				n->l->left = n->left;
				n->l->right = t->left-0.9;
				n->l->height = n->height;
				n->l->l = n->l->r = n->l->m = NULL;
			}
			if (t->right < n->right) {
				n->r = new node();
				n->r->left = t->right+0.9;
				n->r->right = n->right;
				n->r->height = n->height;
				n->r->l = n->r->r = n->r->m = NULL;
			}
			n->height = -1;
		}
		return;
	}
	// split up
	if (n->l && t->left <= n->l->right) reb(t, n->l);
	if (n->m && t->left <= n->m->right && t->right >= n->m->left) reb(t, n->m);
	if (n->r && t->right >= n->r->left) reb(t, n->r);
}

void update(tribe * t) {
	t->fd += t->dd;
	t->str += t->ds;
	t->left += t->dp;
	t->right += t->dp;
	t->n--;
}
class Compare {
public:
	bool operator()(const pii & a, const pii & b) {
		if (a.first != b.first) return a.first > b.first;
		return a.second > b.second;
	}
};
int main() {
	int tc;
	cin >> tc;
	FOR(t, 1, tc+1) {
		head = new node();
		head->left = LONG_MIN;
		head->right = LONG_MAX;
		head->height = 0;
		
		int N;
		cin >> N;
		vector<tribe> tr(N);
		priority_queue<pair<int, int>, vector<pii>, Compare > qu;
		FOR(i, 0, N) {
			cin >> tr[i].fd >> tr[i].n >> tr[i].left >> tr[i].right >> tr[i].str >> tr[i].dd >> tr[i].dp >> tr[i].ds;
			qu.push(mp(tr[i].fd, i));
		}
		ll succ = 0;
		while(!qu.empty()) {
			int cD = qu.top().first;
			bool suc = false;
			vi rebuild;
			while(qu.size() > 0 && qu.top().first == cD) {
				tribe * cT = &tr[qu.top().second];
//				cout << "Attacking Day: " << cD << ", Tribe: " << qu.top().second << ", left: " << cT->left << ", right: " << cT->right << endl;
				if (su(cT, head)) {
//					cout << "Succ##### Day: " << cD << ", Tribe: " << qu.top().second << ", left: " << cT->left << ", right: " << cT->right << endl;
					suc = true;
					succ++;
					rebuild.pb(qu.top().second);
				} else {
					update(cT);
//					cout << "Day " << cD << ", Tribe " << qu.top().second << ", n = " << cT->n << endl;
					if (cT->n > 0) qu.push(mp(cT->fd, qu.top().second));
				}
				qu.pop();
			}
//			if (suc) succ++;
			FOR(i, 0, rebuild.size()) {
				reb(&tr[rebuild[i]], head);
				update(&tr[rebuild[i]]);
				if (tr[rebuild[i]].n > 0) qu.push(mp(tr[rebuild[i]].fd, rebuild[i]));
			}
		}
		kill(head);
		cout << "Case #" << t << ": " << succ << endl;
	}
	return 0;
}
