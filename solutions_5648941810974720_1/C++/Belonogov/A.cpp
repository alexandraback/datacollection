#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = -1;
const long long INF = 1e9 + 19;

string s;
int cnt[200];
vector < pair < string, int > > data;

void read() {
    cin >> s;
    memset(cnt, 0, sizeof(cnt));
    for (auto x: s)
        cnt[x - 'A']++;
}

void solve() {
    vector < int > answer;
    for (auto x: data) {
        //
        //db(x.fr, x.sc)
        for (bool flag = 1;flag;) {
            //db2(x.fr, x.sc);
            //for (int i = 0; i < 26; i++)
                //cerr << cnt[i] << " ";
            //cerr << endl;


            for (auto ch: x.fr)
                flag &= cnt[ch - 'A'] >= 1;
            //db(flag);
            if (flag) {
                answer.pb(x.sc);
                for (auto ch: x.fr)
                    cnt[ch - 'A']--;
            }
        }
    }
    sort(answer.begin(), answer.end());
    for (auto x: answer)
        printf("%d", x);
    puts("");
}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    data.pb(mp("ZERO", 0));
    data.pb(mp("TWO", 2));
    data.pb(mp("SIX", 6));
    data.pb(mp("FOUR", 4));
    data.pb(mp("FIVE", 5));
    data.pb(mp("EIGHT", 8));
    data.pb(mp("THREE", 3));
    data.pb(mp("NINE", 9));
    data.pb(mp("ONE", 1));
    data.pb(mp("SEVEN", 7));

    
    if (1) {
        int k = 1;
        scanf("%d", &k);
        for (int tt = 0; tt < k; tt++) {
            printf("Case #%d: ", tt + 1); 
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}

