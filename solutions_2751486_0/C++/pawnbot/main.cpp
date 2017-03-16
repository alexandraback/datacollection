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
#include <omp.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef long long i64;

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
  int n;
  string name;
  int nth;
  
  void read_data ()
  {
    int found = 0;
    string buf;
    string _nth;
    getline (cin, buf);
    for (size_t i = 0; i < buf.size (); ++i)
    {
      if (buf[i] == ' ')
        found = 1;
      else
        {
          if (found)
            _nth += buf[i];
          else
            name += buf[i];
        }
    }
    nth = atoi (_nth.c_str ());

  }
  int solve ()
  {
    res = 0;
    size_t size = name.size ();
    vector<int> cons (size);
    vector<int> vows (size);
    if (consonant(name[0]))
      cons[0] = 1;
    else
      vows[0] = 1;
    for (size_t i = 1; i < size; ++i)
    {
      if (consonant (name[i]))
        cons[i] = cons[i - 1] + 1;
      else
        vows[i] = vows[i - 1] + 1;
    }

    vector<int> ans (size);
    for (int i = nth - 1; i < size; ++i)
    {
      if (cons[i] >= nth)
        ans[i] = i - nth + 2;
      else
        if (i > 0)
          ans[i] = ans[i - 1];
      res += ans[i];
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
