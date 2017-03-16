
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
  int res = 0;

  while (true)
  {
    while (N > 0 and st[N-1] == 1) N--;
    if (N == 0) return res;

    if (st[0] == 1)
    {
      int i = 0;
      while (st[i] == 1) st[i++] = 0;
      res++;
    }

    flip(st, N);
    res++;
    N--;
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
  ifstream fin("B-large.in");
  ofstream fout("B-large.out");
  run(fin, fout);
}

