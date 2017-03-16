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
int s[500]; 
double p[500];
int S;
int N;


bool can(double x,int y){
  
  p[y]=s[y]+S*x;
  int i;
  double tmp,acum;
  acum=0;
  
  for(i=0;i<N;i++) if(i!=y){
    p[i]=s[i];
    if(p[i]>p[y]) continue;
    
    tmp= (p[y]-p[i])/S;
    acum+=tmp;
    //~cerr << acum << endl;
    if(acum>(1-x)) return true;
    
  }
  
  
  return false;
}

void solve(){
  N=in();
  int i;
  S=0;
  for(i=0;i<N;i++) { s[i]=in(); S+=s[i];}
  
  
  double inf,sup,mid;
  for(i=0;i<N;i++){
    //~cerr << " DO " << i << endl;
    if(i)putchar(' ');
    inf=0;
    sup=1;
    
    while(sup-inf>EPS){
      mid=(sup+inf)/2;
      
      if(can(mid,i)){
        sup=mid;
      }else{
        inf=mid;
      }
    }
    
    
    printf("%.8lf",inf*100);
  }
  
  puts("");

}

int main(){
	//~freopen("A.in","r",stdin);
	freopen("A-small-attempt0.in","r",stdin); 
	//~freopen("A-small-attempt1.in","r",stdin); 
	//~freopen("A-small-attempt2.in","r",stdin); 
	//~freopen("A-large.in","r",stdin);
  freopen("Aout","w",stdout);
  
  int C=in();
  for(int caso=1;caso<=C;caso++){
    printf("Case #%d: ",caso);
    solve();
  }
  
  return 0;
}


