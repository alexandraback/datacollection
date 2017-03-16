#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
typedef long long ll;
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define mp make_pair
#define go(i,n) for(int i=0;i<n;i++)
#define go3(i,j,n) for(int i=j;i<n;i++)
#define inf 1000000000


bool isset(int mask,int bit){
 return (mask&(1<<bit)) > 0;
}

map<int,int > memo;

void oku(){

 int T;
 cin>>T;
 int n;
 go(ii,T){
 
  memo.clear();
  int msk1;
  vi a;
  vi m;
  cin>>n;
  int sum=0;
  printf("Case #%d:\n",ii+1);

  go(i,n) a.pb(0), cin>>a[i], sum+=a[i];

  go(mask,(1<<n)){
  int cur=0;

   go(i,n)
    if(isset(mask,i)) cur+=a[i];
  
    if(memo.count(cur))
    {
      msk1=memo[cur];
      go(i,n)
      if(isset(mask,i) && !isset(msk1,i)) 
      cout<<a[i]<<" ";
      cout<<endl;
      go(i,n)
      if(!isset(mask,i) && isset(msk1,i))
      cout<<a[i]<<" ";
      goto jmp;
    }

    else memo[cur]=mask;

  }

  cout<<"Impossible";
  jmp:;
  cout<<endl;

 }

}

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
#endif

oku();

return 0;}