/* Brian's GCJ entries */
#include <vector>
#include <iterator>
#include <map>
#include <cmath>
#include <set>
#include <deque>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <string.h>
#include <glpk.h> // http://www.gnu.org/software/glpk
using namespace std;
int bitct(long long r) {return r == 0 ? 0 : (bitct(r>>1) + (r&1));}
long long gcd(long long x, long long y) {return x ? gcd(y%x,x) : y;}
template<typename T> ostream& operator << (ostream &o,vector<T> v) {o<<"{";
	int i=0,s=v.size();for(;i+1<s;i++)o<<v[i]<<", ";if(s)o<<v[i];o<<"}";return o;}
long long choose(long long n, long long q)
{ if(n==0 || q==0) return 1;
	if (q==1) return n; else return ( choose(n, q-1) * (n-q+1 ) /q); }
#define foreach(i,c) for(typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define FOR(i,a,b) for(typeof(a) i=(a); i < (b); ++i)

void calc(ifstream &, ofstream &);
main() { stringstream filename, fnamein, fnameout;
	string file("C");
	filename << file << "-small.";
	fnamein << filename.str() << "in"; fnameout << filename.str() << "out";
	ifstream fin(fnamein.str().c_str()); ofstream fout(fnameout.str().c_str());
	int countx;
	fin >> countx;
  calc(fin, fout);
	fin.close(); fout.close(); }


map<long long, double> ptable[2000000];
int R, N, M, K;
int cts[21];
double probs[2000000];
double initprobs[2000000];
int ccc=0;

long long bang(int i)
{
  long long x=1;
  for(int j=i;j>0;j--)
    x*=j;
  return x;
}

int c(int m, int left, long long combos)  
{
  if(m > M)
    {
    probs[ccc]=initprobs[ccc] = combos;
    //compute tables
    ptable[ccc][1]=1.0;

    for(int i=2;i<=M;i++)
      {
      map<long long, double> next;
      int my=1;
      for(int j=0;j<=cts[i];j++)
        {
        for(auto k:ptable[ccc])
          next[k.first * my] = k.second * choose(cts[i], j) * (1.0/(1<<cts[i]));
        my *= i;
        }
      ptable[ccc]=next;
      }
    ccc++;
    }
  else if (m==M)
    {
    cts[m]=left;
    c(1+m, 0, combos*bang(left));
    }
  else
    {
    for(int i=0;i<=left;i++)
      {
      cts[m]=i;
      c(1+m, left-i, combos*bang(i));
      }
    }
  return 0;
}

int cccc=0;
int cord(int id, int m, int left, ofstream &fout)

{
  if(m > M)
    {
    if(id == cccc)
      {
      for(int i=2;i<=M;i++)
        for(int j=0;j<cts[i];j++)
          fout << i;
      fout << endl;
      }
    cccc++;
    }
  else if (m==M)
    {
    cts[m]=left;
    cord(id, 1+m, 0, fout);
    }
  else
    {
    for(int i=0;i<=left;i++)
      {
      cts[m]=i;
      cord(id, 1+m, left-i, fout);
      }
    }
  return 0;
}

void calc(ifstream &fin, ofstream &fout)
	{
  fin >> R >> N >> M >> K;
  c(2, N, 1);
  cerr << "precomputed" << endl;
 // for(int i=0;i<100;i++)
  //  cerr << initprobs[i] << endl;
  
	for(int jj=0;jj<R;jj++)
		{
    memcpy(probs, initprobs, sizeof(double) * 2000000);
    for(int jjj=0;jjj<K;jjj++)
      {
      long long in;
      fin >> in;
      for(int i=0;i<ccc;i++)
        probs[i] = probs[i] * ptable[i][in];
      }
    int best=0;
    double bestval = 0;
    for(int i=0;i<ccc;i++)
      if(probs[i] > bestval)
        {
        bestval = probs[i];
        best=i;
        }

    cccc=0;
    cord(best, 2, N, fout);
		}

	return; 
	}
