#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define PI acos(-1.0)
#define MP make_pair
#define PB push_back
#define SET(a,v) memset(a, v, sizeof(a))

#define VI vector <int>
#define PII pair <int, int>
#define LL long long 

#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,a,b) for (int i = a; i > b; i--)
#define FIT(it,v) for (typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define FITD(it,v) for (typeof(v.rbegin()) it = v.rbegin(); it != v.rend(); it++)
#define FALL(i,v) for (int i = 0; i < (v.size()); i++)

int n, s[25], s1[25], s2[25];
pair <int, PII> a[2000000], b[2000000];
int na, nb, flag;
map <int, int> f, g;

void attemp_1(int i, int ss1, int ss2, int sum) {
     if (i == 11) {
        if (ss1 + ss2 == 0) return;
        if (ss1 == 0 || ss2 == 0) {
           na++;
           a[na] = MP(sum, MP(ss1 + ss2, 0));        
        }      
        else {
             nb++;
             b[nb] = MP(sum, MP(ss1, ss2));     
        }
        return;
     }     
     
     attemp_1(i + 1, ss1, ss2, sum);
     attemp_1(i + 1, ss1 | (1 << (i - 1)), ss2, sum + s[i]);
     attemp_1(i + 1, ss1, ss2 | (1 << (i - 1)), sum -= s[i]);
}

void attemp_2(int i, int ss1, int ss2, int sum) {
     if (flag) return;
     if (i == 21) {
        if (ss1 + ss2 == 0) {
           if (g[0] != 0) {
              flag = 1;
              s1[0] = b[g[0]].second.first;
              s2[0] = b[g[0]].second.second;
           }
           return;
        }        
        if (ss1 == 0 || ss2 == 0) {
           if (f[sum]!= 0) {
              flag = 1;
              s1[0] = ss1 + ss2;
              s2[0] = a[f[sum]].second.first;             
           }        
           else if (g[sum]!= 0) {
                flag = 1;
                s1[0] = ss1 + ss2 + b[g[sum]].second.second;
                s2[0] = b[g[sum]].second.first;    
           }
           return;
        }     
        
        if (g[sum]!= 0) {
                flag = 1;
                s1[0] = ss1 + b[g[sum]].second.second;
                s2[0] = ss2 + b[g[sum]].second.first;    
           }
        else if (sum == 0) {
             flag = 1;
             s1[0] = ss1;
             s2[0] = ss2;     
        }
        return;
     }    
     attemp_2(i + 1, ss1, ss2, sum);
     attemp_2(i + 1, ss1 | (1 << (i - 1)), ss2, sum + s[i]);
     attemp_2(i + 1, ss1, ss2 | (1 << (i - 1)), sum -= s[i]); 
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int _;
    cin >> _;
    FOR (test, 1, _) {
        printf("Case #%d:\n", test);
        cin >> n;
        FOR (i, 1, n) cin >> s[i];
        na = 0;
        nb = 0;        
        attemp_1(1, 0, 0, 0);
        
        sort(a + 1, a + na + 1);
        sort(b + 1, b + nb + 1);
        
        f.clear();
        g.clear();
        FOR (i, 1, na) f[a[i].first] = i;
        FOR (i, 1, nb) g[b[i].first] = i;
        
        flag = 0;
        attemp_2(11, 0, 0, 0);
        if (!flag) printf("Impossible\n");
        else {
             s1[21] = s1[0];
             s1[0] = 0;
             FOR (i, 0, 19)
                 if (s1[21] & (1 << i)) s1[++s1[0]] = s[i + 1];
                 
             s2[21] = s2[0];
             s2[0] = 0;
             FOR (i, 0, 19)
                 if (s2[21] & (1 << i)) s2[++s2[0]] = s[i + 1];
                 
             FOR (i, 1, s1[0]) cout << s1[i] << " ";
             cout << endl;
             FOR (i, 1, s2[0]) cout << s2[i] << " ";
             cout << endl;           
        }
    }
    return 0;   
}
