#include <vector>
#include <list>
#include <map>
#include <set>
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
 
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define sz size()
#define INF (int)1e9
 
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector< vector <int> > VVI;
typedef pair<int,int> pii;



bool isPalin(LL a) {
  int y=0;
  int x = a;
  while(a) {
     y = y*10 + a%10;
     a = a/10;
  }
  if(x==y) return true;
  return false;
}

int main() {
     freopen("abc1.txt","r",stdin);
     freopen("myfile1.txt","w",stdout);
      long long a[40] = {
      1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,
      10000200001LL,10221412201LL,12102420121LL,12345654321LL,40000800004LL,1000002000001LL,1002003002001LL,1004006004001LL,1020304030201LL,1022325232201LL,1024348434201LL,1210024200121LL,
      1212225222121LL,1214428244121LL,1232346432321LL,1234567654321LL,4000008000004LL,4004009004004LL
     };
     int T; 
     cin>>T;
     REP(i,T) {
        LL A,B;
        cin>>A>>B;
        int end,start;
        int flagA = 0;
        REP(j,39) {
           if(!flagA && a[j] >= A) {
             start = j;
             flagA = 1;
           }
           if(B >= a[j]) {
             end = j;
           }
          // cout<<start<<" "<<end<<endl;
           
        }
        int ans=0;
        for(int k=start; k<=end; k++) {
            if(a[k]>=A && a[k]<=B) ans++;
        } 
        cout<<"Case #"<<i+1<<": "<<ans<<endl;
     }
    
     //while(1);
      
}
