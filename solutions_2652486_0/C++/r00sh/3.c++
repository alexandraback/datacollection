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

#define JIG 10000
#define INF 10000
vvi subs;
vvi prods;
vi scores;

int r, n, m, k;

void get_score (int x, int y){
    int score = 0;
    rep(i, k)
      if (subs[y][3] % prods[x][i] != 0){
	score = -INF;
	break;
      }
    if (score > -INF){
      rep(i, JIG){
	int a, b, c;
	a = rand() % 2;
	b = rand() % 2;
	c = rand() % 2;
	int prod = subs[y][0] * a + subs[y][1] * b + subs[y][2] * b;
	rep(j, k)
	  if (prod == prods[x][j])
	    score++;
      }
      scores[y] += score;
    }
}

int main(int argc, char *argv[])
{
  srand(time(NULL));
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
    fin >> r >> n >> m >> k;
    subs.resize(64);
    
    rep(i, 64)
      subs[i].resize(4);
    int p = 0;
    for (int i = 2; i <= 5; i++)
      for (int j = 2; j <= 5; j++)
	for (int k = 2; k <= 5; k++){
	  subs[p][0] = i;
	  subs[p][1] = j;
	  subs[p][2] = k;
	  subs[p][3] = i * j * k;
	  p++;
	}
    prods.resize(r);
    rep(i, r)
      prods[i].resize(k);
    rep(i, r)
      rep(j, k)
      fin >> prods[i][j];
    rep(i, r){
      scores.clear();
      scores.resize(64);
      rep(j, 64)
	get_score(i, j);
      int max, max_j;
      max = 0; 
      max_j = 0;
      rep(j, 64)
	if (max < scores[j]){
	  max = scores[j];
	  max_j = j;
	}
      fout << endl;
      fout << subs[max_j][0] << subs[max_j][1] << subs[max_j][2];
    }
    fout << endl;
  }

  fin.close();
  fout.close();
  return 0;
}
