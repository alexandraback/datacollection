/**
* Change is impossible in this fog of ignorance.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <cmath>
using namespace std;

#define trace(x) {cerr << #x << "=" << x <<endl;}
#define trace2(x, y) {cerr << #x << "=" << x << " " << #y << "=" << y <<endl;}
#define track(x) {cerr << #x << ":" << endl; for (int q = 0; q < x.size(); q++) {cerr << x[q] << " ";} cerr << endl;}
#define trackarr(x, n) {cerr << #x << ":" << endl; for (int q = 0; q < n; q++) {cerr << x[q] << " ";} cerr << endl;}
#define trackvv(x) {cerr << #x << ":" << endl; for (int i = 0; i < x.size(); i++) { cerr << "i:" << i << endl; for (int j = 0; j < x[i].size(); j++){cerr << x[i][j] << " ";} cerr << endl;} cerr << endl;}
#define trackcr(x) {cerr << #x << ":" << endl; for (auto i = x.begin(); i != x.end(); i++) {cerr << *i << " ";} cerr << endl;}
template <typename Tk, typename Tv> ostream& operator<<(ostream& os, const pair<Tk, Tv> &p){os << "{" << p.first << ',' << p.second << "}";return os;}

typedef long long ll;

const int MAX = 100005;
const int MOD = 1000000000+7;
const int INF = 1000000000;

void inout() {
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);
}

char* toString(char temp[], int val, int n) {
    int size = 0;
    for (int i = 0; i < n; i++) {
        temp[size++]=val % 10 + '0';
        val /= 10;
    }
    temp[size]='\0';
    reverse(temp, temp+size);
    return temp;
}

bool compatible(char a[], char b[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i]=='?') continue;
        else {
            if (a[i] != b[i]) return false;
        }
    }
    return true;
}

void doTask() {
    char a[5], b[5];
    cin >> a >> b;
    int n = strlen(a);

    int maxVal = 0;
    for (int i = 0; i < n; i++) {
        maxVal *= 10;
        maxVal += 9;
    }
    //cout << "maxVal=" << maxVal << endl;

    char temp[2][5];
    int minDiff = INF;
    int Answer[2];
    for (int i = 0; i <= maxVal; i++) {
        for (int j = 0; j <= maxVal; j++) {
            if (compatible(a, toString(temp[0], i, n), n) && compatible(b, toString(temp[1], j, n), n)) {
                if (abs(i-j) < minDiff) {
                    minDiff = abs(i-j);
                    Answer[0]=i, Answer[1]=j;
                }
            }
        }
    }
    cout << toString(temp[0], Answer[0], n) << " " << toString(temp[1], Answer[1], n) << endl;
}

int main() {
    inout();
    int tc;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        cerr << t << endl;
        printf("Case #%d: ", t);
        doTask();
    }
}
