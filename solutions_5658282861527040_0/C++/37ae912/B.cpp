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


int main()
{
    int cs=0,T;
    scanf("%d",&T);
    while(++cs <= T){
        int a,b,k;
        scanf("%d%d%d",&a,&b,&k);
        int ans=0;
        FOR(i,a)FOR(j,b) if((i&j)<k) ++ans;
        printf("Case #%d: ",cs);
        printf("%d\n",ans);
         
    }
    
    return 0;    
}
