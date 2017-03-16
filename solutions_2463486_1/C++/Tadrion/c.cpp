//Tadrion
#include <cstdio>
#include <vector>
#include <iostream>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define CLEAR(x) (memset(x,0,sizeof(x)))
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define VAR(v, n) __typeof(n) v = (n)
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define FOREACH(i, c) for(VAR(i,(c).begin()); i != (c).end(); ++i)
#define DBG(v) cout<<#v<<" = "<<v<<endl;
#define IN(x,y) ((y).find(x)!=(y).end())
#define ST first
#define ND second
#define PB push_back
#define PF push_front
#define MP make_pair
typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

vector<LL> res;
vector<LL> v;
bool ispalin(LL n) {
   stringstream ss;
   ss << n;
    string str =  ss.str();
    int l = SZ(str);
    if(n > 1000000000LL) cout << str << "\n";
    for(int i = 0; i < SZ(str); i++) {
        if(str[i] != str[l-i-1]) return false;
    }
    return true;
}

int main() {
v.PB(1);
v.PB(4);
v.PB(9);
v.PB(121);
v.PB(484);
v.PB(10201);
v.PB(12321);
v.PB(14641);
v.PB(40804);
v.PB(44944);
v.PB(1002001LL);
v.PB(1234321LL);
v.PB(4008004LL);
v.PB(100020001LL);
v.PB(102030201LL);
v.PB(104060401LL);
v.PB(121242121LL);
v.PB(123454321LL);
v.PB(125686521LL);
v.PB(400080004LL);
v.PB(404090404LL);
v.PB(10000200001LL);
v.PB(10221412201LL);
v.PB(12102420121LL);
v.PB(12345654321LL);
v.PB(40000800004LL);
v.PB(1000002000001LL);
v.PB(1002003002001LL);
v.PB(1004006004001LL);
v.PB(1020304030201LL);
v.PB(1022325232201LL);
v.PB(1024348434201LL);
v.PB(1210024200121LL);
v.PB(1212225222121LL);
v.PB(1214428244121LL);
v.PB(1232346432321LL);
v.PB(1234567654321LL);
v.PB(4000008000004LL);
v.PB(4004009004004LL);
v.PB(100000020000001LL);

int T;
LL A,B;

    scanf("%d",&T);
    FOR(ttt,1,T) {
        scanf("%lld %lld",&A,&B);
        int cnt = 0;
        REP(i,SZ(v)) {
            if(A <= v[i] && v[i] <=B) cnt++;
        }
        printf("Case #%d: %d\n",ttt,cnt);
    }


/*
  for(LL i = 1; i <= 10000001LL; i++) {
    if(ispalin(i) && ispalin(i*i)) res.PB(i*i);
    //if(i%10000 == 0) printf("%d\n",i);
  }
  printf("%d\n\n",res.size());
  REP(i,SZ(res)) printf("v.PB(%lld);\n",res[i]);
*/


  return 0;
}
