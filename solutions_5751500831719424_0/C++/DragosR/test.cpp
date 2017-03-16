#include <cstdio>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <string>
#include <set>
#include <stack>
#define pb push_back

#define mp make_pair
#define f first
#define s second
#define ll long long

using namespace std;

int main() {
    ifstream cin("test.in");
    ofstream cout("test.out");

    int T; cin >> T;

    for (int tcase = 1; tcase <= T; ++tcase) {
        int N; cin >> N;

        int error = 0;

        vector <string> v(N);
        for (int i = 0; i < N; ++i)
            cin >> v[i];

        vector <int> p(N, 0);
        vector <vector <int> > groups(N, vector <int>());

        for (int k = 0; k < v[0].size(); ++k) {
            if (k > 0) {
                if (v[0][k] == v[0][k - 1]) {
                    continue;
                }
            }

            for (int i = 0; i < N; ++i) {
                int nr = 0;
                while(v[i][p[i] + nr] == v[0][k] && p[i] + nr < v[i].size()) {
                    nr += 1;
                }
                error |= (nr == 0);
                groups[i].push_back(nr);

                p[i] += nr;
            }
        }
        for (int i = 0; i < N; ++i) {
            if (p[i] != v[i].size()) {
                error |= 1;
            }
        }

        cout << "Case #" << tcase << ": ";
        if (error) {
            cout <<"Fegla Won\n";
            continue;
        }

        int m = groups[0].size();

        int answer = 0;

        for (int k = 0; k < m; ++k) {
            int min_cost = 1 << 30;
            for (int quant = 0; quant <= 300; ++quant) {
                int cost = 0;
                for (int i = 0; i < N; ++i) {
                    if (groups[i][k] == 0 && quant > 0) {
                        cost = 1 << 30;
                        break;
                    }
                    if (groups[i][k] > 0 && quant == 0) {
                        cost = 1 << 30;
                        break;
                    }
                    cost += abs( quant - groups[i][k] ) ;
                }
                min_cost = min(min_cost, cost);
            }
            answer += min_cost;
        }
        cout << answer << "\n";

    }
    return 0;
}

