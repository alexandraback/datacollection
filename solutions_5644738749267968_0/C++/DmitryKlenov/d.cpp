#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

vector<int> a, b;
int n;

int readNum() {
    char buf[8];
    scanf("%s", buf);
    return atoi(buf + 2);
}

int good(list<int> a, list<int> b) {
    int ans = 0;
    while(!a.empty()) {
        if (b.front() > a.front()) {
            b.pop_front();
            a.pop_back();
            ++ans;
        } else {
           b.pop_front();
           a.pop_front();
        }
    }
    return ans;
}

int cheat(list<int> a, list<int> b) {
    int ans = 0;
    while (!a.empty()) {
        if (b.back() > a.back()) {
            b.pop_back();
            a.pop_back();
            ++ans;
        } else {
            b.pop_back();
            a.pop_front();
        }    
    }
    return ans; 
}

void solveCase() {
    cin >> n;
    a.resize(n);
    b.resize(n);
    forn(i, n) b[i] = readNum();
    forn(i, n) a[i] = readNum();

    sort(all(b));
    sort(all(a));

    printf("%d %d\n", cheat(list<int>(allr(a)), list<int>(allr(b))), good(list<int>(allr(a)), list<int>(allr(b))));
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    int tk;
    scanf("%d", &tk);
    for(int tc = 1; tc <= tk; ++tc) {
        printf("Case #%d: ", tc);
        solveCase();
        cerr << "Case #" << tc << " is solved." << endl;
    }
    return 0;
}