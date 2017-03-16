#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstring>

#define rep(i,n) for(int i=0;i<n;i++)
#define pr(i) cout<<i<<endl

using namespace std;

int cs,icap,n,a[110];

int dfs(int p,int cap){
  if(p==n-1){
    if(cap>a[p])return 0;
    else return 1;
  }  

  if(cap>a[p])return dfs(p+1,cap+a[p]);
  else {
    int inc  = 0;
    int ncap = cap;
    while(ncap<=a[p]){
      ncap += ncap-1;
      inc++;
    }
    return min(inc+dfs(p+1,ncap+a[p]),1+dfs(p+1,cap));
  }
}



int main(){
  cin>>cs;
  rep(ii,cs){
    cin>>icap>>n;rep(i,n)cin>>a[i];
    sort(a,a+n);
    cout<<"Case #"<<ii+1<<": "<<(icap==1?n:dfs(0,icap))<<endl;
  }

}
