#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <string>
#include <queue>
#include <fstream>
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FR(i,a) for(int i = 0; i < (a); i++)
#define DR(i,a) for(int i = (a)-1; i >=0; i--)
#define DOWN(i,a,b) for(int i = (a); i >= (b); i--)
#define FORD(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define sqr(x) ((x)*(x))
#define oo 1000000009
using namespace std;
char t[1000100];
string s,p;
map<char,bool> Map;
int K;
int main() {
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    int ntest;
    cin >> ntest;
    gets(t);
    Map['a'] = true;
    Map['e'] = true;
    Map['i'] = true;
    Map['o'] = true;
    Map['u'] = true;
    FOR(test,1,ntest) {
        cout << "Case #" << test << ": ";
        gets(t);
        p = string(t);
        istringstream iss(p);
        iss >> s >> K;
        int n = s.size();
        int cur = 0;
        long long res = 0;
        bool ok = false;
        int start = -1;
        FR(i,n) {
            if (!Map[s[i]]) cur++;
            else cur = 0;
            if (cur >= K) {
                ok = true;
                start = i - K + 1;
            }
            if (ok) res += (start + 1);
        }
        cout << res << endl;
    }
    return 0;
}
