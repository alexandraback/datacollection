#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <map>
#include <set>

using namespace std;

int main(int argc, char **argv)
{
        int T;
        cin >> T;
        for (int testcase = 0; testcase < T; testcase++) {
                int N;
                cin >> N;
                vector<string> s0(N), s1(N);
                set<string> d0, d1;
                for (int i = 0; i < N; i++) {
                        cin >> s0[i] >> s1[i];
                        d0.insert(s0[i]);
                        d1.insert(s1[i]);
                }
                int maxn = INT_MAX;
                for (int i = 0; i < 1<<N; i++) {
                        int n = 0;
                        set<string> q0, q1;
                        for (int j = 0; j < N; j++) {
                                if (i & (1<<j)) {
                                        q0.insert(s0[j]);
                                        q1.insert(s1[j]);
                                        n++;
                                }
                        }
                        if (q0.size() == d0.size() && q1.size() == d1.size()) {
                                if (n < maxn)
                                        maxn = n;
                        }
                }
                cout << "Case #" << testcase+1 << ": " << N - maxn << endl;
        }
        return 0;
}
