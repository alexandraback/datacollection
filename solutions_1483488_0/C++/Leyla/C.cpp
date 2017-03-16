#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int ten[10];
int shift(int a, int n)
{
 // cout << "shifting " << a << " " << n << "\t";
  int last = a % 10;
  a /= 10;
  a += last * ten[n];
  //cout << "shifted " << a << endl;
  return a;
}
int countn(int a)
{
  int ans = 0;
  for(; ans < 10; ++ans)
  {
    if(ten[ans] > a)
    {
      --ans; break;
    }
  }
  return ans;
}
int calc(int a, int b)
{
  int ans = 0;
  for(int i = a; i <= b; ++i)
  {
  //  cout << "cur = " << i << endl;
    int c = i;
    int n = countn(i);
  //  int cnt = 0;
    while((c = shift(c, n)) != i)
    {
      if(c >= a && c <= b && c < i)
        ++ans;
/*      ++cnt;
      if(cnt > 10)
      {
        cout << "wrong " << i << endl;
        return 0;
      }*/
    }
  }
  return ans;
}
int main()
{
  freopen("C-small-attempt0.in", "r", stdin);
  freopen("C-small.out", "w", stdout);
  int test; cin >> test;
  ten[0] = 1;
  for(int i = 1; i < 10; ++i)
  {
    ten[i] = ten[i - 1] * 10;
  }
  for(int t = 0; t < test; ++t)
  {
    int a, b; cin >> a >> b;
    cout << "Case #" << t + 1 << ": " << calc(a, b) << endl;
  }
  return 0;
}