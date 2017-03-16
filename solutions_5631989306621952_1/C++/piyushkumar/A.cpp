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

string solve(string s){
   if(s.length() == 0) return "";

   char largest='A';
   for(char e : s) largest = max(largest,e);

   string first="";
   string rem="";
   int cnt=0;

   for(char c : s){
      if(c==largest) cnt++;
      else{
         if(cnt==0) first+=c;
         else rem+=c;
      }
   }
   string ret="";
   fr(i,cnt) ret+=largest;

   return ret+solve(first)+rem;
}

int main(){
   int t;
   read(t);
   fr(ii,t){
      string in;
      cin>>in;
      cout<<"Case #"<<(ii+1)<<": "<<solve(in)<<endl;
   }
}
