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
    map<int,int> sum1,sum2,sum3;
    map<int,int>::iterator s;
    int t,tt,a[50],i,j,k,n;
    for(t=1,read(tt);t<=tt;++t){
        sum1.clear(); sum2.clear(); sum3.clear();
        read(n); for(i=0;i<n;++i) read(a[i]);
        for(i=0;i<(1<<n);++i){
            for(j=k=0;j<n;++j) if(i&(1<<j)) k+=a[j];
            if(sum1.find(k)==sum1.end()) sum1[k]=i;
            else if(sum2.find(k)==sum2.end()) sum2[k]=i;
            }
        cout<<"Case #"<<t<<":"<<endl;
        for(s=sum2.begin();s!=sum2.end();++s){
            k = s->second;
            for(j=0;j<n;++j) if(k&(1<<j)) cout<<a[j]<<(j==n-1?"":" "); cout<<endl;
            k = sum1.find(s->first)->second;
            for(j=0;j<n;++j) if(k&(1<<j)) cout<<a[j]<<(j==n-1?"":" "); cout<<endl;
            break;
            }
        if(s==sum2.end()) cout<<"Impossible"<<endl;
        }
    return 0;
    }
