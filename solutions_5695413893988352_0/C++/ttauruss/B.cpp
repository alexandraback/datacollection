
#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include <sstream>
#include <iomanip>
using namespace std;

using vi = vector<int>;

# define print(...)

bool match(string S, unsigned long l)
{
  int i = S.size() - 1;
  while (l)
  {
    if (S[i] != '?' and (S[i]-48) != l%10) return false;
    i--;
    l /= 10;
  }
  while (i >= 0)
  {
    if (S[i] != '?' and S[i] != '0') return false;
    i--;
  }
  return true;
}

void check(string S1, string S2, string O1, string O2, ostream& out)
{
  istringstream iss(S1);
  unsigned long l1; iss >> l1;
  istringstream iss2(S2);
  unsigned long l2; iss2 >> l2;
  auto diff = l1 < l2 ? l2 - l1 : l1 - l2;
  for (unsigned long d = 1; d < diff; d++)
  {
    if (l1 < l2 and match(O1, l2+d))
    {
      out << setw(S2.size()) << setfill('0') << (l2+d) << " " << S2 << endl;
      return;
    }
    if (l2 < l1 and match(O2, l1+d))
    {
      out << S1 << " " << setw(S2.size()) << setfill('0') << (l1+d) << endl;
      return;
    }
  }
  out << S1 << " " << S2 << endl;
}

void solve(string S1, string S2, ostream& out)
{
  string O1 = S1, O2 = S2;
  int N = S1.size();
  int comp = 0;
  for (int i = 0; i < N; i++)
  {
    if (S1[i] == '?' and S2[i] == '?')
    {
      if (comp == 0) S1[i] = S2[i] = '0';
      else if (comp == -1)
      {
        S1[i] = '9';
        S2[i] = '0';
      }
      else
      {
        S1[i] = '0';
        S2[i] = '9';
      }
    }
    else if (S1[i] == '?')
    {
      if (comp == 0) S1[i] = S2[i];
      if (comp == -1) S1[i] = '9';
      if (comp == 1) S1[i] = '0';
    }
    else if (S2[i] == '?')
    {
      if (comp == 0) S2[i] = S1[i];
      if (comp == -1) S2[i] = '0';
      if (comp == 1) S2[i] = '9';
    }
    else
    {
      if (comp == 0)
      {
        if (S1[i] < S2[i]) comp = -1;
        if (S2[i] < S1[i]) comp = 1;
      }
    }
  }
  check(S1, S2, O1, O2, out);
}

void run(istream& in, ostream& out)
{
  int T; in >> T;
  for (int t = 1; t <= T; t++)
  {
    string S1, S2;
    in >> S1 >> S2;
    out << "Case #" << t << ": ";
    solve(S1, S2, out);
  }
}

int main()
{
  ifstream fin("B-small.in");
  ofstream fout("B-small.out");
  run(fin, fout);
}

