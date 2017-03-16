#include <algorithm>
#include <iterator>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <random>
#include <numeric>
#include <cmath>
#include <ctime>
#include <map>


using namespace std;

#define RA(x) (x).begin(), (x).end()
#define SZ(x) ((int) (x).size())

typedef vector<int> vi; 
typedef vector<string> vs;
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 

template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int solve()
{
  int E, R, N;
  scanf("%d %d %d", &E, &R, &N);
  vi value(N);
  for (int i = 0; i < N; i++) {
    int tmp;
    scanf("%d", &tmp);
    value[i] = tmp;
  }
  int sum=0, m=0;
  int maxe, rest;
  for (auto &i: value)
  {
    sum+= i;
  }
  for (auto &i: value)
    m = max(m, i);
  maxe = m*E;
  rest = (sum - m) * R;
  return maxe+rest;
}

int main()
{
  int cases;
  cin >> cases;
  int maxe;
  for (int cas = 1; cas < cases+1; cas++) {
    maxe = solve();
    printf("Case #%d: %d\n", cas, maxe);
  }

  return 0;
}

