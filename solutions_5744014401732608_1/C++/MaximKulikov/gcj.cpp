#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <bitset>

using namespace std;

typedef vector <int> vi;
typedef vector<vi>	vvi;
typedef pair<int, int> ii;
typedef vector<ii>  vii;
typedef long long ll;
typedef vector<ll>  vll;

#define PROBLEM "B-large"

string pos = "POSSIBLE", impos = "IMPOSSIBLE";

void solve(const unsigned int b, long long m) {
    vll cnt(b, 0);
    vll mapp(b, 0);
    int i;
    cnt[b-1] = 1;
    for (i = b-2; i >= 0; --i) {
        long long n = 0, mask = 0;
        for (int j = i+1; j < b; ++j) {
            if (cnt[j] + n <= m) {
                n += cnt[j];
                mask += 1LL << (b-1-j);
            }
        }
        if (n < m) {
            cnt[i] = n;
            mapp[i] = mask;
        } else if (n == m) {
            cnt[0] = n;
            mapp[0] = mask;
            break;
        } else {
            cerr << "WTF";
            throw "WTF";
        }
    }
    if (cnt[0] != m) {
        cout << impos << endl;
    } else {
        cout << pos << endl;
        for (int i = 0; i < b; ++i) {
            for (int j = 0; j < b; ++j) {
                cout << (((mapp[i] & (1LL << (b-1-j))) == 0) ? '0' : '1');
            }
            cout << endl;
        }
    }
}

int main()
{
	freopen(PROBLEM ".in", "rt", stdin);
	freopen(PROBLEM ".out", "wt", stdout);

	int T;
	std::cin >> T;

	for (int t = 1; t <= T; ++t) {
        long long b, m;
        cin >> b >> m;
		std::cerr << "Case #" << t << ": " << endl;
		std::cout << "Case #" << t << ": ";
		solve(b, m);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
