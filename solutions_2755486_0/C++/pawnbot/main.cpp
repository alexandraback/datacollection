#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <cstring>
#include <complex>
#include <assert.h>
#include <sstream>
#include <map>
#include <omp.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef long long i64;
typedef pair<int, int> pi;

#define SQR(A) ((A) * (A))
#define CUBE(A) ((A) * (A) * (A))
#define MIN(A,B) ((A) < (B) ? (A) : (B))
#define MAX(A,B) ((A) > (B) ? (A) : (B))

template <class T>
string cout_str(T data)
{
  stringstream buf;
  buf << data;
  return buf.str();
}

int consonant (char ch)
{
  if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    return 0;
  else
    return 1;
}

class solver
{
 public:
  long long res;
  int N;
  vi d, n, w, e, s, dd, dp, ds; 
  
  void read_data ()
  {
    cin >> N;
    d.resize (N);
    n.resize (N);
    w.resize (N);
    e.resize (N);
    s.resize (N);
    dd.resize (N);
    dp.resize (N);
    ds.resize (N);
    for (int i = 0; i < N; ++i)
      cin >> d[i] >> n[i] >> w[i] >> e[i] >> s[i] >> dd[i] >> dp[i] >> ds[i];
  }
  int solve ()
  {
    res = 0;
    const int SHIFT = 5000;
    vector<int> str (10000);
    for (int day = 0; day <= 676060; ++day)
    {
      for (int i = 0; i < N; ++i)
        if (n[i] > 0 && d[i] == day)
        {
          int suc = 0;
          for (int pos = w[i]; pos < e[i]; ++pos)
            if (str[pos + SHIFT] < s[i])
            {
              suc = 1;
              break;
            }
          if (suc)
            res++;
        }
        for (int i = 0; i < N; ++i)
          if (n[i] > 0 && d[i] == day)
          {
            for (int pos = w[i]; pos < e[i]; ++pos)
              if (str[pos + SHIFT] < s[i])
                str[pos + SHIFT] = s[i];
            n[i] -= 1;
            d[i] += dd[i];
            w[i] += dp[i];
            e[i] += dp[i];
            s[i] += ds[i];
          }
    }
    return 0;
  }
  void write_res (int id) {cout << "Case #" << id + 1 << ": " << res << endl;}
};

int main ()
{
#ifdef _WIN32
  freopen ("../data.in", "r", stdin);
  freopen ("../output.txt", "w", stdout);
#else
  freopen ("data.in", "r", stdin);
  freopen ("output.txt", "w", stdout);
#endif

  string case_str;
  getline (cin, case_str);
  int cases = atoi (case_str.c_str ());
  vector<solver> tasks (cases);

  for (int id = 0; id < cases; ++id)
    tasks[id].read_data ();
  
  #pragma omp parallel for
  for (int id = 0; id < cases; ++id)
    if (tasks[id].solve () < 0)
      std::cerr << "BAD CASE: " << id + 1 << endl;

  for (int id = 0; id < cases; ++id)
    tasks[id].write_res (id);
  
  return 0;
}
