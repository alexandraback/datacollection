#include <algorithm>
#include <iterator>
#include <iostream>
#include <sstream>
#include <cstring>
#include <numeric>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <random>
#include <cmath>
#include <ctime>
#include <stack>
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

int solve(int A, stack<int>& mote)
{
    stack<int> motes = mote;
    int op = 0;
    if (A == 1)
      return motes.size();
    while (!motes.empty() && A > motes.top()) {
      A += motes.top();
      motes.pop();
    }
    if (motes.empty())
      return 0;
    int getbig = 0;
    int diff = motes.top() - A;
    int n = 0;
    while(((1<<n) - 1)*(A-1) <= diff) {
      n++;
      getbig++;
    }
    
    A += ((1<<n) - 1)*(A-1);
    op = min((int)motes.size(), (getbig + solve(A, motes)));
    return op;
}

int main()
{
  int cases;
  cin >> cases;

  for (int cas = 1; cas < cases+1; cas++) {
    int A, N;
    cin >> A >> N;
    vi motes(N);
    for(int i = 0; i < N; ++i) {
      cin >> motes[i];
    }
    sort(motes.begin(), motes.end());
    stack<int> mote;
    for(int i = N-1; i>=0; --i) {
      mote.push(motes[i]);
    }

    int ans = solve(A, mote);
    printf("Case #%d: %d\n", cas, ans);
    
  }

  return 0;
}
