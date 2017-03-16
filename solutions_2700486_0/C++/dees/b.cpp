#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cassert>
#include <bitset>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <sstream>

class Binomial
{
public:
    Binomial(long long Max)
    {
        max = Max+1;
        table = new unsigned long long * [max]();
        for (long long i=0; i < max; i++)
        {
            table[i] = new unsigned long long[max]();

            for (long long j = 0; j < max; j++)
            {
                table[i][j] = 0;
            }
        }
    }
    ~Binomial()
    {
        for (long long i =0; i < max; i++)
        {
            delete table[i];
        }
        delete table;
    }

    unsigned long long Choose(unsigned long long n, unsigned long long k);

private:
    bool Contains(unsigned long long n, unsigned long long k);

    long long max;
    unsigned long long **table;
};

unsigned long long Binomial::Choose(unsigned long long n, unsigned long long k)
{
    if (n < k) return 0;
    if (k == 0 || n==1 ) return 1;
    if (n==2 && k==1) return 2;
    if (n==2 && k==2) return 1;
    if (n==k) return 1;


    if (Contains(n,k))
    {
        return table[n][k];
    }
    table[n][k] = Choose(n-1,k) + Choose(n-1,k-1);
    return table[n][k];
}
bool Binomial::Contains(unsigned long long n, unsigned long long k)
{
    if (table[n][k] == 0) 
    {
        return false;
    }
    return true;
}

std::vector<int> ebenen;
Binomial bino(10000);

void pre()
{
  int cur=1;
  int cpos=1;
  ebenen.push_back(cur);
  while (cur<1E6+20)
  {
    cpos+=2;
    cur+=cpos+cpos-1;
    ebenen.push_back(cur);
  }
}

double solve(int N, int X, int Y )
{
  if (X==0&&Y==0)
    return 1.0;
  if (X<0)
    X=-X;
  auto it = std::upper_bound(std::begin(ebenen),std::end(ebenen),N);
  int ebs = it-std::begin(ebenen);
  int realeb = (X+Y)/2+1;
  if (realeb<=ebs)
    return 1.0;
  if (realeb>ebs+1)
    return 0.0;
  --it;
  int extra=N-*it;
  if ( extra == 0 )
    return 0.0;
  int realextra=Y+1;
  if (realextra>extra)
    return 0.0;
  double res=0.0;
  if (X==0)
    return 0.0;
  int singleside=realeb*2-2;
  if ( extra-singleside >= realextra )
    return 1.0;
  for ( int i=realextra;i<=extra;++i)
  {
    res += bino.Choose(extra,i);
  }
  for ( int i=0;i<extra;++i)
    res*=0.5;
  return res;
}

int main( int argn, char** argv )
{
  int ncases;
  scanf("%d",&ncases);
  pre();
  for ( int icase = 0; icase<ncases; ++icase )
  {
    int N,X,Y;
    scanf("%d%d%d",&N,&X,&Y);
    double res = solve(N,X,Y);
    printf("Case #%d: %lf\n",icase+1,res);
  }
  return 0;
}
