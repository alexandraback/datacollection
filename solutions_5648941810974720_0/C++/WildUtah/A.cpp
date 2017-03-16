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
#include <sstream>
#include <fstream>
#include <string>
#include <chrono>
using namespace std;
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
	string file("A");
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

void calc(ifstream &fin, ofstream &fout)
	{
  string s;
  fin >> s;

  vector<int> digits(10, 0);
  for(int i=0;i<s.size();i++) if('Z'==s[i])digits[0]++;
  for(int i=0;i<s.size();i++) if('G'==s[i])digits[8]++;
  for(int i=0;i<s.size();i++) if('X'==s[i])digits[6]++;
  for(int i=0;i<s.size();i++) if('S'==s[i])digits[7]++;
  digits[7]-=digits[6];
  for(int i=0;i<s.size();i++) if('V'==s[i])digits[5]++;
  digits[5]-=digits[7];
  for(int i=0;i<s.size();i++) if('U'==s[i])digits[4]++;
  for(int i=0;i<s.size();i++) if('H'==s[i])digits[3]++;
  digits[3]-=digits[8];
  for(int i=0;i<s.size();i++) if('W'==s[i])digits[2]++;
  for(int i=0;i<s.size();i++) if('I'==s[i])digits[9]++;
  digits[9]-=digits[8]+digits[5]+digits[6];
  for(int i=0;i<s.size();i++) if('N'==s[i])digits[1]++;
  digits[1]-=digits[9]*2+digits[7];

  for(int i=0;i<10;i++)
    for(int j=0;j<digits[i];j++)
      fout << i;


    fout << endl;

  return; 
	}
