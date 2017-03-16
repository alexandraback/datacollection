// compile with "g++ XXX.cc -mno-cygwin -O2" in Cygwin

#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<numeric>
#include<functional>
#include<complex>
#include<bitset>

using namespace std;
#define BET(a,b,c) ((a)<=(b)&&(b)<(c))
#define FOR(i,n) for(int i=0,i##_end=(int(n));i<i##_end;i++)
#define FOR3(i,a,b) for(int i=a,i##_end=b;i<i##_end;i++)
#define FOR_EACH(it,v) for(__typeof(v.begin()) it=v.begin(),it_end=v.end() ; it != it_end ; it++)
#define SZ(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define MP make_pair
#define CLS(x,val) memset((x) , val , sizeof(x)) 
typedef long long ll_t;
typedef long double ld_t;
typedef vector<int> VI; 
typedef vector<VI> VVI;
typedef complex<int> xy_t;

template<typename T> void debug(T v , string delimiter = "\n")
{ for(__typeof(v.begin()) it=v.begin(),it_end=v.end() ; it != it_end ; it++) cout << *it << delimiter; cout << flush ;}

int dx[]  = {0,1,0,-1};
int dy[]  = {1,0,-1,0};
string ds = "SENW";

const double PI = 4.0*atan(1.0);
int a[11111],b[11111];
int main() {
  int t,case_no=1;
  cin>>t;
  while(t--){
    int N;
    cin>>N;
    FOR(i,N) {
      scanf("%d%d",&a[i],&b[i]);
    }
    int star = 0;
    VI rate(N);
    int ans = 0 ;
    FOR(_,N*2+10) {
      if(star == 2*N) break;
      bool yet = true;
      while(yet){
        yet = false;
        FOR(i,N){ // get 2-star
          if(b[i] <= star && rate[i]<2){
            star += 2 - rate[i];
            rate[i] = 2;
            yet = true;
            ans++;
            //cout<<i<<" " << 2<<endl;
          }
        }
      }
      int target = -1 , maxB = -1;
      FOR(i,N){ // get 2-star
        if(a[i] <= star && rate[i]<1){
          if(maxB < b[i]){
            maxB = b[i];
            target = i;
          }
        }
      }
      if(target != -1){
        star += 1 - rate[target];
        rate[target] = 1;
        ans++;
        //cout<<target<<" " << 1<<endl;
      }
    }
    //cout<<star<<endl;
    if(star == 2*N){
      printf("Case #%d: %d\n" , case_no++ , ans);
    }else{
      printf("Case #%d: Too Bad\n" , case_no++);
    }
    
  }
  return 0 ;
}
