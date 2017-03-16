#include <algorithm>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cstdarg>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

#if __cplusplus > 199711L
    void read(){}
    template<typename... T>
    void read(int& head, T&... tail) {scanf("%d",&head); read(tail...);}

    #define DB(args...) { cerr << __LINE__<< ": "; vector<string> _v = split(#args, ','); err(_v.begin(), args); }
    vector<string> split(const string& s, char c) {
        vector<string> v;stringstream ss(s);string x;
        while (getline(ss, x, c)) v.push_back(x);
        return move(v);
    }
    void err(vector<string>::iterator it) {cerr<<endl;}
    template<typename T, typename... Args>
    void err(vector<string>::iterator it, T a, Args... args) {
        cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << "  "; err(++it, args...);
    }
#else
    #define DB(e) cerr << __LINE__ << ": " << #e << " = " << e << endl;
    void read(int& head) {scanf("%d",&head);}
#endif

#define ll long long int
#define pb push_back
#define fr(i,n)     for(int i=0;i<n;i++)
#define init(mem,v) memset(mem,v,sizeof(mem))
typedef pair<int,int> pii;

#define mx 11

int n;
int bff[mx];

int solve(vector<int>& c){
   sort(c.begin(),c.end());

   int nn=c.size();

   bool ok=true;
   fr(i,nn){
      int nx=i+1; if(nx==nn) nx=0;
      int pr=i-1; if(pr==-1) pr=nn-1;

      if(not((bff[c[i]]==c[pr] or bff[c[i]]==c[nx]))) ok=false;
   }
   if(ok) return nn;

   while(next_permutation(c.begin(),c.end())){
      bool ok=true;
      fr(i,nn){
         int nx=i+1; if(nx==nn) nx=0;
         int pr=i-1; if(pr==-1) pr=nn-1;

         if(not((bff[c[i]]==c[pr] or bff[c[i]]==c[nx]))) ok=false;
      }
      if(ok) return nn;
   }
   return 0;
}

int main(){
   int t;
   read(t);

   fr(ii,t){
      read(n);
      fr(i,n){
         read(bff[i]);
         bff[i]--;
      }

      int ans=0;

      vector<int> pos;
      for(int mask=0;mask<(1<<n);mask++){
         pos.clear();
         fr(i,n) if(mask & (1<<i)) pos.pb(i);

         ans=max(ans,solve(pos));
      }
      printf("Case #%d: %d\n",ii+1,ans);
   }
}
