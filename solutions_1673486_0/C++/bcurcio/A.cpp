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

double prob[101000];
double wrong[101000];
double correct[101000];
double acum[101000];

void solve(){
  int A=in();
  int B=in();
  
  double res=B+2;
  int i;
  correct[0]=1.0;
  wrong[0]=1.0;
  acum[0]=1.0;
  //~cerr << endl;
  for(i=1;i<=A;i++){
    wrong[i]=0;
    correct[i]=0;
    scanf("%lf",&prob[i]);
    wrong[i]= (1-prob[i])*correct[i-1];
    correct[i]=prob[i]*correct[i-1];
    //~cerr << wrong[i] << " ";
  }
  //~cerr << endl;
  
  acum[0]=correct[A];
  //~cerr << acum[0] << " ";
  for(i=1;i<=A;i++){
    acum[i]=acum[i-1]+wrong[A-i+1];
    //~cerr << acum[i] << " " ;
  }
  //~cerr << endl;
  double exp,algo;
  for(i=0;i<=A;i++){
    algo= acum[i];
    exp= ((i*2)+(B+1-A))*algo+(2*i+2*B+2-A)*(1-algo);
    //~cerr << i<< " " <<exp << endl;
    res=min(res,exp);
  }
  
  printf("%.9lf\n",res);
  

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


