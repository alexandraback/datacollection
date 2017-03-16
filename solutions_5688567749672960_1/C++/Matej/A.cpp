#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

const long long infinity = 1e9 + 9;

long long N;
long long dp[1000009];
long long bk[1000009];
queue<long long> Q;
queue<long long> C;

long long reverse(long long x)
{
  long long r = 0;
  while (x > 0)
  {
    r = 10 * r + (x % 10);
    x = x / 10;
  }
  return r;
}

long long digits(long long x)
{
  long long r = 0;
  while (x > 0)
  {
    x /= 10;
    r++;
  }
  return r;
}

long long power(long long x)
{
  long long r = 1;
  for (long long i = 0; i < x; ++i)
    r *= 10;
  return r;
}

bool verbose = false;

int main()
{
  long long T;
  cin >> T;
  for (long long Ti = 1; Ti <= T; Ti++) {
    // input
    cin >> N;
    
    // special case
    if (N == 1)
    {
      cout << "Case #" << Ti << ": " << 1 << endl;
      continue;
    }
    
    long long x = N;
    long long steps = 0;
    while (x > 10)
    {
      if (x % 10 == 0)
      {
        x--;
        steps++;
      }
      
      
      long long d = digits(x);
      
      if (verbose)
      {
        cout << x << " has " << digits(x) << " digits." << endl;
        cout << "power " << power(digits(x) / 2) << endl;
      }
      
      long long p = power(digits(x) / 2);
      long long s = x % p - 1;
      
      if (verbose)
      {
        cout << "subtract = " << s << endl;
      }
      
      steps += s;
      x -= s;
      
      if (verbose)
      {
        cout << "x = " << x << "; steps = " << steps << endl;
      }
      
      if (x != reverse(x))
      {
      
        if (verbose)
        {
          cout << " reverse " << endl;
        }
        x = reverse(x);
        steps += 1;
        if (verbose)
        {
          cout << "x = " << x << "; steps = " << steps << endl;
        }
        
        // do the same with d - d/2
        p = power(d - d/2);
        s = x % p;
        steps += s;
        x -= s;
        
        if (verbose)
        {
          cout << "x = " << x << "; steps = " << steps << endl;
        }
      }
      
      // subtract 1
      x--;
      steps++;
      
      if (verbose)
      {
        cout << "x = " << x << "; steps = " << steps << endl;
      }
    }
    
    steps += x;
    if (verbose)
    {
      cout << "x = " << x << "; steps = " << steps << endl;
    }
    
    cout << "Case #" << Ti << ": " << steps << endl;
        
    continue;
    // dp
    while (true) {
      long long q = Q.front(); Q.pop();
      long long c = C.front(); C.pop();
      if (c + 1 < dp[q + 1])
      {
        Q.push(q + 1);
        C.push(c + 1);
        dp[q + 1] = c;
        bk[q + 1] = q;
      }
      if (c + 1 < dp[reverse(q)])
      {
        //if (reverse(q) < q)
        //  cout << q << " to " << reverse(q) << endl;
        Q.push(reverse(q));
        C.push(c + 1);
        dp[reverse(q)] = c + 1;
        bk[reverse(q)] = q;
      }
      if ((q + 1 == N) || (reverse(q) == N))
      {
        cout << "Case #" << Ti << ": " << c + 1 << endl;
        break;
      }
    }
    
    continue;
    long long target = 987981;
    target = 189789;
    while (target != -1)
    {
      cout << target;
      if (target != bk[target] + 1)
        cout << " !!!";
      cout << endl;
      target = bk[target];
    }
    cout << endl;
    
    
  }
  return 0;
}
