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

int n;
int a[2010];
string s;
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

int main()
{
    freopen("out.txt","w",stdout);
    freopen("C-small-attempt0.in","r",stdin);
//    freopen("in.txt","r",stdin);
    int t, test = 0;
    cin>>t;
    init_ma();
    while(t--)
    {
        cout<<"Case #"<<++test<<": ";
        int l, x;
        cin>>l>>x;
        string s1;
        cin>>s1;
        s = "";
        for(int i = 0; i < x; i++) s += s1;
        int total = 1;
        for(int i = 0; i < l*x; i++){
            total = cal(total,mb[s[i]]);
        }
        if(total != -1){
            cout<<"NO"<<endl;
            continue;
        }
        int v1 = 1, p1 = -1, v2 = 1, p2 = -1;
        for(int i = 0; i < l*x; i++){
            if(p1 < 0){
                v1 = cal(v1, mb[s[i]]);
                if(v1 == 2){
                    p1 = i;
                }
            }
            if(p2 < 0){
                v2 = cal(v2, mb[s[i]]);
                if(v2 == 4 && p1 >= 0 && i > p1){
                    p2 = i;
                }
            }
        }
        if(p1 >= 0 && p2 >= 0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return(0);
}

