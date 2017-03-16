#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

#include <cmath>

using namespace std;

typedef unsigned long long verylong;
typedef pair<verylong, int> el;

verylong f(const vector<el>& v, int type, int from, int to) {
    verylong c = 0;
    for (int i = from; i < to && i < v.size(); ++i)
        if (v[i].second == type)
            c += v[i].first;
    return c;
}

int main(int argc, char* argv[]) {
    int T = 0;
    cin >> T;

    for (int test = 1; test <= T; ++test) {
        int N, M;
        cin >> N >> M;

        vector<el> a;
        vector<el> b;
        for (int i = 0; i < N; ++i) {
            el e;
            cin >> e.first >> e.second;
            if (a.size() > 0 && e.second == a.back().second)
                a.back().first += e.first;
            else
                a.push_back(e);
        }
        for (int i = 0; i < M; ++i) {
            el e;
            cin >> e.first >> e.second;
            if (b.size() > 0 && e.second == b.back().second)
                b.back().first += e.first;
            else
                b.push_back(e);
        }

        verylong answer = 0;
        switch (a.size()) {
        case 1: {
            answer = min(a[0].first, f(b, a[0].second, 0, b.size()));
            break;
        }

        case 2: {
            for (int i = 0; i <= b.size(); ++i) {
                verylong c1 = min(a[0].first, f(b, a[0].second, 0, i));
                verylong c2 = min(a[1].first, f(b, a[1].second, i, b.size()));
                answer = max(answer, c1 + c2);
            }
            break;
        }

        case 3: {
            for (int i = 0; i <= b.size(); ++i) {
                for (int j = i; j <= b.size(); ++j) {
                    verylong c1 = min(a[0].first, f(b, a[0].second, 0, i));
                    verylong c2 = min(a[1].first, f(b, a[1].second, i, j));
                    verylong c3 = min(a[2].first, f(b, a[2].second, j, b.size()));
                    answer = max(answer, c1 + c2 + c3);
                }
            }

            if (a[0].second == a[2].second) {
                verylong c = min(a[0].first + a[2].first, f(b, a[0].second, 0, b.size()));
                answer = max(answer, c);
            }
            break;
        }
        }

        cout << "Case #" << test << ": " << answer << endl;
    }

    return 0;
}
