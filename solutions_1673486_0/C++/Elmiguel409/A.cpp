#include <string>
#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <map>
#include <complex>
#include <queue>
#include <set>
#include <algorithm>
#include <vector>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <bitset>
#include <cassert>
using namespace std;

#define FOR(a,b,c) for(long long a=(long long)(b);a<(long long)(c);a++)
#define ITER(a,b) for(__typeof((b).begin()) a = (b).begin(); a!=(b).end(); a++)
#define SUBSET(a,b) for(long long a = b; a!=0; a = (b & (a-1)))
#define MEMSET(dest,val) memset(dest,val,sizeof(dest))
#define PAIR pair<long long,long long>
#define BEGEND(a) (a).begin(), (a).end()
#define SHIFT(v) (1LL<<(v))
#define SQ(a) ((a) * (a))
#define LSB(a,b) (b<=sizeof(a)?(b & (SHIFT(a)-1)):LLMAX)

#define eps 1E-9
#define PI acos(-1.0)
#define INF 1000000000
#define LLINF ((1LL<<62)-1)


// ---------------------------------------------------------------------------------
//BEGIN CUT - Print Array - O(N)
void printArray(const vector<string> & v) { FOR(i,0,v.size()) cout << v[i] << endl; cout << endl; }
template<class T> 
void printArray(const vector<T> & v) { FOR(i,0,v.size()) cout << v[i] << " "; cout << endl; }
template <class T>
void printArray(const vector<vector<T> > &v){ FOR(i,0,v.size()) printArray(v[i]);}
//END CUT - Print Array

//BEGIN CUT - Graph deltas
int dr4[] = {0,0,-1,1},           dc4[] = {1,-1,0,0};
int dr8[] = {0,0,1,1,1,-1,-1,-1}, dc8[] = {1,-1,-1,0,1,-1,0,1};
//END CUT - Graph deltas

