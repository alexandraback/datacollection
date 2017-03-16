#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <list>
#include <set>
#include <ctime>
#include <list>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define vi vector<int>
#define vd vector<double>
#define pii pair<int,int>
#define pdd pair<double,double>
#define ll long long
#define INF (1<<30)
using namespace std;

pair<char,int> mult(char a, char b) {
    if(a == '1') return mp(b, 1);
    if(b == '1') return mp(a, 1);
    if(a == b) return mp('1', 0);
    if(a == 'i') {
        if(b == 'j') return mp('k', 1);
        return mp('j', 0);
    }
    if(a == 'j') {
        if(b == 'i') return mp('k', 0);
        return mp('i', 1);
    }
    if(b == 'i') return mp('j', 1);
    return mp('i', 0);
}

void solve_case(int case_id)
{
    printf("Case #%d: ", case_id);
    int i, j, L, X;
    string s, A = "";
    int sg = 1;
    char cr = '1';
    cin >> L >> X;
    cin >> s;
    for(i = 0; i < X; ++i) A += s;
    pair<char, int> res;
    bool hasI = false, hasJ = false;
    for(i = 0; i < (int) A.length(); ++i) {
        res = mult(cr, A[i]);
        cr = res.x;
        if(res.y == 0) {
            sg = 1 - sg;
        }
        if(sg != 1) continue;
        if(!hasI) {
            if(cr == 'i') {
                hasI = true;
                cr = '1';
            }
        } else if(!hasJ) {
            if(cr == 'j') {
                hasJ = true;
                cr = '1';
            }
        }
    }
    if(hasI && hasJ && sg == 1 && cr == 'k') cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    int i, t;
    cin >> t;
    for(i = 1; i <= t; ++i) solve_case(i);
    return 0;
}
