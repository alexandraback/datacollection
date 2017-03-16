#include <iostream>
#include <cstring>
#include <stdexcept>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 10000000;
int d[N + 5];
int fr[N + 5];

long long flip(long long x) {
    long long ret = 0;
    for (;x; x/=10)
        ret = ret*10 + x%10;
    return ret;
}

vector<long long> path(long long x) {
    vector<long long> path;
    while (x != 1) {
        path.push_back(x);
        x = fr[x];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    vector<long long> ret;
    long long prv = -1;
    for (const long long g : path) {
        if (g != prv + 1)
            ret.push_back(g);
        prv = g;
    }
    return ret;
}

void printpath(vector<long long>& path) {
    for (const int g : path) {
        cerr << g << ' ';
    }
    cerr << endl;
}

long long gen[17] = {0, 1, 91};
long long ten[17] = {1};

long long fast(long long x) {
    long long ret = 0;

    vector<long long> path{0};
    for (int i=1; i<=15; ++i) {
        if (gen[i] <= x) {
            path.push_back(gen[i]);
        } else {
            break;
        }
    }
    int length = 0;
    for (long long tmp=x; tmp; tmp /= 10) {
        ++length;
    }

    length /= 2;
    path.push_back((x-1) / ten[length] * ten[length] + 1);
    path.push_back(x);

    /*
    cerr << "fast for " << x << endl;
    for (const long long g : path)
        cerr << g << ' ';
    cerr << endl;
    */

    for (size_t i=1; i<path.size(); ++i) {
        long long cur = path[i] - path[i-1];
        long long fl = flip(path[i]);
        if (fl < path[i]) {
            if (fl > path[i-1]) {
                cur = min(cur, fl - path[i-1] + 1);
            }
        }
        ret += cur;
    }

    return ret;
}

int main() {
    for (int i=1; i<=16; ++i)
        ten[i] = ten[i-1] * 10;

    for (int i=3; i<=16; ++i) {
        if (i % 2 == 1) {
            gen[i] = gen[i-1] + ten[i-1] * 9;
        } else {
            gen[i] = gen[i-1] * 10 - 9;
        }
    }

    for (int i=1; i<=15; ++i)
        cerr << gen[i] << ' ';
    cerr << endl;

    memset(d, 0x7f, sizeof d);
    d[1] = 1;
    for (int i=1; i<=N; ++i) {
        if (i % 1000000 == 0) {
            cerr << "done " << i << endl;
        }

        if (d[i] + 1 < d[i+1]) {
            d[i+1] = d[i] + 1;
            fr[i+1] = i;
        }

        long long fl = flip(i);
        if (fl < i) {
            if (d[fl] > d[i] + 1) {
                throw logic_error("oh no no no");
            }
        }

        if (d[i] + 1 < d[fl]) {
            d[fl] = d[i] + 1;
            fr[fl] = i;
        }
    }

    for (int i=1; i<=N; ++i) {
        if (i % 1000000 == 0) {
            cerr << "check " << i << endl;
        }
        if (d[i] != fast(i)) {
            cerr << "Fail: " << d[i] << ' ' << fast(i) << endl;
        }
    }

    //for (int i=1; i<10001; ++i) {
        //cerr << i << ": ";
        //printpath(i);
    //}

    /*
    vector<int> prv;
    for (int i=1; i<=10000000; ++i) {
        vector<int> pa = path(i);
        if (pa != prv) {
            //cerr << "not equal" << endl;
            //cerr << "--: "; printpath(prv);
            //cerr << "++: "; printpath(pa);
            cerr << i << ": "; printpath(pa);
        }
        prv = std::move(pa);
    }
    */

    //return 0;
    int t; cin >> t;
    for (int e=1; e<=t; ++e) {
        long long x; cin >> x;
        cout << "Case #" << e << ": " << fast(x) << endl;
    }

    return 0;
}



