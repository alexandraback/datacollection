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

int x, r, c;
string yes = "RICHARD", no = "GABRIEL";

string sol()
{
    if(c > r) swap(c, r);
    if((r*c) % x != 0) return yes;
    if(x > 6) return yes;
    if(x == 1) return no;
    /*  
    if(x == 2) return no;
    if(x == 3){
        if(r == 3 && c == 1) return yes;
        if(r == 3 && c == 2) return no;
        if(r == 3 && c == 3) return no;
        if(r == 4 && c == 3) return no;
    }
    if(x == 4){
        if(r == 4 && c == 1) return yes;
        if(r == 4 && c == 2) return yes;
        if(r == 4 && c == 3) return no;
        if(r == 4 && c == 4) return no;
    }*/
    if(x > 1){
        if(c < x - 1) return yes;
        else return no;
    }
    return "";
}
int main()
{
    freopen("out.txt","w",stdout);
    freopen("D-large.in","r",stdin);
//    freopen("in.txt","r",stdin);
    int t, test = 0;
    cin>>t; 
    while(t--)
    {
        cout<<"Case #"<<++test<<": ";
        cin>>x>>r>>c;
        cout<<sol()<<endl;
    }
    return(0);
}

