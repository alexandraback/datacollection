#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <assert.h>
#include <math.h>
#include <iomanip>
#include <fstream>
using namespace std;

typedef long long ll;

#define f first
#define s second
#define mk make_pair
#define pii pair<int,int>

const int maxn = 5000 + 55;
const int maxd = 1000000;

int n;
int len;
char txt[maxn];
int dlen[maxd];
vector<string>dict;

void getDict() {
    ifstream in("dict.txt");
    int dx = 0;
    while (in.eof() == false) {
        string x; in >> x;
        dict.push_back(x);
        dlen[dx] = dict[dx].size();
        dx++;
    }
    dict.pop_back();
    n = dict.size();
}

int lastChange;
int diff(int pos, int w, int setWa = -10) {
    int wa = setWa;
    int cost = 0;

    for (int i = 0; i < dlen[w]; ++i) {
        if (txt[pos+i] != dict[w][i]) {
            cost ++;
            if (i - wa < 5) return -1;
            wa = i;
        }
    }
    lastChange = wa;
    return cost;
}

int mem[4000][10];

int solve(int dx, int backDiff) {
    int &ref = mem[dx][backDiff+5];
    if (ref != -1) return ref;
    if (dx == len) return 0;
    int rem = len - dx;
    ref = 1 << 29;
    for (int i = 0; i < n; ++i) {
        if (rem < dlen[i]) continue;
        int d;
        if ((d=diff(dx,i,backDiff)) == -1) continue;
        int newWa = dlen[i] - lastChange;
        if (newWa > 5)newWa = 5;
        int s = solve(dx + dlen[i], -newWa) + d;
        if (ref > s) ref = s;
    }
    return ref;
}

int main() {
    freopen("Ulaz.txt","r",stdin);
    freopen("Izlaz.txt","w",stdout);
    getDict();
    int tests; scanf("%d",&tests);
    for (int t = 1; t <= tests; ++t) {
        scanf("%s",txt);
        len = strlen(txt);
        memset(mem, -1, sizeof(mem));
        int sol = solve(0,-5);
        printf("Case #%d: %d\n",t,sol);
    }
    return 0;
}
