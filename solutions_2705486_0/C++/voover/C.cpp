#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <complex>
#include <sstream>
using namespace std;
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define SIZE(c) ((int)((c).size()))
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)
#define ALL(v) (v).begin(), (v).end()
 
#define pb push_back
#define mp make_pair
#define st first
#define nd second

vector<string> dict;

char S[5000];
int DP[5000][10];
int INF = 999999;

bool match[5000];

void scase() {    
    scanf("%s",S+1);
    int N = strlen(S+1);
    FOR(i,1,N+1) {
        REP(j,5) DP[i][j] = INF;
 
        FOREACH(it, dict) {
            if (it->size() > i) continue;
            int s = i - it->size() + 1;

            FOR(f0,0,5) {
                int f = -f0 - 1;
                int tmp = 0;
                REP(j,it->size()) if (S[s + j] != (*it)[j]) {
                    ++tmp;
                    if (j - f < 5) tmp = INF;
                    f = j;
                }
                
                int b = min(4, (int)it->size()-1 - f);            
                DP[i][b] = min(DP[i][b], DP[s-1][f0] + tmp);                
                
                //if (*it == "code") printf("%d %d\n", i, tmp);
                //if (*it == "jam") printf("jam %d|%d %d %d\n",i,s,b,tmp);                
            }            
        }    
        FORD(j,3,0) DP[i][j] = min(DP[i][j], DP[i][j+1]);
    }
    
    int res = INF;
    REP(j,5) res = min(res, DP[N][j]);
    printf("%d\n", res);
}

char buf[1000000];

int main() {
    int W = 521196;
    FILE* f = fopen("garbled_email_dictionary.txt", "r");
    REP(i,W) {
        fscanf(f, "%s",buf);
        dict.push_back(buf);
    }
    fclose(f);

    int C;
    scanf("%d",&C);
    FOR(i,1,C+1) {
        printf("Case #%d: ", i);
        scase();
    }
}  
