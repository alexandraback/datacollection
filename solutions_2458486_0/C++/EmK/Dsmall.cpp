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

struct Chest
{
  int keytype;
  VI keys;
};

int memo[1<<20];
int before[1<<20];
VI result;
int dfs(const vector<Chest> &chests , int used, VI& key)
{
  int& ret = memo[used];
  if(ret != -1) return ret;
  if(used == (1<<SZ(chests)) - 1) return 1;

  FOR(i, SZ(chests)){
    if((1<<i) & used) continue;
    
    const Chest& c = chests[i];
    if(key[c.keytype] > 0){
      key[c.keytype]--;

      FOR(j,SZ(c.keys)) key[c.keys[j]]++;

      if(dfs(chests, (1<<i) | used , key)){
        result.push_back(i);
        return ret = 1;
      }

      FOR(j,SZ(c.keys)) key[c.keys[j]]--;

      key[c.keytype]++;
    }
  }

  return ret = 0; // NOT FOUND
}

string solve()
{
  int K,N;
  cin>>K>>N;
  VI keys(222);
  FOR(i,K) {
    int k ;
    cin>>k;
    keys[--k]++;
  }
  vector<Chest> chests;
  FOR(i,N){
    int t,k;
    cin>>t>>k;
    t--;
    Chest chest;
    chest.keytype = t;
    FOR(j,k){
      int key;
      cin>>key; key--;
      chest.keys.push_back(key);
    }
    chests.push_back(chest);
  }
  memset(memo , -1 , sizeof(memo));
  result.clear();
  int res = dfs(chests, 0, keys);
  if(res == 0) return "IMPOSSIBLE";

  string ans = "";

  reverse(ALL(result));
  ostringstream out;

  FOR(i,SZ(result)) out<<(i?" ":"")<<result[i]+1;
  return out.str();
}

int main() {
  int t,case_no=1;
  cin>>t;
  while(t--){
    string ans = solve();

    printf("Case #%d: %s\n" , case_no++ , ans.c_str());
  }
  return 0 ;
}
