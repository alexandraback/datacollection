#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
// q.push(el);
// q.front(); q.pop(); 

#include <sstream>
// ostringstream buf;

#include <cstdio>
// sscanf(time.c_str(), "%d:%d:%d", &H, &M, &S);

#include <limits>
// std::numeric_limits<long long>::max();

#include <cctype>
// std::toupper(c)

typedef long long ll;

const int NN = 10000001;
std::vector<bool> visited(NN, false);
const ll mll = std::numeric_limits<long long>::max();
std::vector<ll>   nsteps (NN, mll);

std::vector<ll> n2d(ll n) {
    std::vector<ll> d;
    while (n>0) {
	d.push_back(n % 10);
	n /= 10;
    }
    return d;
}

ll d2n(const std::vector<ll>& d) {
    ll n = 0;
    ll p = 1;
    for (auto c : d) {
	n += c * p;
	p *= 10;
    }
    return n;
}

std::vector<ll> gen_next_list(ll v) {
    std::vector<ll> a;
    a.push_back(v + 1);

    auto d = n2d(v);
    std::reverse(std::begin(d), std::end(d));
    a.push_back( d2n(d));

    return a;
}

void bfs(ll pnum) {
    std::queue<ll> Q;
    Q.push(pnum);
    visited[pnum] = true;
    nsteps[pnum] = 1ll;

    ll nchecked = 0;

    while (!Q.empty()) {
	auto v = Q.front();
	Q.pop();
	for (auto w : gen_next_list(v)) {
	    if (w>=NN) continue;
	    if (visited[w]) continue;
	    nsteps[w] = nsteps[v] + 1;
	    nchecked ++ ;
	    visited[w] = true;
	    Q.push(w);
	}
    }
}


int main() {
    bfs(1);

    int T;
    std::cin >> T;
    for (int icase = 1; icase<=T; icase++) {
	int n;
	std::cin >> n;
	std::cout << "Case #" << icase << ": " << nsteps[n] << '\n';
    }
}
