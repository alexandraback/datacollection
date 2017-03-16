#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define PII       pair<int,int>
#define all(c)    c.begin(),c.end()
#define sz(c)     (int)c.size()
#define clr(c)    c.clear()
#define pb        push_back
#define mp        make_pair
#define cin(x)    scanf("%d",&x)
#define MOD            1000000007
#define EPS            1E-10

int fit(string a,int b)
{
      for(int i = sz(a) - 1; i >= 0; i--)
      {
            int v = b%10;
            b /= 10;
            if(a[i] == '?') continue;
            if(v != (a[i] - '0')) return 0;
      }
      if(b) return 0;
      return 1;
}

int better(int i,int j,PII A)
{
      if(i < A.first) return 1;
      if(i == A.first && j < A.second) return 1;
      return 0;
}

ifstream fin("in.txt");
ofstream fout("out.txt");

int main()
{
      int t;
      fin >> t;
      for(int ii = 1; ii <= t; ii++)
      {
            fout << "Case #" << ii << ": ";
            string a,b;
            fin >> a >> b;
            int bestDiff = 1000000;
            PII no = mp(1000000,1000000);
            for(int i = 0; i < 1000; i++)
            {
                  if(fit(a,i) == 0) continue;
                  for(int j = 0; j < 1000; j++)
                  {
                        if(fit(b,j) == 0) continue;
                        int d = abs(i - j);
                        if(d < bestDiff or (d == bestDiff && better(i,j,no)))
                        {
                              bestDiff = d;
                              no = mp(i,j);
                        }
                  }
            }
            for(int i = sz(a) - 1; i >= 0; i--)
            {
                  a[i] = (char)('0' + (no.first%10));
                  no.first /= 10;
                  b[i] = (char)('0' + (no.second%10));
                  no.second /= 10;
            }
            fout << a << " " << b << "\n";
      }
      return 0;
}