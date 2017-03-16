// Majestic12::SourceCode
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<utility>
#include<sstream>
using namespace std;
typedef long long int64;
typedef long double real;
#define PI  3.14159265358979323846264338327950288419716939937510
#define PHI 1.61803398874989484820458683436563811772030917980576
#define DELIM " !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"
#define read(x) scanf("%d",&x)
#define write(x) printf("%d\n",x)
#define cls(x) memset(x,0,sizeof(x))
#define mp(x,y) make_pair(x,y)
template <class datatype> datatype gcd(datatype a,datatype b){ return (b==0)?a:gcd(b,a%b); }
template <class datatype> datatype lcm(datatype a,datatype b){ return a*(b/gcd(a,b)); }
template <class datatype> datatype mod_multiply(datatype a,datatype b,datatype m){ datatype x=0, y=a%m; b%=m; while(b){ if(b%2) x=(x+y)%m; y=(2*y)%m; b/=2; } return x%m; }
template <class datatype> datatype mod_power(datatype n,datatype e,datatype m){ datatype p=n,r=1; while(e){ if(e%2) r=mod_multiply(r,p,m); p=mod_multiply(p,p,m); e/=2; } return r; }

int main(){
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int t,tt,n,i,j,k;
    double a[200],sum,x,y;
    for(t=1,read(tt);t<=tt;++t){
        sum = 0;
        read(n); for(i=0;i<n;++i){ cin>>a[i]; sum+=a[i]; }
        cout<<"Case #"<<t<<":";
        for(i=0;i<n;++i){
            double left=0,right=1,mid=0.5;
            //cout<<endl;
            while(1){
                x = a[i]+mid*sum;
                y = 0;
                for(j=0;j<n;++j) if(j!=i and a[j]<x) y+=(x-a[j])/sum;
                //cout<<mid<<" "<<x<<" "<<y<<endl;
                if(y>1-mid) right=mid; else left=mid;
                if(abs(mid-(left+right)/2)<0.0000000001) break;
                else mid = (left+right)/2;
                }
            printf(" %.6llf",mid*100);
            }
        cout<<endl;
        }
    return 0;
    }
