#include <algorithm>
#include <numeric>
#include <functional>

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
#include <ctime>
using namespace std;

//#define debug(x) cerr<<#x<<" = "<<(x)<<endl;

int cmp(string a, string b){
  int n = a.size();
  int m = b.size();
  if(n<m)
    return 1;

  if(n>m)
    return 0;

  return a<b;

  for(int i = 0 ; i < n; i++){
    if(a[i]<b[i]){
      cout<<" CMP "<<i<<" "<<a[i]<<","<<b[i]<<endl;
      return 1;
    }
  }
  return 0;
}

int main(int argc, char *argv[])
{
  int __T;
  cin>>__T;
  for(int __t = 1 ; __t <= __T; __t++){
    int n, m;
    cin>>n>>m;
    vector<string> code;
    for(int i = 0 ; i < n; i++){
      string s;
      cin>>s;
      code.push_back(s);
    }
    vector<set<int> > out (n), back(n);
    for(int i = 0 ; i < m; i++){
      int a, b;
      cin>>a>>b;
      a--;b--;
      out[a].insert(b);
      out[b].insert(a);
      back[b].insert(a);
    }


    if(n==1){
      cout<<"Case #"<<__t<<": "<<code[0]<<endl;
    }else{
      string ans="";

      vector<int> path(n, 0);
      for(int i = 0 ; i < n; i++){
        path[i]=i;
      }

      do{
        int start = path[0];
        stack<int> st;
        st.push(start);
        int p = 1, ok=1;
        while(p < n){
          int next = path[p];
          while(!st.empty() && out[st.top()].find(next) == out[st.top()].end()){
            st.pop();
          }
          if(st.empty()){
            ok=0;
            break;
          }
          st.push(next);
          p++;
        }

        if(p>=n){
          string s;
          for(int i = 0 ; i < n; i++){
            s+=code[path[i]];
          }

          //copy(path.begin(), path.end(), ostream_iterator<int>(cout, ","));cout<<endl;


          if(ans=="" || cmp(s, ans)){
            //cout<<ans<<" --> "<<s<<endl;
            ans = s;
          }
        }


      }while(next_permutation(path.begin(), path.end()));


      cout<<"Case #"<<__t<<": "<<ans<<endl;

    }
  }

    return 0;
}
