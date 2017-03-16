//General Template 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <bitset> // bitset<N>, set, reset, flip, to_ulong
using namespace std;

#define FOR(i,n) for(int i=0;i<n;++i)
#define FORI(it,v) for(typeof(v.begin()) it=v.begin(); it!=v.end(); ++it)
#define MP(x,y) make_pair( (x), (y))
#define PB(x) push_back( x )

template<class T>void checkMin(T& r, T v){if(r>v)r=v;}
template<class T>void checkMax(T& r, T v){if(r<v)r=v;}

typedef long long LL;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef pair<int,int> PII;

const LL N = 1LL<<40;

LL gcd(LL a, LL b){return b==0 ? a : gcd(b,a%b);}

int main()
{
    int cs=0,T;
    scanf("%d",&T);
    while(++cs <= T){
        
        LL P,Q;
//        cin>>P>>Q;
        scanf("%I64d/%I64d",&P,&Q);
        LL g = gcd(P,Q);
        P /=g;
        Q /=g;
        
        printf("Case #%d: ",cs);
        
        if(N%Q){
            cout<<"impossible"<<endl;        
        }  
        else{
            P*= N/Q;
            int ans = 0;
            while(P){
                ++ans;
                P>>=1;    
            }
            --ans;
            cout<< 40-ans <<endl;
        }
         
    }
    
    return 0;    
}
