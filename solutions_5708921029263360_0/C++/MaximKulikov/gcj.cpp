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

#define PROBLEM "C-small-attempt0"

void solve(int j, int p, int s, int k) {
    vi used(64, 0);
    vector <vi> out;
    out.reserve(64);
    int N = 0;
    for (int a = 1; a <= j; ++a) {
        for (int b = 1; b <= p; ++b) {
            for (int c = 1; c <= s; ++c) {
                int ab = a * 16 + b * 4;
                int ac = a * 16 + c;
                int bc = b * 4 + c;
                //cerr << a << " " << b << " " << c << endl;
                //cerr << used[ab] << " " << used[ac] << " " << used[bc] << endl << endl;
                if (used[ab] < k && used[ac] < k && used[bc] < k) {
                    ++N;
                    vi o(3);
                    o[0] = a;
                    o[1] = b;
                    o[2] = c;
                    out.push_back(o);
                    used[ab]++;
                    used[ac]++;
                    used[bc]++;
                }
            }
        }
    }
    cout << N << endl;
    for (int i = 0; i < out.size(); ++i) {
        cout << out[i][0] << " " << out[i][1] << " " << out[i][2] << endl;
    }
}

int main()
{
	freopen(PROBLEM ".in", "rt", stdin);
	freopen(PROBLEM ".out", "wt", stdout);

	int T;
	std::cin >> T;

	for (int t = 1; t <= T; ++t) {
        int j, p, s, k;
        cin >> j >> p >> s >> k;
		std::cerr << "Case #" << t << ": " << endl;
		std::cout << "Case #" << t << ": ";
		solve(j, p, s, k);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
