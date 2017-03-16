#include <vector>
#include <utility>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <list>
#include <bitset>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> vI;
typedef vector<string> vS;
typedef pair<int, int> pI;
typedef map<int, int> mI;
typedef map<string, int> mSI;
typedef set<int> sI;
typedef set<pI> spI;
typedef priority_queue<int> qmax;
typedef priority_queue<int, vector<int>, greater<int> >qmin;
typedef map<int, int>::iterator mI_it;
typedef set<int>::iterator sI_it;

#define TWO(k)  (1<<(k))
#define LTWO(k) (((LL)(1)<<(k)))
#define MIN(a,b) ( (a)<(b)?(a):(b) )
#define MAX(a,b) ( (a)>(b)?(a):(b) )
#define LS(x) 	 ((x)<<1)
#define RS(x) 	 (((x)<<1)+1)
#define MP make_pair
#define PB push_back
#define F0(i, n) for( int (i) = 0; (i) < (n); (i)++)
#define F1(i, n) for( int (i) = 1; (i) <= (n); (i)++)
#define zero(i) memset((i),0,sizeof((i)))

//const double PI = acos(-1.0);
//const double EPS = 1e-9;
//const int ioo = (~0)-(1<<31);
//const LL loo = (~(LL)0)-((LL)1<<63);

int Scan()     //输入外挂
{
  int res=0,ch,flag=0;
  if((ch=getchar())=='-')
      flag=1;
  else if(ch>='0'&&ch<='9')
      res=ch-'0';
  while((ch=getchar())>='0'&&ch<='9')
      res=res*10+ch-'0';
  return flag?-res:res;
}

void Out(int a)    //输出外挂
{
  if(a>9)
  Out(a/10);
  putchar(a%10+'0');
}

map< pair<int, int>, int>  ma;
map<char, int> mb;

void init_ma()
{
    ma[MP(1,1)] = 1; ma[MP(1,2)] = 2; ma[MP(1,3)] = 3; ma[MP(1, 4)] = 4; 
    ma[MP(2,1)] = 2; ma[MP(2,2)] = -1; ma[MP(2,3)] = 4; ma[MP(2, 4)] = -3; 
    ma[MP(3,1)] = 3; ma[MP(3,2)] = -4; ma[MP(3,3)] = -1; ma[MP(3, 4)] = 2; 
    ma[MP(4,1)] = 4; ma[MP(4,2)] = 3; ma[MP(4,3)] = -2; ma[MP(4, 4)] = -1;
    mb['i'] = 2; mb['j'] = 3; mb['k'] = 4;
}

int cal(int x, int y)
{
    int sn = 1;
    if(x * y < 0) sn = -1;
    return sn*ma[MP(abs(x), abs(y))];
}

int cal_pow(int x, int n)
{
    if(x == 1) return 1;
    else if(x == -1) return n%2==1? -1: 1;
    else{
        if(n % 4 == 0) return 1;
        if(n % 4 == 1) return x;
        if(n % 4 == 2) return -1;
        if(n % 4 == 3) return -x;
    }
    return 0;
}

int cal_rev(int x, int y)
{
    for(int i = -4; i <= 4; i++){
        if(i != 0 && cal(i, x) == y) return i;
    }
    return 0;
}

int pow_find_min(int x, int y, int mv)
{
    if(y == 1) return 0;
    else if(y == -1){
        if(x == 1) return -1;
        else if(x == -1) return mv>1? 1 : -1;
        else return mv>2? 2 : -1;
    }
    else if(abs(x) == abs(y)){
        if(x > 0 && y > 0) return mv>1? 1 : -1;
        if(x > 0 && y < 0) return mv>3? 3 : -1;
        if(x < 0 && y > 0) return mv>3? 3 : -1;
        if(x < 0 && y < 0) return mv>1? 1 : -1;
    }
    return -1;
}

int pow_find_max(int x, int y, int mv)
{
    if(y == 1){
        if(x == 1) return mv-1;
        else if(x == -1) return mv%2==1? mv-1 : mv-2;
        else return mv%4==0? mv-4 : mv-mv%4;
    }
    else if(y == -1){
        if(x == 1) return -1;
        else if(x == -1) return mv%2==0? mv-1 : mv-2;
        else{ mv--; while(mv >= 0 && mv % 4 != 2) mv--; return mv;}
    }
    else if(abs(x) == abs(y)){
        if(x > 0 && y > 0) { mv--; while(mv >= 0 && mv % 4 != 1) mv--; return mv;}
        if(x > 0 && y < 0) { mv--; while(mv >= 0 && mv % 4 != 3) mv--; return mv;}
        if(x < 0 && y > 0) { mv--; while(mv >= 0 && mv % 4 != 3) mv--; return mv;}
        if(x < 0 && y < 0) { mv--; while(mv >= 0 && mv % 4 != 1) mv--; return mv;}
    }
    else return -1;
    return -1;
}

int main()
{
    freopen("out.txt","w",stdout);
    freopen("C-large.in","r",stdin);
//    freopen("in.txt","r",stdin);
    int t, test = 0;
    cin>>t;
    init_ma();
    while(t--)
    {
        cout<<"Case #"<<++test<<": ";
        int l;
        long long x;
        cin>>l>>x;
        string s;
        cin>>s;
        int total = 1;
        for(int i = 0; i < l; i++){
            total = cal(total,mb[s[i]]);
        }
        int total1 = cal_pow(total, x);
        if(total1 != -1){
            cout<<"NO"<<endl;
            continue;
        }
        int v1 = 1, v2 = 1, r;
        LL p1, m1 = l*x, p2, m2 = -1;
        for(int i = 0; i < l; i++){
            v1 = cal(v1, mb[s[i]]);
            r = cal_rev(v1, mb['i']);
            if(r != 0){
                LL x1 = pow_find_min(total, r, x);
                if(x1 >= 0){
                    p1 = x1 * l + i;
                    m1 = min(p1, m1);
                }
            }
            v2 = cal(v2, mb[s[i]]);
            r = cal_rev(v2, mb['k']);
            if(r != 0){
                LL x2 = pow_find_max(total, r, x);
                if(x2 >= 0){
                    p2 = x2 * l + i; 
                    m2 = max(p2, m2);
                }
            }
        }
        if(m1 < l*x && m2 > m1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return(0);
}

