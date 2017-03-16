#define print(x) cerr << #x << " = " << toStr(x) << endl;
// -Wl,--stack,9001 
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz(x) ((int)((x).size()))
#define rep(i, N) for (int i = 0; i < N; ++i)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
typedef long long lint;
typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> pii;
template<class T> string toStr(T x){stringstream ss;ss<< x; return ss.str(); } 
template<class T1,class T2>string toStr(pair<T1,T2>x){return toStr(x.first)+": "+toStr(x.second);}
template<class T> string containerToStr(T v) { string r = "["; foreach (it, v) { if (r != "[") r += ", "; r += toStr(*it); } return r + "]";}
template<class T> string toStr(vector<T>v){return containerToStr(v);} 
template<class T> string toStr(set<T> v) {return containerToStr(v);} 
template<class T1,class T2>string toStr(map<T1,T2>v){return containerToStr(v);}


int A[100];
int N;
int Ans[1000][11];
int A1[1000][100];
int curJ = 0;
int J;

void check() {
    int cnt = 0;

    for (int b = 2; b <= 10; ++b) {
        int d1 = -1;
        for (int d = 3; d <= 100; d += 2) {            
            lint cum = 1;
            lint sum = 0;
            for (int i = 0; i < N; ++i) {
                if (A[i]) {
                    sum += cum;
                    sum %= d;
                }
                cum = cum * b;
                cum = cum % d;
            }     
            if (sum == 0) {
                d1 = d;
                break;
            }
        }
        if (d1 != -1) {
            Ans[curJ][b] = d1;
            ++cnt;
        }
    }

    if (cnt == 9) {
        for (int i = 0; i < N; ++i) {
            A1[curJ][i] = A[i];
        }
        ++curJ;
    } 

    
}


void rec(int k) {
    if (curJ == J) {
        return;
    }
    if (k == N) {
        check();
    } else {
        if (k != N - 1) {
            A[k] = 0;
            rec(k + 1);    
        }
        A[k] = 1;
        rec(k + 1);
    }
}


void solve(int num) {
    cin >> N >> J;
    A[0] = 1;
    rec(1);
    printf("Case #%d:\n", num);
    for (int j = 0; j < curJ; ++j) {
        for (int i = 0; i < N; ++i) {
            printf("%d", A1[j][N - i - 1]);
        }
        for (int b = 2; b <= 10; ++b) {
            printf(" %d", Ans[j][b]);
        }
        printf("\n");
    }
    //cout << curJ << " " << J << endl;
}

bool verify(int ans[], int a[]) {
    for (int b = 2; b <= 10; ++b) {
        int d = ans[b];
        lint cum = 0;
        for (int i = N - 1; i >= 0; --i) {
            cum = cum * b + a[i];
            cum %= d;
        }
        if (cum != 0) {
            return false;
        }
    }
    return true;
}

bool verify() {
    for (int j = 0; j < curJ; ++j) {
        if (!verify(Ans[j], A1[j])) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        solve(i);
    }

//    cout << verify() << endl;

    return 0;
}
