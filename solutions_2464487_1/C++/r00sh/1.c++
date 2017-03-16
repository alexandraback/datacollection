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
#include <gmpxx.h>

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

#define BIG 1000000000L
#define MAX "18446744073709551615"

mpz_class search(mpz_class bot, mpz_class top, mpz_class r, mpz_class t){
  if (bot == top)
    return bot;
  
  mpz_class guess = bot + (top - bot + 1) / 2;
  mpz_class g2 = guess * (2 * guess + 2 * r - 1);
  if (g2 == t)
    return guess;
  if (g2 > t)
    return search(bot, guess - 1, r, t);
  else 
    return search(guess, top, r, t);
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
  string r, t;
  ull add;
  mpz_class ans;
  rep(z, tests){
    fout << "Case #" << z + 1 << ": ";
    fin >> r >> t;
    /*
    ans = 0;
    add = 2 * r + 1;
    while(t >= add){
      ans += 1;
      t -= add;
      add += 4;
    }
    */
    mpz_class a, b, c, d;
    a = 0;
    b = MAX;
    c = r;
    d = t;
    ans = search(a, b, c, d);
    fout << ans << endl;
  }
  fin.close();
  fout.close();
  return 0;
}
