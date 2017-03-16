#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <string>
#include <cstring>
#include <limits.h>

using namespace std;

#define push_back pb
#define fi first
#define se second
#define M_PI		3.14159265358979323846
#define forn(i, n) for(int i = 0; i < n; ++i)
typedef long long ll;
typedef long double ld;
typedef pair<int, double> pid;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;

ifstream fin("in.in");
ofstream fout("out1.out");
template<class T>
void printVec(vector<T> v){
    for(auto x : v)
        cout << x << ' ';
    cout << endl;
}
template<class T>
void print2DVec(vector<vector<T> > V){
    for(auto v : V)
        printVec<T> (v);
}
struct cmp{
    bool operator () (const pid &p1, const pid &p2){
        return p1.second > p2.second;
    }
};

int R, C, W;

int calc(int k, int w){
    if(k == w)
        return w;
    if(k >= 2 * w){
        return 1 + calc(k - w, w);
    }
    return 1 + w;
}

int solve(){
    fin >> R >> C >> W;
    int ans = 0;
    if(R > 1){
        ans += (R - 1) * (C / W);
    }
    return ans + calc(C, W);
}

int main(){
    int T;
    fin >> T;
    for(int tc = 1;tc <= T; ++tc){
        fout << "Case #" << tc << ": " << solve() << endl;
    }
}
