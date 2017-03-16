#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define PB push_back
#define SZ(X) ((int)(X.size()))
#define ALL(X) (X).begin(), (X).end()
#define FE(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define MOD 1000000007ll

const double PI=acos(-1.0);
const double EPS=1e-10;

typedef long long ll;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<string> vstr;
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
#define MAXN 1800

pii stars[MAXN];
int perm[MAXN];
int used[MAXN];
int conv[MAXN];

void solve(){
  int N=in();
  int i,j,k,a,b;
  for(i=0;i<N;i++){
    a=in(); b=in(); stars[i]=pii(a,b);
    perm[i]=i;
  }
  int ans=1001001001;
  int act;
  int have;
  bool cant;
  
  do{
    for(i=0;i<N;i++) used[i]=0;
    act=0;
    have=0;
    cant=false;
    
    
    
    for(i=0;i<N;i++){
      if(used[i]==0 && have<stars[perm[i]].first) {cant=true; break;}
        
      //~if(i==6)  cerr << perm[i] << endl;
      if(used[i]==0 && have>=stars[perm[i]].second){
        have+=2;
        used[i]=2;
      }
      
      if(used[i]==0){
        act++;
        used[i]=1;
        have++;
      }
      
      for(k=0;k<N;k++)
      for(j=0;j<N;j++){
        if(used[j]<2 && have>=stars[perm[j]].second){
          if(used[j]==0) have+=2;
          else have++;
          
          used[j]=2;
          
        }
      }
    }
    
    if(!cant){
      ans=min(ans,act+N);
    }
    
  }while(next_permutation(perm,perm+N));

  
  if(ans==1001001001){
    puts("Too Bad");
    return;
  }
  
  printf("%d\n",ans);

}

int main(){
	//~freopen("B.in","r",stdin);
	//~freopen("B-small-attempt0.in","r",stdin); 
	//~freopen("B-small-attempt1.in","r",stdin); 
	freopen("B-small-attempt2.in","r",stdin); 
	//~freopen("B-large.in","r",stdin);
  freopen("Bout","w",stdout);
  
  int C=in();
  for(int caso=1;caso<=C;caso++){
    printf("Case #%d: ",caso);
    solve();
  }
  
  return 0;
}


