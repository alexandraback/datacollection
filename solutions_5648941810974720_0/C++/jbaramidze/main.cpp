#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stack>
#include <string.h>
#include <climits>
#include <limits>

using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;

#define FOR(i, a, b) for(int i=a; i<b; i++)
#define FORE(i, a, b) for(int i=a; i<=b; i++)
#define ll long long
#define pii pair<ll, ll>
#define mp make_pair
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define ceil(a, b) ((a)/(b) + ((a)%(b)!=0))
#define square(a) ((a)*(a))
#define PI 3.14159265359
#define INF 1000000000000LL;
#define mod 1000000009LL

string nums[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};


bool avail(int index, vector<int> &A)
{
  FOR(i, 0, nums[index].size()) if (A[nums[index][i]] == 0) return false;

  return true;
}


bool remove(int index, vector<int> &A)
{
//  FOR(i, 0, nums[index].size()) if (A[nums[index][i]] == 0) return false;

  FOR(i, 0, nums[index].size()) A[nums[index][i]]--;

  return true;
}

int main(int argc, char **argv) {
  
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);

  int T;
  cin >> T;

  FOR(t, 0, T)
  {
    string s;
    cin >> s;
    vector<int> A(500, 0);

    FOR(i, 0, s.size()) A[s[i]]++;

    vi result;

 //   Z(0)  2(W) 4(R) 6(X) 8(G)         F(5)  H(3) I(9) O(1)  7

    while(avail(0, A))
    {
      remove(0, A);
      result.pb(0);
    }

    while(avail(2, A))
    {
      remove(2, A);
      result.pb(2);
    }

    while(avail(4, A))
    {
      remove(4, A);
      result.pb(4);
    }

    while(avail(6, A))
    {
      remove(6, A);
      result.pb(6);
    }

    while(avail(8, A))
    {
      remove(8, A);
      result.pb(8);
    }

    while(avail(5, A))
    {
      remove(5, A);
      result.pb(5);
    }

    while(avail(3, A))
    {
      remove(3, A);
      result.pb(3);
    }

    while(avail(9, A))
    {
      remove(9, A);
      result.pb(9);
    }

    while(avail(1, A))
    {
      remove(1, A);
      result.pb(1);
    }

    while(avail(7, A))
    {
      remove(7, A);
      result.pb(7);
    }

    sort(result.begin(), result.end());



    printf("Case #%d: ", t+1);
    FOR(i, 0, result.size()) printf("%d", result[i]);

    printf("\n");
  }
}
