// compile with "g++ XXX.cc -mno-cygwin -O2" in Cygwin

#include<iostream>
#include<sstream>
#include<fstream>
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

const double PI = 4.0*atan(1.0);

vector<string> dic;
vector<string> dicFromFirst[26];
vector<string> dicFromSecond[26];


int maxDicLength = -1;

void loadDictionary()
{
  ifstream in("garbled_email_dictionary.txt");
  string tok;
  while(in>>tok){
    dic.push_back(tok);
    maxDicLength = max(maxDicLength , SZ(tok));
    dicFromFirst[tok[0]-'a'].push_back(tok);
    if(SZ(tok) >= 2){
      dicFromSecond[tok[1]-'a'].push_back(tok);
    }
  }
}

int memo[4100][10];
const int minErrorDiff = 5;
int dfs(const string& S, int pos, int lastError)
{
  if(pos >= SZ(S)) return 0 ;
  if(lastError < -minErrorDiff) lastError = -minErrorDiff;
  int& ret = memo[pos][lastError+minErrorDiff];
  if(ret != -1) return ret;
  int val = 1<<28;
  FOR(t,2){
    vector<string>& targetDic = t == 0 ? dicFromFirst[S[pos]-'a'] : 
      (pos + 1 < SZ(S) ? dicFromSecond[S[pos+1]-'a'] : dic) ;
    FOR(i,SZ(targetDic)){
      const string& s = targetDic[i];
      if(pos + SZ(s) - 1 >= SZ(S)) continue;
      int last = lastError;
      int change = 0 ;
      bool ng = false;
      FOR(j,SZ(s)) {
        if(S[pos+j] != s[j]) {
          if(j - last < minErrorDiff){
            ng = true; break;
          }
          last = j;
          change++;
        }
      }
      if(!ng) {
        val = min(val , dfs(S , pos + SZ(s), last - SZ(s)) + change);
      }
    }
  }

  return ret = val;
}

int solve()
{
  string S;
  cin>>S;
  memset(memo , -1 , sizeof(memo));
  return dfs(S, 0, -100);
}

int main() {
  loadDictionary();
  int t,case_no=1;
  cin>>t;
  while(t--){
    printf("Case #%d: %d\n" , case_no++ , solve());
  }
  return 0 ;
}
