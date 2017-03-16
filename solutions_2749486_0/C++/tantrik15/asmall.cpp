/*
    TanTr!k.$aX
*/

using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>
#include<utility>
#include<climits>
#include<sstream>

#define unsigned long long int ulli
#define FRm(i, m, n)     for( int i = m; i <=n; i++)
#define FRrev(i, n)         for( int i = n; i >= 0; i-- )
#define FRrevm(i,n,m)         for( int i = n; i >= m; i-- )
#define max(a,b) ((a)>(b)?(a):(b))
#define S(a) scanf("%d",&(a))
#define P(a) printf("%d",(a))
#define min(a,b) ((a)<(b)?(a):(b))
#define NL printf("\n")
#define sqr(a) ((a)*(a))
#define SL(a) scanf("%lld",&(a))
#define PL(a) printf("%lld",(a))
#define lli long long int
#define FOR(I,A,B) for(int I= (A); I<(B); ++I)
#define inarrd(arr,n) for(int i=0;i<n;i++)S(arr[i]);
#define outarrd(arr,n) for(int i=0;i<n;i++){PFd(arr[i]);PF(" ");}NL;
#define outarrN(arr,n) for(int i=0;i<n;i++){PFd(arr[i]);PFN;}

int main(){
    int tc,cs=1,x,y;
    char l,r,n,s;

    //string s;
    freopen("C:\\Users\\tantrik\\Desktop\\input.txt","r",stdin);
    freopen("C:\\Users\\tantrik\\Desktop\\output.txt","w",stdout);
    S(tc);
    while(tc--){
       S(x);S(y);




       if(x<0){
           l='E';
           r='W';
       }
       if(x>0){
           l='W';
           r='E';
       }
       if(y<0){
           s='N';
           n='S';
       }
       if(y>0){
           s='S';
           n='N';
       }
       x=x>0?x:x*-1;
       y=y>0?y:y*-1;
       cout<<"Case #"<<cs++<<": ";
       if(x!=0)
       for(int i=0;i<x;i++)
           cout<<l<<r;
       if(y!=0)
       for(int i=0;i<y;i++)
            cout<<s<<n;
       cout<<endl;
       //printf("Case #%d: %d\n",cs++,ans);
    }
}
