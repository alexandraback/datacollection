
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void flip(vector<int>& st, int N)
{
  int l = 0, r = N-1;
  while (l < r)
  {
    int tmp = st[l];
    st[l] = (st[r] + 1) % 2;
    st[r] = (tmp + 1) % 2;
    l++; r--;
  }
  if (l == r) st[l] = (st[l] + 1) % 2;
}

int solve(vector<int>& st, int N)
{
  while (N > 0 and st[N-1] == 1) N--;
  if (N == 0) return 0;

  int res = 100000;
  if (st[0] == 0)
  {
    vector<int> st2 = st;
    flip(st2, N);
    res = solve(st2, N-1) + 1;
  }
  for (int i = 0; i < N; i++)
  {
    if (st[i] == 1)
    {
      vector<int> st2 = st;
      flip(st2, i+1);
      flip(st2, N);
      int curres = solve(st2, N-1) + 2;
      if (curres < res) res = curres;
    }
  }
  return res;
}
void run(istream& in, ostream& out)
{
  int T; in >> T;
  for (int t = 1; t <= T; t++)
  {
    vector<int> st;
    string s; in >> s;
    int N = s.size();
    for (int i = 0; i < N; i++)
    {
      if (s[i] == '-') st.push_back(0);
      else st.push_back(1);
    }
    out << "Case #" << t << ": " << solve(st, st.size()) << endl;
  }
}

int main()
{
  ifstream fin("B-small-attempt0.in");
  ofstream fout("B-small-attempt0.out");
  run(fin, fout);
}