// BEGIN CUT - Misc. Data
string months[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
string daysOfWeek[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int daysOfMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};

string lettersU = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string lettersL = "abcdefghijklmnopqrstuvwxyz";
// BEGIN CUT - Misc. Data

//BEGIN CUT - HexStuff [ USED BY Bigint ]
string _hexdigits = "0123456789ABCDEF";
unsigned long long toHexLong(string str){ unsigned long long num = 0; FOR(i,0,str.length()) { num<<=4; if(isalpha(str[i])) num += (str[i]-'A'+10); else num += (str[i]-'0');} return num; }
string toHexString(unsigned long long num) {string ret; FOR(k,0,16) { ret += _hexdigits[((num>>(k<<2))&0xF)]; } reverse(ret.begin(),ret.end()); return ret;}
//END CUT - HexStuff

//BEGIN CUT - Math Functions - O(digits^2) [ USED By Bigint, Choose, Frac]
long long gcd(long long A, long long B){  if(!A && !B) return 0;  return (A%B)?gcd(B,A%B):B; }
long long lcm(long long A, long long B){ if(!A && !B) return 0; return A / gcd(A,B) * B; }
long long gcdext(long long A, long long B, long long &Aout, long long &Bout, long long cmod){ long long r,t; if(A%B==0) { Aout = 0, Bout = 1; r = B; } else{ r = gcdext(B,A%B,Aout,Bout,cmod); t = Bout; Bout = (Aout - A/B * Bout) % cmod; Aout = t;} return r;}
long long ModDiv(long long num, long long denom, long long mod){ long long A, B; gcdext(mod,denom,A,B,mod); return ((num * B) % mod + mod) % mod;}
//END CUT - Math Functions

//BEGIN CUT - Random Functions [ USED BY Bigint]
static bool _seeded = false;
unsigned long long lrand(int seed=-1){ if(!_seeded) _seeded=true,srand((seed==-1)?time(0):seed); return ((((unsigned long long)rand())<<32) | rand());}
//END CUT - Random Functions
// ---------------------------------------------------------------------------------

//BEGIN CUT - AVL Trees structure
#define _AVLSIZE 1
template <class T>
struct AVLTree{
 private:
   int _AVLleftChild[_AVLSIZE], _AVLrightChild[_AVLSIZE], _AVLparent[_AVLSIZE], _AVLdepth[_AVLSIZE], _AVLdescendants[_AVLSIZE]; int _AVLroot, _AVLtotal; bool _AVLbalanced; T _AVLdata[_AVLSIZE]; int _AVLleftCount[_AVLSIZE], _AVLrightCount[_AVLSIZE];
   int _AVLrightMost(int index){ return (_AVLrightChild[index] == -1)?index:_AVLrightMost(_AVLrightChild[index]); }
   int _AVLleftMost(int index){ return (_AVLleftChild[index] == -1)?index:_AVLleftMost(_AVLleftChild[index]); }
   int _AVLgetDepth(int index){ if(index == -1) return -1; else return _AVLdepth[index];}
   int _AVLgetDescendants(int index){ if(index==-1) return 0; else return _AVLdescendants[index];}
   int _AVLgetBalance(int index){ if(index == -1) return -1; else return _AVLgetDepth(_AVLrightChild[index]) - _AVLgetDepth(_AVLleftChild[index]);}
   void _AVLleftRotate(int rt, int pivot){ if(_AVLparent[rt]!=-1){ if(rt == _AVLleftChild[_AVLparent[rt]]) _AVLleftChild[_AVLparent[rt]] = pivot; else _AVLrightChild[_AVLparent[rt]] = pivot;} _AVLparent[pivot] = _AVLparent[rt]; _AVLparent[rt] = pivot; _AVLrightChild[rt] = _AVLleftChild[pivot]; _AVLleftChild[pivot] = rt; if(_AVLrightChild[rt]!=-1) _AVLparent[_AVLrightChild[rt]] = rt; if(_AVLroot == rt) _AVLroot = pivot; _AVLdepth[rt] = 1 + max(_AVLgetDepth(_AVLleftChild[rt]),_AVLgetDepth(_AVLrightChild[rt])); _AVLdepth[pivot] = 1 + max(_AVLgetDepth(_AVLleftChild[pivot]),_AVLgetDepth(_AVLrightChild[pivot])); _AVLdescendants[rt] = 1 + _AVLgetDescendants(_AVLleftChild[rt]) + _AVLgetDescendants(_AVLrightChild[rt]); _AVLdescendants[pivot] = 1 + _AVLgetDescendants(_AVLleftChild[pivot]) + _AVLgetDescendants(_AVLrightChild[pivot]);}
   void _AVLrightRotate(int rt, int pivot){ if(_AVLparent[rt]!=-1){ if(rt == _AVLleftChild[_AVLparent[rt]]) _AVLleftChild[_AVLparent[rt]] = pivot; else _AVLrightChild[_AVLparent[rt]] = pivot;} _AVLparent[pivot] = _AVLparent[rt]; _AVLparent[rt] = pivot; _AVLleftChild[rt] = _AVLrightChild[pivot]; _AVLrightChild[pivot] = rt; if(_AVLleftChild[rt]!=-1) _AVLparent[_AVLleftChild[rt]] = rt; if(_AVLroot == rt) _AVLroot = pivot; _AVLdepth[rt] = 1 + max(_AVLgetDepth(_AVLleftChild[rt]),_AVLgetDepth(_AVLrightChild[rt])); _AVLdepth[pivot] = 1 + max(_AVLgetDepth(_AVLleftChild[pivot]),_AVLgetDepth(_AVLrightChild[pivot])); _AVLdescendants[rt] = 1 + _AVLgetDescendants(_AVLleftChild[rt]) + _AVLgetDescendants(_AVLrightChild[rt]); _AVLdescendants[pivot] = 1 + _AVLgetDescendants(_AVLleftChild[pivot]) + _AVLgetDescendants(_AVLrightChild[pivot]);}
   void _AVLbalance(int cur){ if(cur == -1) return;  int balance = _AVLgetBalance(cur); if(abs(balance) > 1){ if(balance < 0){ if(_AVLgetBalance(_AVLleftChild[cur]) > 0) _AVLleftRotate(_AVLleftChild[cur],_AVLrightChild[_AVLleftChild[cur]]); _AVLrightRotate(cur,_AVLleftChild[cur]);} else{         if(_AVLgetBalance(_AVLrightChild[cur]) < 0) _AVLrightRotate(_AVLrightChild[cur],_AVLleftChild[_AVLrightChild[cur]]); _AVLleftRotate(cur,_AVLrightChild[cur]);}}_AVLdepth[cur] = max(_AVLgetDepth(_AVLrightChild[cur]),_AVLgetDepth(_AVLleftChild[cur])) + 1; _AVLdescendants[cur] = 1 + _AVLgetDescendants(_AVLrightChild[cur]) + _AVLgetDescendants(_AVLleftChild[cur]); _AVLbalance(_AVLparent[cur]);}
   void _AVLinsert(int last, int cur, int index, T data){ if(cur == -1){ _AVLparent[index] = last; _AVLdata[index]= data; _AVLrightChild[index] = _AVLleftChild[index] = -1; _AVLdepth[index] = 0; _AVLdescendants[index] = 1; _AVLtotal++; if(last == -1) _AVLroot = index; else if(_AVLdata[last] < data || _AVLdata[last] == data && last < index) _AVLrightChild[last] = index; else _AVLleftChild[last] = index; if(_AVLbalanced) _AVLbalance(index);} else if(_AVLdata[cur] < data || _AVLdata[cur]==data && cur < index) _AVLinsert(cur,_AVLrightChild[cur],index,data); else _AVLinsert(cur,_AVLleftChild[cur],index,data); _AVLdepth[cur] = max(_AVLgetDepth(_AVLrightChild[cur]),_AVLgetDepth(_AVLleftChild[cur])) + 1; _AVLdescendants[cur] = 1 + _AVLgetDescendants(_AVLrightChild[cur]) + _AVLgetDescendants(_AVLleftChild[cur]);}
   void _AVLremove(int cur, int index, T value){ if(cur==-1) return; else if(cur == index || index==-1 && _AVLdata[cur]==value){ if(_AVLdescendants[cur]>1){ int replace = (_AVLleftChild[cur]!=-1)?_AVLrightMost(_AVLleftChild[cur]):_AVLleftMost(_AVLrightChild[cur]); int par = _AVLparent[replace]; if(replace == _AVLleftChild[par]) _AVLleftChild[par] = _AVLrightChild[replace]; else _AVLrightChild[par] = _AVLleftChild[replace]; _AVLdepth[par] = max(_AVLgetDepth(_AVLrightChild[par]),_AVLgetDepth(_AVLleftChild[par])) + 1; _AVLdescendants[par] = 1 + _AVLgetDescendants(_AVLrightChild[par]) + _AVLgetDescendants(_AVLleftChild[par]);  _AVLparent[replace] = _AVLparent[cur]; if(_AVLparent[replace]!=-1){ if(_AVLleftChild[_AVLparent[replace]] == cur) _AVLleftChild[_AVLparent[replace]] = replace; else _AVLrightChild[_AVLparent[replace]] = replace;} _AVLleftChild[replace] = _AVLleftChild[cur]; _AVLrightChild[replace] = _AVLrightChild[cur]; _AVLparent[cur] = -2;  if(_AVLleftChild[replace]!=-1) _AVLparent[_AVLleftChild[replace]] = replace; if(_AVLrightChild[replace]!=-1) _AVLparent[_AVLrightChild[replace]] = replace;_AVLdepth[replace] = max(_AVLgetDepth(_AVLrightChild[replace]),_AVLgetDepth(_AVLleftChild[replace])) + 1; _AVLdescendants[replace] = 1 + _AVLgetDescendants(_AVLrightChild[replace]) + _AVLgetDescendants(_AVLleftChild[replace]); if(cur == _AVLroot) _AVLroot = replace;if(_AVLbalanced) if(par!=cur) _AVLbalance(par); else _AVLbalance(replace);  return;} else if(_AVLroot == cur) _AVLroot = -1, _AVLparent[cur] = -2; else{ if(_AVLleftChild[_AVLparent[cur]] == cur) _AVLleftChild[_AVLparent[cur]] = -1; else _AVLrightChild[_AVLparent[cur]] = -1; if(_AVLbalanced) _AVLbalance(_AVLparent[cur]); _AVLparent[cur] = -2; return; }}else if(_AVLdata[cur] < value || index!=-1 && _AVLdata[cur] == value && cur < index) _AVLremove(_AVLrightChild[cur],index, value);else _AVLremove(_AVLleftChild[cur],index, value);_AVLdepth[cur] = max(_AVLgetDepth(_AVLrightChild[cur]),_AVLgetDepth(_AVLleftChild[cur])) + 1; _AVLdescendants[cur] = 1 + _AVLgetDescendants(_AVLrightChild[cur]) + _AVLgetDescendants(_AVLleftChild[cur]); }
public:
   AVLTree(bool bal=true) : _AVLbalanced(bal) { init();}
   void init(){ _AVLroot = -1; _AVLtotal = 0; MEMSET(_AVLleftChild,-1); MEMSET(_AVLrightChild,-1); MEMSET(_AVLparent,-1); MEMSET(_AVLdepth,0); MEMSET(_AVLdescendants,0);}
   void insertIndex(int index, T value){ _AVLinsert(-1,_AVLroot,index,value);}
   void insert(T value){ _AVLinsert(-1,_AVLroot,_AVLtotal,value);}
   void removeIndex(int index) { _AVLremove(_AVLroot, index, _AVLdata[index]); }
   void remove(T value){ _AVLremove(_AVLroot,-1,value); }
};
// END CUT - AVL Trees

// BEGIN CUT - BFS - O(states)
#define _BFS_ROWS 1
#define _BFS_COLS 1
int bfsmatrix[_BFS_ROWS][_BFS_COLS];
bool _BFSvalidMove(int fR, int fC, int dR, int dC){
   cout << "NEED TO PUT SOME MORE CODE HERE" << fR << " " << fC << " " << dR << " " << dC << endl;
   return true;
}
int bfs(int r, int c, int numRows, int numCols, int targetR=INF, int targetC=INF){
       memset(bfsmatrix,-1,sizeof(bfsmatrix));
       queue<int>left; left.push(r); left.push(c); bfsmatrix[r][c] = 0; if(targetR==0&&targetC==0) return 0;
       while(!left.empty()){
         int tR, tC, d, nR, nC; tR =left.front(); left.pop(); tC = left.front(); left.pop(); d = bfsmatrix[tR][tC];
         FOR(i,0,4){
             nR = tR + dr4[i], nC = tC + dc4[i]; if(nR<0||nC<0||nR>=numRows||nC>=numCols||bfsmatrix[nR][nC]!=-1||!_BFSvalidMove(tR,tC,nR,nC)) continue;
             bfsmatrix[nR][nC]=(d+1); left.push(nR); left.push(nC); if(nR==targetR&&nC==targetC) return d+1;
         }
      }
      return -1;
}
// END CUT - BFS

//BEGIN CUT - Binary Indexed Tree - O(log(V))
#define _BIT_SIZE 1
long long _BIT_freq[_BIT_SIZE];
void bit_init(){ MEMSET(_BIT_freq,0);}
long long bit_getCumulative(int pos){ pos++; assert(pos>=0 && pos<_BIT_SIZE); long long ret = 0; while(pos>0){ ret += _BIT_freq[pos]; pos -= (pos & -pos);}return ret;}
long long bit_getSingular(int pos){ pos++; assert(pos>=0 && pos<_BIT_SIZE); long long ret = _BIT_freq[pos]; if(pos > 0){ int z = pos - (pos & -pos); pos--; while(pos!=z){ ret -= _BIT_freq[pos]; pos -= (pos & -pos);}}return ret;}
bool bit_update(int pos, long long delta){ pos++; if(pos<1 || pos>=_BIT_SIZE) return false; while(pos < _BIT_SIZE){ _BIT_freq[pos] += delta; pos += (pos&-pos);}return true;}
        /* find smallest x such that c[x] >= cumFre */
long long bit_find(int cumFre){ long long pos = 0, bitMask=0; FOR(i,0,64) if(SHIFT(i)>=_BIT_SIZE) break; else if(SHIFT(i) & (_BIT_SIZE-1)) bitMask = SHIFT(i); int ret = _BIT_SIZE;while ((bitMask != 0) && (pos < _BIT_SIZE)){  int mid = pos + bitMask; if(mid < _BIT_SIZE){  if (cumFre > _BIT_freq[mid]){ pos = mid; cumFre -= _BIT_freq[mid];}  else ret = min(ret,mid);} bitMask >>= 1;}if(ret == _BIT_SIZE) return -1;return ret-1;}
// END CUT - Binay Indexed Tree

// BEGIN CUT - Binary Search - O(logN) - find the point where it goes from untrue to true... always false at low
long long  binarySearch(long long  low, long long high, bool (* _target) (long long t1)){ while(low < high){ long long mid = low + (high - low) / 2; if(_target(mid)) high = mid; else low = mid+1;} return low;}
long double binarySearch(long double low, long double high, bool (* _target) (long double t1)){ while(low < high-eps){ long double mid = low + (high - low) / 2.0; if(_target(mid)) high = mid; else low = mid; }return low;}
// END CUT - Binary Search

//BEGIN CUT - BitStuff
int numBits(unsigned long long v) {return __builtin_popcount(v>>32) + __builtin_popcount(v & ((SHIFT(32)-1)));}
int highestBit(unsigned long long v) { return (v==0)?-1:(((v>>32)!=0)?63-__builtin_clz(v>>32):31-__builtin_clz(v));}
int lowestBit(unsigned long long v) { return (v==0)?-1:((((v>>32)<<32)==v)?32 + __builtin_ctz(v>>32):__builtin_ctz(v));}
inline void flip(long long &m, int v) { m ^= SHIFT(v);}
inline void flip(int &m, int v) { assert(v<32); m ^= SHIFT(v);}
bitset<8> toBinary(char c) { return bitset<8>(c);}
bitset<32> toBinary(int n) { return bitset<32>(n);}
bitset<64> toBinary(long long n){ return bitset<64>(bitset<64>(n) | (bitset<64>(n>>32)<<32));}
//END CUT - BitStuff

//BEGIN CUT - Choose Function - O(min(B,T-B)^2)
long long choose(long long T, long long B){ long long ret = 1;  vector<long long> top, bottom; if(T<B || B<0) return -1; B = min(B,T-B); FOR(i,0,B){ top.push_back(T-i); bottom.push_back(i+1); } FOR(i,0,top.size()) FOR(j,0,bottom.size()){ if(top[i]==1) break; long long g = gcd(top[i],bottom[j]); top[i]/=g; bottom[j]/=g; if(bottom[j]==1){ swap(bottom[bottom.size()-1],bottom[j--]); bottom.pop_back();} } FOR(i,0,top.size()) ret*=top[i]; return ret;}
// END CUT - Choose Function

// BEGIN CUT - Concatenate - O(N)
string concatenate(vector<string> &str){ string s; FOR(i,0,str.size()) s += str[i]; return s;}
// END CUT - Concatenate

//BEGIN CUT - Disjoint Set Forest - O(m*a(n))		NOTE: First Convert to indeces on the range (0.._MAX_DJSFSIZE]
#define _MAX_DJSFSIZE 1
int _djsParent[_MAX_DJSFSIZE], _djsRank[_MAX_DJSFSIZE];
void djs_init(){ MEMSET(_djsParent,-1); MEMSET(_djsRank,-1);}
bool djs_makeset(int pos){ if(pos < 0 || pos>=_MAX_DJSFSIZE || _djsParent[pos]!=-1) return false;_djsParent[pos]=pos; _djsRank[pos]=0; return true;}
int djs_findset(int pos){ if(_djsParent[pos]!=pos){ _djsParent[pos] = djs_findset(_djsParent[pos]);} return _djsParent[pos];}
bool djs_union(int posA, int posB){ int pA = djs_findset(posA), pB = djs_findset(posB); if(pA==pB) return false; if(_djsRank[pA]>_djsRank[pB]) _djsParent[pB] = pA; else if(_djsRank[pB]>_djsRank[pA]) _djsParent[pA]=pB; else _djsParent[pA]=pB, _djsRank[pA]++; return true;}
//END CUT - Disjoing Set Forest

// BEGIN CUT - Fast Fourier Transform - O(n lg n)
void polyToDFT(vector<complex<long double> >&A, bool inverse){  if(A.size() == 1) return; complex<long double> wn(cos(2*PI/A.size()),sin(2*PI/A.size())), w(1); if(inverse) wn.imag() = -wn.imag(); vector<complex<long double> > A0, A1; FOR(i,0,A.size()) if(i&1) A1.push_back(A[i]); else A0.push_back(A[i]); polyToDFT(A0,inverse), polyToDFT(A1,inverse); FOR(k,0,A.size()/2){ A[k] = A0[k] + w*A1[k]; A[k+A.size()/2] = A0[k] - w*A1[k]; if(inverse) A[k]/=2, A[k+A.size()/2]/=2; w = w * wn;}}
vector<complex<long double> > fft(vector<complex<long double> > &A, vector<complex<long double> > &B){ while(A.size() < B.size()) A.push_back(0); while(B.size() < A.size()) B.push_back(0);  while(A.size() & (A.size()-1)) A.push_back(0), B.push_back(0); FOR(i,0,A.size()) B.push_back(0); while(A.size() < B.size()) A.push_back(0); polyToDFT(A,false), polyToDFT(B,false); vector<complex<long double> > Cy; FOR(i,0,A.size()) Cy.push_back(A[i]*B[i]); polyToDFT(Cy,true); return Cy;}
// END CUT - Fast Fourier Transform

// BEGIN CUT - Flood Fill - O(elements)
#define _FLD_ROWS 1
#define _FLD_COLS 1
bool floodmatrix[_FLD_ROWS][_FLD_COLS];
void initFlood(){ MEMSET(floodmatrix,false);}
int flood(int r, int c, int nR, int nC, bool (*invalid)(int,int)){ if(r<0 || c<0 || r>=nR || c>=nC || floodmatrix[r][c] || invalid(r,c)) return 0; floodmatrix[r][c] = true; int ret =1;      FOR(i,0,4) ret += flood(r+dr4[i],c+dc4[i],nR,nC,invalid); return ret;}
// END CUT - Flood Fill

//BEGIN CUT - Fraction structure
struct frac{
public:   frac(long long A=0, long long B=1):num(A), denom(B){} frac operator=(const frac &rhs) { this->num = rhs.num; this->denom = rhs.denom; return reduce();}
   frac operator*(const frac & rhs){ if(num==0||rhs.num==0) return frac(); long long g1=gcd(abs(num),rhs.denom), g2=gcd(denom,abs(rhs.num)); return frac((num/g1)*(rhs.num/g2),(denom/g2)*(rhs.denom/g1));} frac operator*=(const frac &rhs){return (*this)=operator*(rhs);}
   frac operator+(const frac &rhs){long long _lcm = lcm(denom,rhs.denom); return frac(num*(_lcm/denom) + rhs.num*(_lcm/rhs.denom),_lcm).reduce();} frac operator+=(const frac &rhs){return (*this)=operator+(rhs);}
   frac operator-(const frac &rhs){ return (*this)+frac(-rhs.num,rhs.denom);} frac operator-=(const frac &rhs){return (*this)=operator-(rhs);}
   frac operator/(const frac &rhs){ assert(rhs.num!=0); return (*this)*frac(rhs.denom,rhs.num);} frac operator/=(const frac &rhs){return (*this)=operator/(rhs);}
   bool operator==(frac rhs){ rhs.reduce(); return num==rhs.num && denom==rhs.denom;} bool operator!=(const frac & rhs) { return !((*this)==rhs);}
   bool operator<(const frac &rhs){ long long _lcm = lcm(denom,rhs.denom); return num * (_lcm/denom) < rhs.num * (_lcm/rhs.denom);} bool operator<=(const frac &rhs) { return (*this)==rhs || (*this) < rhs;}
   bool operator>(const frac &rhs){ return !((*this) <= rhs);} bool operator>=(const frac &rhs){ return !((*this)<rhs);}
   frac reduce() { long long g = gcd(num,denom); if(g>1){num/=g,denom/=g;} return (*this);} string toString(){stringstream ss; ss << num << "/" << denom; return ss.str();}
private:    long long num, denom;
};
//END CUT - fraction structure

// BEGIN CUT - Geometry Library = O(dimensions)
template <class T>
T distanceSquared(const vector<T> &p1, const vector<T> &p2){ T ret = 0; FOR(i,0,p1.size()) ret += SQ(p2[i] - p1[i]); return ret;}
template <class T>
inline T distanceSquared(const pair<T,T> p1, const pair<T,T> p2){ return SQ(p2.first - p1.first) + SQ(p2.second - p1.second);}
bool line_intersection2D(const vector<long double> &p1, const vector<long double> &p2, const vector<long double> &q1, const vector<long double> &q2, vector<long double> &r, bool &colinear){ colinear = false; r = vector<long double>(2,0); long double N1, N2, D, u1, u2; N1 = (q2[0] - q1[0]) * (p1[1] - q1[1]) - (q2[1] - q1[1]) * (p1[0] - q1[0]); N2 = (p2[0] - p1[0]) * (p1[1] - q1[1]) - (p2[1] - p1[1]) * (p1[0] - q1[0]);  D  = (q2[1] - q1[1]) * (p2[0] - p1[0]) - (q2[0] - q1[0]) * (p2[1] - p1[1]); if(fabs(D) > eps) { u1 = N1 / D; u2 = N2/D; if(u1 < -eps || u1 > 1+eps || u2 < -eps || u2 > 1+eps) return false; r[0] = p1[0] + (p2[0] - p1[0]) * u1;  r[1] = p1[1] + (p2[1] - p1[0]) * u1; return true;}  if(fabs(N1) > eps && fabs(N2) > eps) return false; else colinear = true; if(p1[0] >= min(q1[0],q2[0]) && p1[0] <= max(q1[0],q2[0]) && p1[1] >= min(q1[1],q2[1]) && p1[1] <= max(q1[1],q2[1]))  { r = p1; return true;}  if(p2[0] >= min(q1[0],q2[0]) && p2[0] <= max(q1[0],q2[0]) && p2[1] >= min(q1[1],q2[1]) && p2[1] <= max(q1[1],q2[1]))  { r = p2; return true;} return false;}
bool line_intersection2D(const pair<long double, long double> &p1, const pair<long double,long double> &p2, const pair<long double,long double> &q1, const pair<long double,long double> &q2, pair<long double, long double> &r, bool &colinear){ vector<long double> pv1(2), pv2(2), qv1(2), qv2(2), rv; pv1[0] = p1.first; pv1[1] = p1.second; pv2[0] = p2.first; pv2[1] = p2.second; qv1[0] = q1.first; qv1[1] = q1.second; qv2[0] = q2.first; qv2[1] = q2.second; bool ret = line_intersection2D(pv1,pv2,qv1,qv2,rv,colinear); r.first = rv[0]; r.second = rv[1]; return ret;}
template <class T>
T dot_product(const vector<T> &p1, const vector<T> &p2){ T ret = 0; FOR(i,0,p1.size()) ret += p1[i] * p2[i];  return ret; }
template <class T>
vector<T> cross_product(const vector<T> &p1, const vector<T> &p2){ vector<T> ret(3);    ret[0] = p1[1] * p2[2] - p1[2] * p2[1]; ret[1] = p1[2] * p2[0] - p1[0] * p2[2]; ret[2] = p1[0] * p2[1] - p1[1] * p2[0]; return ret; }
template <class T>
vector<T> cross_product(const pair<T,T> &p1, const pair<T,T> &p2){ vector<T> v1(3), v2(3); v1[0] = p1.first; v1[1] = p1.second; v2[0] = p2.first; v2[1] = p2.second; return cross_product(v1,v2);}
// END CUT - Geometry Library

// BEGIN CUT - Graph Manipulation - O(elements)
vector<string> rotateR(const vector<string> &orig){ vector<string> ret(orig[0].length()); FOR(i,0,orig[0].length()) FOR(j,0,orig.size()) ret[i].push_back(orig[orig.size()-j-1][i]); return ret;}
vector<string> flipH(const vector<string> &orig){ vector<string> ret = orig; FOR(i,0,orig.size()) FOR(j,0,orig[0].length()) ret[i][j] = orig[i][orig.size()-j-1]; return ret;}
// END CUT - Graph Manipulation

// BEGIN CUT - Linear Programming
const int LP_GTE=1, LP_LTE=-1, LP_EQ = 0, LP_MAX=1, LP_MIN=0;
struct slackForm{ int nV, nC; long double val; vector<int> nonBasic, basic; vector<vector<long double> > aCoef; vector<long double> bCoef, cCoef; slackForm(int v=0, int c=0):nV(v),nC(c),val(0){ nonBasic=vector<int>(nV), basic=vector<int>(nC),aCoef = vector<vector<long double> >(nC,vector<long double>(nV,0)),bCoef=vector<long double>(nC), cCoef=vector<long double>(nV,0);}};
struct linearProgrammer{
   int numVars; vector<int> minus; vector<bool> used, nnConstrained; vector<pair<long double, int> > mmEquation; int mmType; vector<vector<pair<long double, int> > > consEquations; vector<long double> consRHS; vector<int> consTypes;
   linearProgrammer(int nV):numVars(nV){minus = vector<int>(nV,-1); used = nnConstrained = vector<bool>(nV,false); mmType = LP_MAX;}
   void setMMType(int mmt){mmType=mmt;}
   bool addMMPair(long double coef, int index){ if(index>=numVars) return false; mmEquation.push_back(make_pair(coef,index)); used[index] = true; return true; }
   void addConsEquation(int type, long double rhs){ consEquations.push_back(vector<pair<long double, int> >()); consTypes.push_back(type);consRHS.push_back(rhs);}
   bool addConsPair(int index, long double coef, int var){ if(index>=consEquations.size() || var >= numVars) return false; consEquations[index].push_back(make_pair(coef,var)); used[var] = true; return true;}
   bool addNNConstraint(int index) { return(index>=numVars)?false:nnConstrained[index]=true;}
   void toStandard(){ if(mmType == LP_MIN) FOR(i,0,mmEquation.size()) mmEquation[i].first*=-1; mmType = LP_MAX; FOR(i,0,numVars) if(!used[i]) nnConstrained[i] = true; else if(!nnConstrained[i]){ minus.push_back(-1), nnConstrained.push_back(true), used.push_back(true); minus[i] = numVars++; nnConstrained[i] = true; FOR(j,0,mmEquation.size()) if(mmEquation[j].second==i) addMMPair(-mmEquation[j].first,numVars-1); FOR(j,0,consEquations.size()) FOR(k,0,consEquations[j].size()) if(consEquations[j][k].second==i) addConsPair(j,-consEquations[j][k].first,numVars-1); } FOR(i,0,consEquations.size()){ if(consTypes[i] == LP_EQ){ consTypes.push_back(LP_GTE); consRHS.push_back(consRHS[i]); consEquations.push_back(consEquations[i]); } else if(consTypes[i] == LP_GTE){ consRHS[i] = -consRHS[i]; FOR(j,0,consEquations[i].size()) consEquations[i][j].first*=-1; } consTypes[i] = LP_LTE;}}
   slackForm toSlack(){ toStandard(); slackForm sf(numVars,consEquations.size()); FOR(i,0,numVars) sf.nonBasic[i] = i; FOR(i,0,consEquations.size()){ sf.basic[i] = numVars+i; sf.bCoef[i] = consRHS[i]; FOR(j,0,consEquations[i].size()) sf.aCoef[i][consEquations[i][j].second] += consEquations[i][j].first;} FOR(i,0,mmEquation.size()) sf.cCoef[mmEquation[i].second] += mmEquation[i].first; return sf;}
};
slackForm pivot(const slackForm &input, int rowL, int colE){ slackForm output = input; output.bCoef[rowL] = input.bCoef[rowL] / input.aCoef[rowL][colE]; FOR(i,0,input.nV) if(i!=colE) output.aCoef[rowL][i] = input.aCoef[rowL][i] / input.aCoef[rowL][colE]; output.aCoef[rowL][colE] = 1 / input.aCoef[rowL][colE]; FOR(i,0,input.nC) if(i!=rowL){ output.bCoef[i] = input.bCoef[i] - input.aCoef[i][colE] * output.bCoef[rowL]; FOR(j,0,input.nV) if(j!=colE) output.aCoef[i][j] = input.aCoef[i][j] - input.aCoef[i][colE] * output.aCoef[rowL][j]; output.aCoef[i][colE] = -input.aCoef[i][colE] * output.aCoef[rowL][colE];} output.val = input.val + input.cCoef[colE] * output.bCoef[rowL];FOR(i,0,input.nV) if(i!=colE) output.cCoef[i] = input.cCoef[i] - input.cCoef[colE] * output.aCoef[rowL][i]; output.cCoef[colE] = -input.cCoef[colE] * output.aCoef[rowL][colE]; output.nonBasic[colE] = input.basic[rowL], output.basic[rowL] = input.nonBasic[colE]; return output;}
void simplexValidSlack(slackForm & sF, vector<long double> & xArray, bool &bounded, long double &value){ bounded = true; int posit = -1; FOR(i,0,sF.nV) if(sF.cCoef[i]>eps){ posit=i; break;} while(posit!=-1){ int bestI = -1; long double bestV = 0; bool zeroed = false; int trying = posit; while(trying < sF.nV){ if(sF.cCoef[trying]<eps || sF.nonBasic[trying] > sF.nonBasic[posit]){trying++;continue;} int tBestI = -1; FOR(i,0,sF.basic.size()) if(sF.aCoef[i][trying] > eps){ long double value = sF.bCoef[i] / sF.aCoef[i][trying];  if(zeroed){ if(sF.bCoef[i] < eps && (tBestI == -1 || sF.basic[tBestI] > sF.basic[i])) tBestI = i;continue; } else if(sF.bCoef[i] < eps) {zeroed=true, tBestI = i; continue;} if(tBestI == -1) tBestI = i, bestV = value; else if(bestV > value) bestV = value, tBestI=i;} if(tBestI != -1 || !zeroed) bestI = tBestI, posit = trying; if(!zeroed && bestI != -1) break; trying++;} if(!zeroed && bestI == -1) { bounded = false; return;} sF = pivot(sF,bestI,posit); posit=-1; FOR(i,0,sF.nV) if(sF.cCoef[i]>eps){ posit=i; break;}} xArray = vector<long double>(sF.nV,0); FOR(i,0,sF.bCoef.size()) if(sF.basic[i]<sF.nV) xArray[sF.basic[i]]=sF.bCoef[i]; value = sF.val;}
void initializeSimplex(linearProgrammer standard, slackForm & retSF, bool &feasible){ slackForm stSlack = standard.toSlack(); feasible = true; int mnIndex = 0; FOR(i,1,standard.consEquations.size()) if(standard.consRHS[mnIndex] > standard.consRHS[i]) mnIndex = i; if(standard.consRHS[mnIndex] > -eps) { retSF = stSlack; return;} linearProgrammer aux(standard.numVars+1); aux.setMMType(LP_MAX); aux.addMMPair(-1,standard.numVars); aux.consEquations = standard.consEquations; aux.consTypes = standard.consTypes; aux.consRHS = standard.consRHS; FOR(i,0,aux.consEquations.size()) aux.addConsPair(i,-1,standard.numVars); aux.addNNConstraint(standard.numVars); retSF = pivot(aux.toSlack(),mnIndex,standard.numVars); vector<long double> xArray; bool bounded; long double value; simplexValidSlack(retSF,xArray,bounded,value); if(!bounded || abs(value) > eps){ feasible = false; return;} FOR(i,0,retSF.nV) if(retSF.nonBasic[i]==standard.numVars){ FOR(j,0,retSF.nC) retSF.aCoef[j].erase(retSF.aCoef[j].begin()+i); retSF.nonBasic.erase(retSF.nonBasic.begin() + i); retSF.nV--; break;} retSF.cCoef = vector<long double>(retSF.nV,0); retSF.val = 0; FOR(i,0,retSF.nV) if(retSF.nonBasic[i] < retSF.nV) retSF.cCoef[i] += stSlack.cCoef[retSF.nonBasic[i]]; FOR(i,0,retSF.nC) if(retSF.basic[i] < retSF.nV){ FOR(j,0,retSF.nV) retSF.cCoef[j] += -stSlack.cCoef[retSF.basic[i]] * retSF.aCoef[i][j]; retSF.val += retSF.bCoef[i] * stSlack.cCoef[retSF.basic[i]]; }}
void simplex(const linearProgrammer & original, vector<long double> & xArray, bool &feasible, bool & bounded, long double &value){ bounded = true; feasible = true; linearProgrammer standard = original; standard.toStandard(); if(standard.consEquations.size()==0) FOR(j,0,standard.mmEquation.size()) if(standard.mmEquation[j].first>0){ bounded = false; break; }  if(!bounded) return; slackForm sF; initializeSimplex(standard,sF,feasible); if(!feasible) return; simplexValidSlack(sF,xArray,bounded,value); FOR(i,0,original.numVars){ int next = standard.minus[i]; if(next!=-1) xArray[i] -= xArray[next];} xArray.resize(original.numVars); value = 0; FOR(i,0,original.mmEquation.size()) value += original.mmEquation[i].first * xArray[original.mmEquation[i].second];}
// END CUT - Linear Programming

// BEGIN CUT - Matrix Multiplication/Exponentiation - O(N^3) / O(N^3logP)
template <class T>
vector<vector<T> > matrixMultiply(const vector<vector<T> > & A, const vector<vector<T> > &B){ int nR = A.size(), nC = B[0].size(), com = B.size();  vector<vector<T> > retMatrix; if(A[0].size() != com) cerr << "Fatal Matrix Error" << endl, exit(0); FOR(i,0,nR){ vector<T> row; FOR(j,0,nC){ T sum = 0; FOR(k,0,com) sum += A[i][k] * B[k][j]; row.push_back(sum);} retMatrix.push_back(row); } return retMatrix;}
template <class T>
vector<vector<T> > matrixExponentiate(vector<vector<T> > matrix, int power){ if(power == 1) return matrix; int size = matrix.size(); vector<vector<T> > current(size,vector<T>(size,0)); FOR(i,0,size) current[i][i] = 1; while(power > 0){ if(power & 1) current = matrixMultiply(current,matrix); matrix = matrixMultiply(matrix,matrix); power >>=1;   } return current;}
template <class T>
vector<vector< T> > matrixTranspose(vector<vector<T> > matrix){}
//END CUT - Matrix Multiplication/Exponentiation

// BEGIN CUT - Maxflow [DFS -> O(E * maxflow), BFS -> O(E^2*V), Shotest Path -> O(E*V^2)]
//	     - MinCostMaxFlow O(V*E*B log V)
#define MF_VERTEX_SIZE 1
#define MF_EDGE_SIZE 1

enum {DFS=0,BFS,SHORTEST};

template<class T, class S>
class FlowNetwork{
public:
  T aug_path_dfs(int cur, int snk, T &lowest){ if(snk == cur) return lowest; T tlowest = lowest;  if(_MFparent[cur] == -1) _MFparent[cur] = -2;  ITER(it,_MFadjlist[cur]){  int tedge = (it->second).first, dir = (it->second).second, tnext = it->first; if(dir && _MFflow[tedge] >= _MFcapacity[tedge] || !dir && _MFflow[tedge]==0 || _MFparent[tnext]!=-1) continue;  lowest = min(tlowest,dir?_MFcapacity[tedge]-_MFflow[tedge]:_MFflow[tedge]); _MFparent[tnext] = cur; if(aug_path_dfs(tnext,snk,lowest)){ _MFflow[tedge] += dir?lowest:-lowest; return lowest;  }}  return 0; }
  T aug_path_bfs(int src, int snk, T &lowest){ T ret = 0; while(true){  memset(_MFparent,-1,sizeof(_MFparent)); _MFparent[src] = -2;  memset(_MFpedge,-1,sizeof(_MFpedge)); _MFpedge[src] = make_pair(-2,true);  queue<int> q; q.push(src); queue<T> p; p.push(lowest); T tmp = 0; while(!q.empty()){  int c = q.front(); q.pop();  T clow = p.front(); p.pop();  if(c == snk) { tmp = clow; break;}   ITER(it,_MFadjlist[c]){  int tedge = (it->second).first, dir = (it->second).second, tnext = it->first;  if(dir && _MFflow[tedge] >= _MFcapacity[tedge] || !dir && _MFflow[tedge]==0 || _MFparent[tnext]!=-1) continue;   _MFparent[tnext] = c; _MFpedge[tnext] = make_pair(tedge,dir);  p.push(min(clow,dir?_MFcapacity[tedge] - _MFflow[tedge]:_MFflow[tedge]));  q.push(tnext); }  }  if(tmp==0) break;  ret += tmp;   int c = snk;  while(c != src){ _MFflow[_MFpedge[c].first] += (_MFpedge[c].second)?tmp:-tmp; c = _MFparent[c]; }  } return ret;  }
  T aug_path_shortest(int src, int snk, T &lowest){ memset(_MFsnkdist,-1,sizeof(_MFsnkdist)); _MFsnkdist[snk] = 0; queue<int> q; q.push(snk);  set<pair<int,pair<int,bool> > >::iterator itarray[MF_VERTEX_SIZE]; int N = 0;  while(!q.empty()){ int c = q.front(); q.pop();  itarray[c] = _MFadjlist[c].begin(); N++;  ITER(it,_MFadjlist[c]){   int tedge = (it->second).first, dir = (it->second).second , tnext = it->first;  if(_MFsnkdist[tnext]!=-1 || !dir &&  _MFflow[tedge] >= _MFcapacity[tedge] || dir && _MFflow[tedge]==0) continue;  _MFsnkdist[tnext] = _MFsnkdist[c]+1; q.push(tnext);  }  }  if(_MFsnkdist[src]==-1) return 0; memset(_MFparent,-1,sizeof(_MFparent));  memset(_MFpedge,-1,sizeof(_MFpedge));  _MFparent[src] = -2; _MFpedge[src] = make_pair(-2,true); int cur = src, ret = 0;  while(_MFsnkdist[src] < N){  bool any = false;   for(set<pair<int,pair<int,bool> > >::iterator it=itarray[cur];it!=_MFadjlist[cur].end();it++){  itarray[cur]++;  int tedge = (it->second).first, dir = (it->second).second, tnext = it->first;  if(dir && _MFflow[tedge] >= _MFcapacity[tedge] || !dir && _MFflow[tedge]==0 || _MFsnkdist[cur] != _MFsnkdist[tnext]+1 || _MFsnkdist[tnext]==-1) continue;   any = true; _MFparent[tnext] = cur; _MFpedge[tnext] = make_pair(tedge,dir); cur = tnext;  if(cur == snk){ int tc = cur, low = lowest;  while(tc!=src){  low = min(low,_MFpedge[tnext].second?_MFcapacity[_MFpedge[tnext].first] - _MFflow[_MFpedge[tnext].first]:_MFflow[_MFpedge[tnext].first]);  tc = _MFparent[tc]; }  while(cur != src){  _MFflow[_MFpedge[cur].first] += _MFpedge[cur].second?low:-low;  cur = _MFparent[cur]; }  ret += low;  }  break; }  if(!any){  int low = N;  ITER(it,_MFadjlist[cur]){  int tedge = (it->second).first, dir = (it->second).second, tnext = it->first;  if(dir && _MFflow[tedge] >= _MFcapacity[tedge] || !dir && _MFflow[tedge]==0 || _MFsnkdist[tnext]==-1) continue;  low = min(low,_MFsnkdist[tnext]+1);  }  _MFsnkdist[cur] = low; itarray[cur] = _MFadjlist[cur].begin(); if(cur != src) cur = _MFparent[cur]; } } return ret; }
  bool _MFbellmanFord(vector<S> &dist, int start, const vector<int> mapping){ int N = mapping.size(); dist = vector<S>(N,INF); MEMSET(_MFparent,-1); dist[mapping[start]] = 0; int hash[MF_VERTEX_SIZE]; FOR(i,0,mapping.size()) hash[mapping[i]] = i; long long c = 0; FOR(i,0,N) c += _MFadjlist[mapping[i]].size(); FOR(k,0,N-1){  bool any = false; FOR(i,0,N) ITER(it,_MFadjlist[mapping[i]]){ int tedge = (it->second).first, dir = (it->second).second, tnext = it->first; if(dir && _MFflow[tedge] >= _MFcapacity[tedge] || !dir && _MFflow[tedge]==0) continue; if(dist[i] + (dir?_MFcost[tedge]:-_MFcost[tedge]) < dist[hash[tnext]]){ dist[hash[tnext]] = dist[i] + (dir?_MFcost[tedge]:-_MFcost[tedge]);  _MFparent[tnext] = mapping[i]; _MFpedge[tnext] = make_pair(tedge,dir); any = true; } } if(!any) break; } FOR(i,0,N) ITER(it,_MFadjlist[mapping[i]]){ int tedge = (it->second).first, dir = (it->second).second, tnext = it->first; if(dir && _MFflow[tedge] >= _MFcapacity[tedge] || !dir && _MFflow[tedge]==0) continue; if(dist[hash[tnext]] > dist[i] + (dir?_MFcost[tedge]:-_MFcost[tedge])) return false;  } return true;}
  void _MFdijkstra(vector<S> &dist, int start, const vector<int> mapping){ int N = mapping.size(); dist = vector<S>(N,INF); dist[start] = 0; int hash[MF_VERTEX_SIZE]; FOR(i,0,mapping.size()) hash[mapping[i]] = i; vector<int> hPos(N); vector<pair<S,int> > heap; FOR(i,0,N) heap.push_back(make_pair(dist[i],i)); make_heap(BEGEND(heap),greater<pair<int,S> >());  FOR(i,0,N) hPos[heap[i].second] = i;  while(heap.size() > 0){  pair<S,int> lowest = heap[0]; swap(heap[0],heap[heap.size()-1]); swap(hPos[heap[0].second], hPos[heap[heap.size()-1].second]); heap.pop_back(); if(lowest.first == INF) break; int pos = 1;  while(pos*2 <= heap.size() && (heap[pos-1] > heap[pos*2-1] || pos*2<heap.size() && heap[pos-1] > heap[pos*2])){   if(pos*2 == heap.size() || heap[pos*2] >= heap[pos*2-1]){  swap(heap[pos-1],heap[pos*2-1]); swap(hPos[heap[pos-1].second],hPos[heap[pos*2-1].second]);  pos = pos*2; } else { swap(heap[pos-1],heap[pos*2]); swap(hPos[heap[pos-1].second],hPos[heap[pos*2].second]); pos = pos*2+1;}  }  ITER(it,_MFadjlist[mapping[lowest.second]]){ int tedge = (it->second).first, dir = (it->second).second, tnext = it->first; if(dir && _MFflow[tedge] >= _MFcapacity[tedge] || !dir && _MFflow[tedge]==0) continue; if(dist[lowest.second] + (dir?_MFcost[tedge]:0) < dist[hash[tnext]]){  dist[hash[tnext]] = dist[lowest.second] + (dir?_MFcost[tedge]:0);  _MFparent[tnext] = mapping[lowest.second]; _MFpedge[tnext] = make_pair(tedge,dir); int p = hPos[hash[tnext]];  heap[p].first = dist[hash[tnext]]; while(p > 0 && heap[p] < heap[((p+1)>>1)-1]){ swap(heap[p],heap[((p+1)>>1)-1]); swap(hPos[heap[p].second],hPos[heap[((p+1)>>1)-1].second]);  p = (((p+1)>>1)-1); } } } } }

  T getFunction(int src, int snk, int fun, T low = 1000000000){ switch(fun){  case DFS: return aug_path_dfs(src,snk,low);  case BFS: return aug_path_bfs(src,snk,low); case SHORTEST: return aug_path_shortest(src,snk,low); default: return 0;} }

  pair<T,S> minCostMaxFlow(int src, int snk, bool negative=false){ vector<S> dist, pot(MF_VERTEX_SIZE,0); S tmpCost[MF_EDGE_SIZE]; memcpy(tmpCost,_MFcost,sizeof(_MFcost));  vector<int> mapping; FOR(i,0,MF_VERTEX_SIZE) if(_MFadjlist[i].size() > 0) mapping.push_back(i); int hash[MF_VERTEX_SIZE]; FOR(i,0,mapping.size()) hash[mapping[i]] = i;  if(negative && !_MFbellmanFord(pot,src,mapping)) return make_pair(-1,-1); FOR(i,0,mapping.size()) ITER(it,_MFadjlist[mapping[i]]){  int tedge = (it->second).first, dir = (it->second).second, tnext = it->first; if(dir && _MFflow[tedge] >= _MFcapacity[tedge] || !dir) continue;  _MFcost[tedge] += pot[i] - pot[hash[tnext]]; }	 T ret = 0; while(true){  memset(_MFparent,-1,sizeof(_MFparent)); _MFdijkstra(dist,src,mapping); if(_MFparent[snk] == -1) break; pot = dist; FOR(i,0,mapping.size()) ITER(it,_MFadjlist[mapping[i]]){ int tedge = (it->second).first, dir = (it->second).second, tnext = it->first; if(dir && _MFflow[tedge] >= _MFcapacity[tedge] || !dir) continue;  _MFcost[tedge] += pot[i] - pot[hash[tnext]]; }	 T tCap = INF; int c = snk; while(c != src){ tCap = min(tCap,_MFpedge[c].second?(_MFcapacity[_MFpedge[c].first]-_MFflow[_MFpedge[c].first]):_MFflow[_MFpedge[c].first]); c = _MFparent[c];} c = snk; while(c != src){ _MFflow[_MFpedge[c].first] += _MFpedge[c].second?tCap:-tCap; c = _MFparent[c]; } ret += tCap; } memcpy(_MFcost,tmpCost,sizeof(_MFcost)); S cost = 0; FOR(i,0,MF_EDGE_SIZE) if(_MFflow[i] > 0) cost += _MFflow[i] * _MFcost[i]; return make_pair(ret,cost); }
  T maxFlow(int src, int snk, int fun){ assert(MF_VERTEX_SIZE!=1 && MF_EDGE_SIZE!=1); T ret = 0; while(true){ memset(_MFparent,-1,sizeof(_MFparent)); T val = getFunction(src,snk,fun); if(val == 0) break; ret+=val;} return ret; }
  S hungarian(int src, int snk){ return src+snk;}

  void initMF(){ assert(MF_EDGE_SIZE!=1 && MF_VERTEX_SIZE!=1); memset(_MFflow,0,sizeof(_MFflow)); memset(_MFcapacity,0,sizeof(_MFcapacity)); FOR(i,0,MF_VERTEX_SIZE) _MFadjlist[i].clear(); _MFedgehash.clear();}
  void reset(){ memset(_MFflow,0,sizeof(_MFflow));}
  void removeMFConnection(int left, int right){ if(_MFedgehash.count(make_pair(left,right)) == 0) return; int e = _MFedgehash[make_pair(left,right)]; _MFflow[e] = 0; _MFcapacity[e] = 0; _MFadjlist[left].erase(make_pair(right,make_pair(e,true))); _MFadjlist[right].erase(make_pair(left,make_pair(e,false)));}
  void addMFConnection(int left, int right, T cap, S cost=0){ int e; if(_MFedgehash.count(make_pair(left,right)) == 0){ e = _MFedgehash[make_pair(left,right)] = _MFedgehash.size()-1; _MFadjlist[left].insert(make_pair(right,make_pair(e,true))); _MFadjlist[right].insert(make_pair(left,make_pair(e,false))); } else e = _MFedgehash[make_pair(left,right)]; _MFflow[e] = 0; _MFcapacity[e] = cap; _MFcost[e]=cost;}

private:
  set<pair<int,pair<int,bool> > > _MFadjlist[MF_VERTEX_SIZE];
  map<pair<int,int>,int> _MFedgehash;
  T _MFflow[MF_EDGE_SIZE], _MFcapacity[MF_EDGE_SIZE];
  S _MFcost[MF_EDGE_SIZE];
  int _MFparent[MF_VERTEX_SIZE], _MFsnkdist[MF_VERTEX_SIZE];
  pair<int,bool> _MFpedge[MF_VERTEX_SIZE];
};
// END CUT - Max Flow

// BEGIN CUT - Primality Functions
#define _SE_SIZE 1LL
bitset<_SE_SIZE> prime; void runSieve(){ assert(_SE_SIZE != 1); prime = 0; prime.flip(); prime[0] = prime[1] = 0; for(int i=4;i<_SE_SIZE; i+=2) prime[i]=0; for(long long i=3;i*i<_SE_SIZE; i+=2) if(prime[i]) for(int j=i*i;j<_SE_SIZE;j+=i) prime[j]=0;}
vector<int> primes;     void buildPrimes(){ primes.clear(); FOR(i,2,_SE_SIZE) if(prime[i]) primes.push_back(i);}
vector<PAIR> factorize(long long val){ if(prime[val]) return vector<PAIR>(1,make_pair(val,1)); vector<PAIR> ret; FOR(i,0,primes.size()){ if(val % primes[i] != 0) continue; int cnt = 0; while(val % primes[i] == 0) cnt++, val /= primes[i]; if(cnt) ret.push_back(make_pair(primes[i],cnt)); if(prime[val]) { ret.push_back(make_pair(val,1)); break;} if(val == 1) break; } return ret; }
long long totient(long long val){ if(prime[val]) return val-1; vector<PAIR> f = factorize(val); long long ret = val; FOR(i,0,f.size()) ret = ret * (f[i].first-1) / f[i].first; return ret;}
// END CUT - Primality Functions

//BEGIN CUT - Set FUNCTIONS O(N)
template<class T>
void setIntersect(const set<T> &A, const set<T> &B, set<T> &C){ set_intersection(A.begin(),A.end(),B.begin(),B.end(),inserter(C,C.begin())); }
template<class T>
void setDifference(const set<T> &A, const set<T> &B, set<T> &C){ set_difference(A.begin(),A.end(),B.begin(),B.end(),inserter(C,C.begin()));}
//END CUT - Set FUNCTIONS

//BEGIN CUT - Strongly Connected Components O(V+E)
void tarjanSCCrecursive(const vector<vector<int> > &adj, vector<vector<int> > &results, int cur, int &cindex, vector<int> &mystack, vector<bool> &instack, vector<int> &indices, vector<int> &lowlinks){
   indices[cur] = lowlinks[cur] = cindex++;
   mystack.push_back(cur); instack[cur] = true;

   FOR(i,0,adj[cur].size()){
      int w = adj[cur][i];
      if(indices[w] == -1){
	   tarjanSCCrecursive(adj,results,w,cindex,mystack,instack,indices,lowlinks);
	   lowlinks[cur] = min(lowlinks[cur],lowlinks[w]);
      }
      else if(instack[w]) lowlinks[cur] = min(lowlinks[cur],indices[w]);
   }
   if(lowlinks[cur] == indices[cur]){
      vector<int> conn;
      int w;
      do{
         w = mystack.back(); mystack.pop_back();
	 instack[w] = false;
	 conn.push_back(w);
      }while(w != cur);
      sort(BEGEND(conn)); results.push_back(conn);
   }
}

template <class T>
void tarjanSCC(const vector<vector<pair<int,T> > > &adj, vector<vector<int> > &results){
   vector<vector<int> > adj2(adj.size()); FOR(i,0,adj.size()) FOR(j,0,adj[i].size()) adj2[i].push_back(adj[i][j].first);
   vector<bool> instack(adj.size(),false); vector<int>  mystack, indices(adj.size(),-1), lowlinks(adj.size(),-1); results.clear();
   int index = 0; FOR(i,0,adj.size()) if(indices[i] == -1) tarjanSCCrecursive(adj,results,i,index,mystack,instack,indices,lowlinks);
   sort(BEGEND(results));
}
//END CUT   - Strongly Connected Components

//BEGIN CUT - Shortest Path Algorithms [Floyd-Warshall O(V^3), Dijkstra O((E+V)lgV), Bellman-Ford O(V*E)]
void floydWarshall(vector<vector<bool> > &matrix){ int N = matrix.size(); FOR(c,0,N) FOR(a,0,N) FOR(b,0,N) matrix[a][b] = matrix[a][b] || matrix[a][c] && matrix[c][b];}
template <class T>
void floydWarshall(vector<vector<T> > &matrix){ int N = matrix.size(); FOR(c,0,N) FOR(a,0,N) FOR(b,0,N) if(matrix[a][c]!=-1 && matrix[c][b]!=-1 && (matrix[a][b] == -1 || matrix[a][b] > matrix[a][c]+matrix[c][b])) matrix[a][b] = matrix[a][c] + matrix[c][b];}
template<class T>
bool bellmanFord(const vector<vector<pair<int,T> > > &adj, vector<T> &dist, vector<int > &prev, int start){ int N = adj.size(); dist = vector<T>(N,INF), prev = vector<int>(N,-1); dist[start] = 0; FOR(k,0,N-1) { bool any =false; FOR(i,0,N) FOR(j,0,adj[i].size()) if(dist[i] + adj[i][j].second < dist[adj[i][j].first]){ any=true; dist[adj[i][j].first] = dist[i] + adj[i][j].second; prev[adj[i][j].first] = i;} if(!any) break;} FOR(i,0,N) FOR(j,0,adj[i].size()) if(dist[adj[i][j].first] > dist[i] + adj[i][j].second) return false; return true;}
template<class T>
void dijkstra(const vector<vector<pair<int,T> > > &adj, vector<T> &dist, vector<int > &prev, int start){ int N = adj.size(); dist = vector<T>(N,INF), prev = vector<int>(N,-1); dist[start] = 0; vector<int> hPos(N); vector<pair<T,int> > heap; FOR(i,0,N) heap.push_back(make_pair(dist[i],i)); make_heap(BEGEND(heap),greater<pair<int,T> >()); FOR(i,0,N) hPos[heap[i].second] = i; while(heap.size() > 0){ pair<T,int> lowest = heap[0]; swap(heap[0],heap[heap.size()-1]); swap(hPos[heap[0].second], hPos[heap[heap.size()-1].second]); heap.pop_back(); if(lowest.first == INF) break; int pos = 1; while(pos*2 <= heap.size() && (heap[pos-1] > heap[pos*2-1] || pos*2<heap.size() && heap[pos-1] > heap[pos*2])){ if(pos*2 == heap.size() || heap[pos*2] >= heap[pos*2-1]){ swap(heap[pos-1],heap[pos*2-1]); swap(hPos[heap[pos-1].second],hPos[heap[pos*2-1].second]); pos = pos*2;} else { swap(heap[pos-1],heap[pos*2]); swap(hPos[heap[pos-1].second],hPos[heap[pos*2].second]); pos = pos*2+1;} } FOR(i,0,adj[lowest.second].size()) if(dist[lowest.second] + adj[lowest.second][i].second < dist[adj[lowest.second][i].first]){ dist[adj[lowest.second][i].first] = dist[lowest.second] + adj[lowest.second][i].second; prev[adj[lowest.second][i].first] = lowest.second; int p = hPos[adj[lowest.second][i].first]; heap[p].first = dist[adj[lowest.second][i].first]; while(p > 0 && heap[p] < heap[((p+1)>>1)-1]){ swap(heap[p],heap[((p+1)>>1)-1]); swap(hPos[heap[p].second],hPos[heap[((p+1)>>1)-1].second]); p = (((p+1)>>1)-1);}}}}
//END CUT - Shortest Path Algorithms

// BEGIN CUT - Ternary Search - O(logN)
long long ternarySearch(long long low, long long high, bool (* _better) (long long t1, long long t2)){ while(low < high - 3){ long long p1 = low + (high - low) / 3, p2 = low + 2 * (high - low) / 3; if(_better(p1, p2)) high = p2; else low = p1; } if(_better(low,low+1)) return low; else if(_better(low+1,low+2)) return low+1; else if(_better(low+2,low+3)) return low+2; return low+3;}
long double ternarySearch(long double low, long double high, bool (* _better) (long double t1, long double t2)){ while(low < high-eps){ long double p1 = low + (high - low) / 3.0, p2 = low + 2 * (high - low) / 3.0; if(_better(p1, p2)) high = p2; else low = p1; } return low;}
// END CUT - Ternary Search

double prob[100002], each[100002];

int sofar, total;

double solve(){
    prob[0] = 1;
    FOR(j,0,sofar){
      cin >> each[j];
      prob[j+1] = prob[j] * each[j];
    }

    double ret = 2 + total;
    FOR(back,0,sofar){
	double gcost = 1 + back + total - (sofar-back);
	double bcost = gcost + total + 1;
	ret = min(ret,gcost * prob[sofar-back] + bcost * (1-prob[sofar-back]));
    }
    return ret;
}

int _T;
int main(){
  cin >> _T;
  FOR(i,0,_T){
    cout << "Case #" << (i+1) << ": ";
    cin >> sofar >> total;
    printf("%f",solve());
    cout << endl;
  }
  return 0;
}

