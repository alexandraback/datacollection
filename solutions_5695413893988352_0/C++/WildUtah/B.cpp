/* Brian's GCJ entries */
#include <vector>
#include <iterator>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <chrono>
#include <tuple>
using namespace std;
typedef long long ll;
int bitct(long long r) {return r == 0 ? 0 : (bitct(r>>1) + (r&1));}
long long gcd(long long x, long long y) {return x ? gcd(y%x,x) : y;}
long long choose(long long n, long long q) { if(n==0 || q==0) return 1;
	if (q==1) return n; else return ( choose(n, q-1) * (n-q+1 ) /q); }
template<typename T> ostream& operator << (ostream &o,vector<T> v) {o<<"[";
	int i=0,s=v.size();for(;i+1<s;i++)o<<v[i]<<", ";if(s)o<<v[i];o<<"]";return o;}
template<typename K, typename V> ostream& operator << (ostream &o,
  unordered_map<K, V> m) {o<<"h{";for(auto i:m)o<<i.first<<" -> "<< i.second <<
  ", "; o<<"}";return o;}
template<typename K, typename V> ostream& operator << (ostream &o,
  map<K, V> m) {o<<"{";for(auto i:m)o<<i.first<<" -> "<< i.second <<
  ", "; o<<"}";return o;}
template<typename K, typename V> ostream& operator << (ostream &o,
  set<K> m) {o<<"#{";for(auto i:m)o<<i<< ", "; o<<"}";return o;}
template<typename K, typename V> ostream& operator << (ostream &o,
  unordered_set<K> m) {o<<"#h{";for(auto i:m)o<<i<< ", "; o<<"}";return o;}
//int dx[8] = {0,  1,  1,  1,  0, -1, -1, -1}
//int dy[8] = {1,  1,  0, -1, -1, -1,  0,  1}
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void calc(ifstream &, ofstream &);
main() { stringstream filename, fnamein, fnameout;
  typedef std::chrono::duration<int,std::milli> ms;
	string file("B");
	filename << file << "-small.";
	fnamein << filename.str() << "in"; fnameout << filename.str() << "out";
	ifstream fin(fnamein.str().c_str()); ofstream fout(fnameout.str().c_str());
	int count;
	fin >> count;
	for(int i=0;i<count;i++) {
		fout << "Case #" << (i+1) << ": ";
    chrono::steady_clock::time_point t0 = chrono::steady_clock::now();
		calc(fin, fout);
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    cerr << "CASE" << (i+1) << " " << 
      (chrono::duration_cast<ms>(t1-t0)).count() << endl;
		fout.flush(); }
	fin.close(); fout.close(); }

tuple<ll, ll> n0(int i, ll l, string ls, ll r, string rs)
{
  for(i=i+1;i<ls.size();i++)
    {
    l*=10;
    r*=10;
    if(ls[i] == '?')
      l+=9;
    else
      l+=ls[i]-'0';

    if(rs[i] == '?')
      r+=0;
    else
      r+=rs[i]-'0';
    }

  return make_tuple(l, r);
}

void calc(ifstream &fin, ofstream &fout)
	{
  string c,j;
  fin >> c >> j;

  ll cc, cj, diff = 999'999'999'999'999'999+5;
  abs(-1);

  ll mc=0, mj=0;
  int stop=0;
  for(int i=0;i<c.size();i++)
    {
    mc*=10; 
    mj*=10;

    if(c[i] == '?' && j[i] == '?')
      {
      ll pc=mc, pj=mj+1;
      tie(pc, pj) = n0(i, pc, c, pj, j);
      if(abs(pc-pj) < diff || 
          abs(pc-pj) == diff && pc < cc ||
          abs(pc-pj) == diff && pc == cc && pj < cj )
        {cc=pc;cj=pj;diff=abs(pc-pj);} 

      pc=mc+1, pj=mj;
      tie(pj, pc) = n0(i, pj, j, pc, c);
      if(abs(pc-pj) < diff || 
          abs(pc-pj) == diff && pc < cc ||
          abs(pc-pj) == diff && pc == cc && pj < cj )
        {cc=pc;cj=pj;diff=abs(pc-pj);} 

      continue;
      }

    if(c[i] == '?')
      {
      mj+=j[i]-'0';
      if(j[i] <= '8')
        {
        ll pj=mj, pc=mc+j[i]-'0'+1;
        tie(pj, pc) = n0(i, pj, j, pc, c);
        if(abs(pc-pj) < diff || 
            abs(pc-pj) == diff && pc < cc ||
            abs(pc-pj) == diff && pc == cc && pj < cj )
          {cc=pc;cj=pj;diff=abs(pc-pj);} 
        }
      if(j[i] >= '1')
        {
        ll pj=mj, pc=mc+j[i]-'0'-1;
        tie(pc, pj) = n0(i, pc, c, pj, j);
        if(abs(pc-pj) < diff || 
            abs(pc-pj) == diff && pc < cc ||
            abs(pc-pj) == diff && pc == cc && pj < cj )
          {cc=pc;cj=pj;diff=abs(pc-pj);} 
        }

      mc+=j[i]-'0';
      continue;
      }

    if(j[i] == '?')
      {
      mc+=c[i]-'0';
      if(c[i] <= '8')
        {
        ll pc=mc, pj=mj+c[i]-'0'+1;
        tie(pc, pj) = n0(i, pc, c, pj, j);
        if(abs(pc-pj) < diff || 
            abs(pc-pj) == diff && pc < cc ||
            abs(pc-pj) == diff && pc == cc && pj < cj )
          {cc=pc;cj=pj;diff=abs(pc-pj);} 
        }
      if(c[i] >= '1')
        {
        ll pc=mc, pj=mj+c[i]-'0'-1;
        tie(pj, pc) = n0(i, pj, j, pc, c);
        if(abs(pc-pj) < diff || 
            abs(pc-pj) == diff && pc < cc ||
            abs(pc-pj) == diff && pc == cc && pj < cj )
          {cc=pc;cj=pj;diff=abs(pc-pj);} 
        }



      mj+=c[i]-'0';
      continue;
      }

    if(c[i] == j[i])
      {
      mc+=c[i]-'0';
      mj+=c[i]-'0';
      continue;
      }

    if(c[i] > j[i])
      {
      mc+=c[i]-'0';
      mj+=j[i]-'0';

      ll pc=mc, pj=mj;
      tie(pj, pc) = n0(i, pj, j, pc, c);
      if(abs(pc-pj) < diff || 
          abs(pc-pj) == diff && pc < cc ||
          abs(pc-pj) == diff && pc == cc && pj < cj )
        {cc=pc;cj=pj;diff=abs(pc-pj);} 

      stop=1;
      break;
      }

    if(j[i] > c[i])
      {
      mc+=c[i]-'0';
      mj+=j[i]-'0';

      ll pc=mc, pj=mj;
      tie(pc, pj) = n0(i, pc, c, pj, j);
      if(abs(pc-pj) < diff || 
          abs(pc-pj) == diff && pc < cc ||
          abs(pc-pj) == diff && pc == cc && pj < cj )
        {cc=pc;cj=pj;diff=abs(pc-pj);} 

      stop=1;
      break;
      }

    }

  if(!stop && mc==mj)
    cc=cj=mj;

  fout << setfill('0') << setw(c.size()) << cc << " " << 
    setfill('0') << setw(c.size()) << cj << endl;
  
  return; 
	}
