#include "iostream"
#include "algorithm"
#include "vector"
#include "set"
#include "map"
#include "cstring"
#include "string"
#include "vector"
#include "cassert"
#include "queue"
#include "cstdio"
#include "cstdlib"
#include "ctime"
#include "cmath"
#include "bitset"

using namespace std;

typedef long long ll;
typedef pair < int, int > ii;

const int N = 2000 + 5;

char s[N];
int cnt[26];
string str[10];

bool pos(int x) {
    for(auto i : str[x])
        if(!cnt[i - 'A'])
            return 0;
    return 1;
}

vector < int > buf;

void get(int x) {
    buf.push_back(x);
    for(auto i : str[x])
        cnt[i - 'A']--;
}

void solve() {
    buf.clear();
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= n; i++)
        cnt[s[i] - 'A']++;
    while(pos(0)) get(0);
    while(pos(4)) get(4);
    while(pos(2)) get(2);
    while(pos(1)) get(1);
    while(pos(3)) get(3);
    while(pos(8)) get(8);
    while(pos(5)) get(5);
    while(pos(6)) get(6);
    while(pos(7)) get(7);
    while(pos(9)) get(9);
    sort(buf.begin(), buf.end());
    for(auto x : buf)
        printf("%d", x);
    puts("");
}

int main () {
    
    freopen("A-large.in.txt", "r", stdin);
    freopen("big.txt", "w", stdout);
    
    str[0] = "ZERO";
    str[1] = "ONE";
    str[2] = "TWO";
    str[3] = "THREE";
    str[4] = "FOUR";
    str[5] = "FIVE";
    str[6] = "SIX";
    str[7] = "SEVEN";
    str[8] = "EIGHT";
    str[9] = "NINE";
    
    int n;
    
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++) {
        printf("Case #%d: ", i);
        solve();
    }
    
    return 0;
    
}