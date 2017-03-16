// compile with "g++ XXX.cc -mno-cygwin -O2" in Cygwin

#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<numeric>
#include<functional>
#include<complex>
#include<cassert>
#include<bitset>

using namespace std;
#define BET(a,b,c) ((a)<=(b)&&(b)<(c))
#define FOR(i,n) for(int i=0,i##_end=(int(n));i<i##_end;i++)
#define FOR3(i,a,b) for(int i=a,i##_end=b;i<i##_end;i++)
#define FOR_EACH(it,v) for(__typeof(v.begin()) it=v.begin(),it_end=v.end() ; it != it_end ; it++)
#define SZ(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define MP make_pair
#define CLS(x,val) memset((x) , val , sizeof(x)) 
typedef long long ll_t;
typedef long double ld_t;
typedef vector<int> VI; 
typedef vector<VI> VVI;
typedef complex<int> xy_t;

template<typename T> void debug(T v , string delimiter = "\n")
{ for(__typeof(v.begin()) it=v.begin(),it_end=v.end() ; it != it_end ; it++) cout << *it << delimiter; cout << flush ;}

int dx[]  = {0,1,0,-1};
int dy[]  = {1,0,-1,0};
string ds = "SENW";

vector<string> cand;

void enumerate(int N, int M,int last,string now)
{
  if(N == 0) {
    cand.push_back(now);
    return; 
  }
  for(int i=last;i<=M;i++) {
    enumerate(N-1,M,i,now+(char)('0'+i));
  }
}

struct data
{
  string digits;
  map<ll_t,double> percentage;
};

vector<data> dataList;

void MakeTable(int N, int M, int K) // for small
{
  enumerate(N, M,2,"");

  FOR(i,SZ(cand)) {
    data d;
    d.digits = cand[i];

    assert(SZ(d.digits) == N);
    FOR(b,(1<<N)) {
      ll_t sum = 1;
      FOR(j, N) if(b & (1<<j)) {
        sum *= d.digits[j] - '0';
      }
      d.percentage[sum] += 1.0 / (1<<N);
    }
    dataList.push_back(d);
  }
  cand.clear();
}

void solve()
{
  int R,N,M,K;
  cin>>R>>N>>M>>K;

  // small: N=3 M=5 (2..5)
  MakeTable(N,M,K);
  vector<long long> p(K);
  FOR(_,R) {
    FOR(i,K) cin>>p[i];
    string ans = "";
    double maxValue = -1;
    FOR(j,SZ(dataList)) {
      data& d = dataList[j];
      double value = 0 ;
      FOR(i,K) {
        double per = d.percentage.count(p[i]) ? d.percentage[p[i]] : 0;
        if(per == 0) { value = -10; break; }
        value += pow(per , 1.5);
      }
      if(maxValue < value) {
        maxValue = value;
        ans = d.digits;
      }
    }
    //assert(SZ(ans) == N);
    printf("%s\n" , ans.c_str());
  }
}

int main() {
  int t,case_no=1;
  cin>>t;
  while(t--){
    printf("Case #%d:\n" , case_no++);
    solve();
  }
  return 0 ;
}
