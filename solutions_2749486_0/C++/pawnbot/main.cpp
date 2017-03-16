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
  string res;
  int x, y;
  
  void read_data ()
  {
    cin >> x >> y;
  }
  int solve ()
  {
    for (int i = 0; i < x; ++i)
      res += "WE";
    for (int i = 0; i > x; --i)
      res += "EW";
    for (int i = 0; i < y; ++i)
      res += "SN";
    for (int i = 0; i > y; --i)
      res += "NS";
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
