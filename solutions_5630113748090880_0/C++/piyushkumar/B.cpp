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
vector<int> l[2*mx];

bool solve(int mask){
   vector<vector<int>> columns;
   for(int i=0;i<2*n-1;i++) if(mask & (1<<i)) columns.pb(l[i]);

   sort(columns.begin(),columns.end());

   fr(i,n-1) fr(j,n) if(columns[i][j] >= columns[i+1][j]) return false;

   map<vector<int>,int> rows;
   fr(i,n){
      vector<int> v;
      fr(j,n) v.pb(columns[j][i]);
      rows[v]++;
   }

   for(int i=0;i<2*n-1;i++) if(not(mask & (1<<i))){
      if(rows.find(l[i]) == rows.end()) return false;
      rows[l[i]]--;
      if(rows[l[i]]==0) rows.erase(l[i]);
   }
   for(auto r : rows){
      for(auto e : r.first) printf("%d ",e);
      printf("\n");
   }
   return true;
}

int main(){
   int t;
   read(t);

   fr(ii,t){
      read(n);

      fr(i,2*n-1){
         l[i].clear();

         fr(j,n){
            int e;
            read(e);
            l[i].pb(e);
         }
      }

      printf("Case #%d: ",ii+1);

      for(int mask=0;mask<(1<<(2*n-1));mask++){
         if(__builtin_popcount(mask) != n) continue;
         if(solve(mask)) break;
      }
   }
}
