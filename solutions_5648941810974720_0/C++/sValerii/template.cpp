#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <list>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <ctime>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

#define REP(i,n) for(int i=0; i<n; i++)
#define FORR(i,a,b) for (int i=a; i<=b; i++)
#define FORD(i,a,b) for (int i=a; i>=b; i--)
#define mset(a,b) memset(a,b,sizeof(a))
#define sz(a) int( a.size() )
#define all(A) A.begin(),A.end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define X first
#define Y second

typedef long long i64;
typedef vector<int> VI;
typedef vector< VI > VVI;
typedef pair<int,int> PII;
typedef vector<string> VS;

const string NUMBERS[10] = {
  "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int testNum;
  char s[20000];
  int letters[30];
  int num[10];


int check(int num) {
  int r = 200000;
  string st = NUMBERS[num];
  REP(i, sz(st))
    r = min(r, letters[ st[i]-'A']);
  //  printf("%s %d\n",st.c_str(), r);

  if (r == 0) return 0;
  REP(i, sz(st)) letters[ st[i]-'A' ] -= r;

  return r;
}

int main(){

 #ifdef LocalHost
  freopen("input.in","r", stdin);
  freopen("a1.txt", "w", stdout);

 #endif
  int order[10] = {0,2,6,8,4,5,7,3,9,1};
  scanf("%d\n", &testNum);
  REP(testCase,testNum) {
    gets(s);
    mset(letters,0);
    mset(num,0);
    int i = 0;
    while (s[i] !='\0') letters[ s[i]-'A']++, i++;
    REP(j,10) {
      num[order[j]] = check(order[j]);
    }

    printf("Case #%d: ",testCase+1);
    REP(j,10) REP(t,num[j]) printf("%d",j);
    printf("\n");
  }


  return 0;
}
