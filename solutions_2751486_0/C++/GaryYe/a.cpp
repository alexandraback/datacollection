//Program: a
//Author: gary
//Date: 12/05/2013
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <limits>
#include <string>
#include <iostream>
#include <sstream>
#include <functional>
#include <algorithm>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define CNT(c,x) ((c).find(x) != (c).end())
#define FOR(i, a, n) for(int i=(a);i<=(n);i++)
#define REP(i, n) for(int i=0;i<(n);i++)
#define REP1(i, n) for(int i=0;i<=(n);i++)
#define DBG(VAR) cerr<<#VAR<<" = "<<(VAR)<<endl;
#define CLR(x, v) memset(x, v, sizeof(x))
#define SZ(x) ( (int) (x).size() )
#define MP(x, y) make_pair( (x), (y) )
#define MP3(x, y, z) MP( (x), MP( (y), (z) ) )
#define MP4(x1, y1, x2, y2) MP( MP(x1, y1), MP(x2, y2) )
#define foreach(it, C) for(typeof((C).begin())it=(C).begin();it!=(C).end();++it)
#define pb push_back
typedef long long LL;
typedef pair<int, int> PII;
template<class T> bool checkMin(T& a, T b) { if(a > b){ a = b;return 1;}return 0;}
template<class T> bool checkMax(T& a, T b) { if(a < b){ a = b;return 1;}return 0;}
//int dx[]={-1,0,1,0},  dy[]={0,1,0,-1};
//int dx[]={-1,-1,0,1,1,1,0,-1},dy[]={0,1,1,1,0,-1,-1,-1};
const int INF = 1e9;
const int MN = -1;
const string vowel = "aeiou";
int T, n, m;
string S;

#define VOWEL 0
#define CONSONANT 1

int main(){
  cin >> T;
  for(int cs = 1; cs <= T; cs++){
    printf("Case #%d: ", cs);
    cin >> S >> n;
    m = S.length();

    int i, last = -1, streak = 0, res = 0;

    for(i = 0; i < m; ++i){
      int is = !count(ALL(vowel), S[i]);
      
      if(is == VOWEL)
	streak = 0;
      else
	streak++;
      if(streak >= n){
	res += i + 2 - n;
	last = max(last, i + 2 - n);
      }else{
	if(last != -1)
	  res += last;
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
