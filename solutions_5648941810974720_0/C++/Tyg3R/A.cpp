#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

#define FOR(prom, a, b) for(int prom = (a); prom < (b); prom++)
#define FORD(prom, a, b) for(int prom = (a); prom > (b); prom--)
#define FORDE(prom, a, b) for(int prom = (a); prom >= (b); prom--)

#define DRI(a) int a; scanf("%d ", &a);
#define DRII(a, b) int a, b; scanf("%d %d ", &a, &b);
#define DRIII(a, b, c) int a, b, c; scanf("%d %d %d ", &a, &b, &c);
#define DRIIII(a, b, c, d) int a, b, c, d; scanf("%d %d %d %d ", &a, &b, &c, &d);
#define RI(a) scanf("%d ", &a);
#define RII(a, b) scanf("%d %d ", &a, &b);
#define RIII(a, b, c) scanf("%d %d %d ", &a, &b, &c);
#define RIIII(a, b, c, d) scanf("%d %d %d %d ", &a, &b, &c, &d);

#define PB push_back
#define MP make_pair

#define ff first
#define ss second
#define vi vector<int>
#define pii pair<int,int>

#define ll long long
#define ull unsigned long long

#define MM(co, cim) memset((co), (cim), sizeof((co)))

#define DEB(x) cerr << ">>> " << #x << " : " << x << endl;

int order[10] = {0,2,6,8,3,4,1,5,7,9};
int letter[10] = {'Z','W','X','G','H','R','O','F','V','E'};

char word[10][6] = {
  "ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"
};

int cnt[256];
int res[10];

int main ()
{
  DRI(T);
  FOR(t,0,T) {
    string s;
    cin >> s;
    FOR(i,0,s.size()) cnt[s[i]]++;
    FOR(i,0,10) {
      int num = order[i];
      int cc = cnt[letter[i]];
      res[num] = cc;
      int j = 0;
      while(word[num][j] != '\0') {
        cnt[word[num][j]] -= cc;
        j++;
      }
    }
    printf("Case #%d: ", t+1);
    FOR(i,0,10) {
      FOR(j,0,res[i]) cout << i;
    }
    cout << endl;
  }
  return 0;
}
