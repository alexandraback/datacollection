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
    bool graph[1000][1000], visited[1000];
    int t,tt,m,n,i,j,k;
    queue<int> q;
    for(read(tt),t=1;t<=tt;++t){
        cls(graph);
        read(n);
        for(i=0;i<n;i++){
            read(m);
            for(j=0;j<m;++j){
                read(k); --k; // i inherits from k, properties move from k to i
                graph[k][i] = 1;
                }
            }
        for(i=0;i<n;++i){
            cls(visited);
            while(!q.empty()) q.pop();
            q.push(i); visited[i]=1;
            while(!q.empty()){
                //cout<<"Current "<<q.front()<<endl;
                for(j=0;j<n;++j) if(graph[q.front()][j]){
                    if(visited[j]) break;
                    else { q.push(j); visited[j]=1; if(0)cout<<"Visiting "<<j<<endl;; }
                    }
                if(j<n) break;
                else q.pop();
                }
            if(!q.empty()) break;
            }
        cout<<"Case #"<<t<<": ";
        if(i<n) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        }
    return 0;
    }
