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
typedef vector<double> vD;
typedef vector<pair<int, int> > vpI;
typedef vector<string> vS;
typedef pair<int, int> pI;
typedef pair<double, double> pD;
typedef map<int, int> mI;
typedef map<string, int> mSI;
typedef map<int, pair<int, int> > mIP;
typedef map<pair<int, int>, int> mPI;
typedef set<int> sI;
typedef set<pI> sPI;
typedef set<string> sS;
typedef priority_queue<int> Qmax;
typedef priority_queue<int, vector<int>, greater<int> >Qmin;

#define TWO(k)  (1<<(k))
#define LTWO(k) (((LL)(1)<<(k)))
#define MP make_pair
#define PB push_back
#define FI first
#define SE second
#define For(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define Ford(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define F0(n) for(int (i)=0;(i)<(n);(i)++)
#define F1(n) for(int (i)=1;(i)<=(n);(i)++)
#define Zero(i) memset((i),0,sizeof((i)))
#define Fu1(i) memset((i),0xff,sizeof((i)))
#define Bit(s,i) (( (s) &(1<<(i)))>0)
#define NP next_permutation

//const double PI = acos(-1.0);
//const double EPS = 1e-9;
//const int ioo = (~0)-(1<<31);
//const LL loo = (~(LL)0)-((LL)1<<63);
//const int MOD = 1000000007;
//const LL MODL = 1000000007;

int Scan()
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

void Out(int a)
{
  if(a>9)
      Out(a/10);
  putchar(a%10+'0');
}

int main()
{
    freopen("out.txt","w",stdout);
    freopen("B-large.in","r",stdin);
    // freopen("in.txt","r",stdin);
    int t, test = 0;
    cin>>t;
    while(t--){
        cout<<"Case #"<<++test<<": ";
        string s;
        cin>>s;
        int l = s.length();
        int dp[102][2];
        if(s[0] == '+'){
            dp[0][0] = 1;
            dp[0][1] = 0;
        }
        else{
            dp[0][0] = 0;
            dp[0][1] = 1;
        }
        for(int i = 1;i < l; i++){
            if(s[i] == '-'){
                dp[i][0] = min(dp[i-1][1]+1, dp[i-1][0]);
                dp[i][1] = min(dp[i-1][0]+1, dp[i-1][1]+2);
            }
            else{
                dp[i][0] = min(dp[i-1][0]+2, dp[i-1][1]+1);
                dp[i][1] = min(dp[i-1][1], dp[i-1][0]+1);
            }
        }
        cout<<dp[l-1][1]<<endl;
    }
    return(0);
}
