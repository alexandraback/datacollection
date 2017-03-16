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

int N, J;

int main()
{
    freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    freopen("C-large.in","r",stdin);
    int t, test = 0;
    cin>>t;
    while(t--){
        cout<<"Case #"<<++test<<": "<<endl;
        cin>>N>>J;
        int a1[20], a2[20];
        a1[0] = a2[0] = 0;
        a1[1] = 1; a2[1] = 2;
        for(int i = 2; i < 20; i++){
            a1[i] = a1[i-1]+2;
            a2[i] = a2[i-1]+2;
        }
        int ans_count = 0;
        for(int i = 0; i < (1<<(N-2)); i++){
            if(ans_count >= J) break;
            int one_count = 0;
            int tmp = i;
            while(tmp > 0){
                if(tmp&1) one_count++;
                tmp >>= 1;
            }
            if(a2[one_count] < N-1){
                int n1, n2;
                n2 = one_count;
                if(N&1) n1 = n2+2;
                else n1 = n2;
                ans_count++;
                int index1[20], index2[20];
                for(int j = 1; j <= n1; j++) index1[j] = a1[j];
                int l1 = 0, l2 = 0;
                tmp = i;
                while(tmp > 0){
                    l2++;
                    if(tmp&1) index2[++l1] = l2;
                    tmp >>= 1;
                }
                string ans(N, '0');
                ans[0] = ans[N-1] = '1';
                for(int j = 1; j <= n2; j++) index2[j] = a2[index2[j]];
                // for(int j = 1; j <= n2; j++) cout<<index2[j]<<' '; cout<<endl;
                for(int j = 1; j <= n1; j++) ans[index1[j]] = '1';
                for(int j = 1; j <= n2; j++) ans[index2[j]] = '1';
                cout<<ans<<' ';
                for(int j = 2; j <= 10; j++){
                    if(j&1) cout<<2<<' ';
                    else cout<<j+1<<' ';
                }
                cout<<endl;
            }
        }
    }
    return(0);
}
