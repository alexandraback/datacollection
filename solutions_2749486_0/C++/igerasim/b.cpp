#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <hash_map>
#include <map>

using namespace std;
using namespace stdext;

typedef __int64 ll;
typedef unsigned __int64 ull;

int T;
pair<ll, ll> to; // Y, X



string solve() {
	map<pair<ll, ll>, string> poses;
	poses[pair<ll, ll>(0, 0)] = string("");

	for (int j = 1; true; ++j) {
		map<pair<ll, ll>, string> poses1;
		for (map<pair<ll, ll>, string>::iterator it = poses.begin(); it != poses.end(); ++it) {
			const pair<ll, ll>& key = it->first;
			const string& val = it->second;
			pair<ll, ll> key1;
			key1 = make_pair(key.first - j, key.second);
			poses1[key1] = val + "S"; if (key1 == to) return poses1[key1];

			key1 = make_pair(key.first + j, key.second);
			poses1[key1] = val + "N"; if (key1 == to) return poses1[key1];

			key1 = make_pair(key.first, key.second + j);
			poses1[key1] = val + "E"; if (key1 == to) return poses1[key1];

			key1 = make_pair(key.first, key.second - j);
			poses1[key1] = val + "W"; if (key1 == to) return poses1[key1];
		}
		poses1.swap(poses);
	}
	return "";
}

int main(int argc, char* argv[]) {
    cin >> T;
    for (int t_ = 0; t_ != T; ++t_) {
		cin >> to.second >> to.first;

        cout << "Case #" << (t_ + 1) << ": " << solve() << "\n";
    }
    return 0;
}
