//DER.......
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<functional>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<limits.h>
#include<ctype.h>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<vector>
#include<iostream>
#include<sstream>
using namespace std;

// #defines
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define LPI(i,n) for(int i=0;i<(n);i++)
#define LPI1(i,a,b) for(int i=(a);i<=(b);i++)
#define LPIL(i,x) for(int i=0;x[i];i++)
#define LPD(i,n) for(int i=(n)-1;i>=0;i--)
#define LPD1(i,a,b) for(int i=(a);i>=(b);i--)
#define I(x) scanf("%d",&x)
#define RI(x) int x;I(x)
#define II(x,y) scanf("%d%d",&x,&y)
#define RII(x,y) int x,y;II(x,y)
#define III(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define RIII(x,y,z) int x,y,z;III(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define CASET int ___T,cas=1;scanf("%d ",&___T);while(___T--)
#define CASEN0(n) int cas=1;while(scanf("%d",&n)!=EOF&&n)
#define CASEN(n) int cas=1;while(scanf("%d",&n)!=EOF)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
#define F first
#define S second
#ifdef ONLINE_JUDGE
#define FILEIO(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout);
#define FILEIOS freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
#define FILEIO(x) ;
#define FILEIOS ;
#endif
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;
LL A[]={0,1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004,100000000000009};
char T[105][105];
int Lsearch(LL value,int left,int right)
{
    int mid;
    if(right<left)
    return left;
    mid=floor((left+right)/2);
         if(A[mid]==value)
         return mid;
         if(A[mid]>value)
          Lsearch(value,left,mid-1);
        else
          Lsearch(value,mid+1,right);

}
int Rsearch(LL value,int left,int right)
{
    int mid;
    if(right<left)
    return right;
    mid=floor((left+right)/2);
         if(A[mid]==value)
         return mid;
         if(A[mid]>value)
          Rsearch(value,left,mid-1);
        else
          Rsearch(value,mid+1,right);

}
int main(){
    //FILEIO("B-small-practice");
   freopen("C-large-1.in","r",stdin);
   freopen("C-large-1.out","w",stdout);

   LL a,b;
   int l,r,t;
  cin>>t;
  LPI(i,t)
  {
      cin>>a>>b;
      l=Lsearch(a,1,39);
      r=Rsearch(b,1,39);
      cout<<"Case #"<<i+1<<": "<<r-l+1<<endl;
  }

    return 0;
}


