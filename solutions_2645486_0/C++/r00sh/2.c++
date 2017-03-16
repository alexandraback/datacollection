#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <complex>
#include <fstream>

using namespace std;

#define s(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)

#define pb push_back
#define mp make_pair
#define gcd __gcd
#define bitcount __builtin_popcount

#define rep(i, n) for(int i=0;i<(n);i++)
#define forall(i,a,b) for(int i=(a);i<(b);i++)
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin() ;it!=(c).end();++it)
#define all(a) (a).begin(), (a).end()
#define in(a,b) ((b).find(a) != (b).end())
#define fill(a,v) memset((a), (v), sizeof (a))
#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef vector<string> vs;
typedef pair<int,int> ii; 

int memo[6][11];
vi vec;

int small(int h, int e, int r, int n, int p){
  if (p == n)
    return 0;
  if (memo[h][p])
    return memo[h][p];
  int max = 0;
  int g;
  for(int i = 0; i <= h; i++){
    g = vec[p] * i + small(min(h - i + r, e), e, r, n, p + 1);
    if (max < g)
      max = g;
  }
  memo[h][p] = max;
  return max;
}

int main(int argc, char *argv[])
{
  int tests;
  char infile[40], outfile[40];
  ifstream fin;
  ofstream fout;
  int z;
 
  if (argc != 2){
    cout << "No file provided.\n";
    return -1;
  }
  
  for (z = 0; argv[1][z] != '\0'; z++)
    infile[z] = outfile[z] = argv[1][z];
  infile[z] = '\0';
  outfile[z - 2] = 'o';
  outfile[z - 1] = 'u';
  outfile[z] = 't';
  outfile[z + 1] = '\0';
  
  fin.open(infile);
  fout.open(outfile);
  fin >> tests;

  rep(z, tests){
    fout << "Case #" << z + 1 << ": ";
    int n, r, e;
    fin >> e >> r >> n;
    rep(i, 6)
      rep(j, 11)
      memo[i][j] = 0;
    vec.clear();
    vec.resize(n);
    rep(i, n)
      fin >> vec[i];
    int ans = small(e, e, r, n, 0);
    fout << ans << endl;
  }

  fin.close();
  fout.close();
  return 0;
}
