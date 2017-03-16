#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define MS0(A) memset(A,0,sizeof(A));
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,a,b) for(int i=a;i<=b;i++)
#define red(i,n) for(int i=n-1;i>=0;i--)
#define DA(A,n) {cout<<#A;rep(iii,n)cout<<' '<<A[iii];cout<<endl;}
#define D(x) {cout<<#x<<' '<<(x)<<endl;}
#define DD(x,y) {cout<<#x<<' '<<x<<' ';cout<<#y<<' '<<y<<endl;}
#define DDD(x,y,z) {cout<<#x<<' '<<x<<' ';cout<<#y<<' '<<y<<' ';cout<<#z<<' '<<z<<endl;}
#include<ext/rope>
#define __rope __gnu_cxx::
using namespace std;
typedef long long LL;
const int MAXN=111111;
const int oo=0X1FFFFFFF;
int PP=1000000007;
const long double PI=3.141592653589793;
template<typename TT>
void read(TT &x)
{
    char ch;
	for (ch=getchar(); ch>'9'||ch<'0'; ch=getchar()) ;
	for (x=0; ch>='0'&&ch<='9'; ch=getchar()) x=x*10+ch-48;
}
template<typename TT> void read2(TT &x,TT &y){read(x);read(y);}
template<typename TT> void read3(TT &x,TT &y,TT &z){read(x);read(y);read(z);}
int r,n,m,k,a[13],b[6];
void Init(){
    read(r);read3(n,m,k);
    rep(rr,r){
        rep(i,k)read(a[i]);
        MS0(b);
        rep(i,k){
            int j=0;
            for(j=0;a[i]%3==0;a[i]/=3) j++; b[3]=max(b[3],j);
            for(j=0;a[i]%5==0;a[i]/=5) j++; b[5]=max(b[5],j);
            for(j=0;a[i]%4==0;a[i]/=4) j++; b[4]=max(b[4],j);
            for(j=0;a[i]%2==0;a[i]/=2) j++; b[2]=max(b[2],j);
        }
        if(b[3]+b[5]==0) puts("234");else
        if(b[3]+b[5]==3){
            rep(i,b[3])printf("%c",'3');
            rep(i,b[5])printf("%c",'5');
            cout<<endl;
        }else
        if(b[3]+b[5]==2){
            rep(i,b[3])printf("%c",'3');
            rep(i,b[5])printf("%c",'5');
            printf("%c\n" ,(b[4]>0)?'4':'2');
        }else{
            rep(i,b[3])printf("%c",'3');
            rep(i,b[5])printf("%c",'5');
            if(b[4]==2) printf("%s\n","44");else
            if(b[2]==2) printf("%s\n","22");else
            printf("%s\n","24");
        }
    }
}
int main(){
    freopen("C-small-1-attempt0.in","r",stdin);
    freopen("C-small-1-attempt0.out","w",stdout);
    int T;read(T);
    rep(i,T){
        cout<<"Case #"<<i+1<<":\n";
        Init();
    }
}
