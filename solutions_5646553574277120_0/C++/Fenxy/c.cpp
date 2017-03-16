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

ifstream fin("C-small-attempt2.in");
ofstream fout("out.out");
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

int C, D, V;
bool v[10000];
int m[5];

int solve(){
    fin >> C >> D >> V;
    memset(v, 0, sizeof(v));
    forn(i, D)
        fin >> m[i];
    for(int i = 1; i < 1 << D; ++i){
        int sum = 0;
        for(int j = 0; j < D; ++j){
            if(i & 1 << j){
                sum += m[j];
            }
        }
        v[sum] = true;
    }
    int ans = 0;
    bool flag = true;
    v[0] = true;
    while(flag){
        flag = false;
        for(int i = 1; i <= V; ++i){
            if(!v[i]){
                int p = i;
                ans += 1;
                for(int j = V; j >= 0; --j)
                if(v[j] && j + p <= V){
                    v[j + p] = true;
                }
                flag = true;
                break;
            }
        }
    }
    return ans;
}

int main(){
    int T;
    fin >> T;
    for(int tc = 1;tc <= T; ++tc){
        fout << "Case #" << tc << ": " << solve() << endl;
    }
}
