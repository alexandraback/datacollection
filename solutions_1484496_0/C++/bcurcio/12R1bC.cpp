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
#define MAXN 1000
int a[40];
pii vale[1<<21];
int N;
int calc(int idx){
  int j;
  int res=0;
  for(j=0;j<N;j++) if((idx&(1<<j))!=0) res+=a[j];
  return res;
}

void show(int x,int y){
  int i;
  bool p=false;
  for(i=0;i<N;i++) if((x&(1<<i))!=0) {
    if(p) putchar(' ');
    printf("%d",a[i]);
    p=true;
  }
  puts("");
  p=false;
  for(i=0;i<N;i++) if((y&(1<<i))!=0) {
    if(p) putchar(' ');
    printf("%d",a[i]);
    p=true;
  }
  puts("");
}


void solve(){
  puts("");
  N=in();
  int i,j,x;
  for(i=0;i<N;i++) a[i]=in();
  int cnt=0;
  for(i=0;i<(1<<N);i++){
    x=calc(i);
    
    vale[cnt++]=pii(x,i);
  }
  
  sort(vale,vale+cnt);
  
  for(i=0;i<cnt;i++){
    for(j=i+1; vale[j].first==vale[i].first;j++){
      if((vale[i].second&vale[j].second) ==0){
        show( vale[i].second, vale[j].second);
        return;
      }
    }
  }
  
  puts("impossible");
}

int main(){
	//~freopen("C.in","r",stdin);
	freopen("C-small-attempt0.in","r",stdin); 
	//~freopen("C-small-attempt1.in","r",stdin); 
	//~freopen("C-small-attempt2.in","r",stdin); 
	//~freopen("C-large.in","r",stdin);
  freopen("Cout","w",stdout);
  
  int C=in();
  for(int caso=1;caso<=C;caso++){
    printf("Case #%d: ",caso);
    solve();
  }
  
  return 0;
}


