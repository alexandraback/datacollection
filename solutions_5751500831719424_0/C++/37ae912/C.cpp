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
#define ABS(x) ( (x)<0 ? (-(x)) : (x) )

template<class T>void checkMin(T& r, T v){if(r>v)r=v;}
template<class T>void checkMax(T& r, T v){if(r<v)r=v;}

typedef long long LL;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef pair<int,int> PII;

const int N = 110;

vector<PII> v[N];
char buf[N];

int n;

void process(vector<PII>& vp)
{
    vp.clear();
    char c=buf[0];
    int len = strlen(buf);
    int cnt=0;
    FOR(i,len){
        if(c==buf[i]){++cnt;}
        else{
            vp.PB( MP( (int)(c-'a'), cnt ) );
            cnt = 1;
            c=buf[i];    
        }    
    }
    
    vp.PB( MP( (int)(c-'a'), cnt ) );
    
}

bool check()
{
    FOR(i,n-1){
        if(v[i].size() != v[i+1].size())return false;
        FOR(j,v[i].size()) if( v[i][j].first != v[i+1][j].first ) return false;    
    }    
    
    return true;
}

int mincost(VI& tv)
{
    int res = 1<<30;
    for(int i=1;i<=N;++i){
        int tmp = 0;
        
        FORI(it,tv) tmp += ABS( i - *it );    
        checkMin(res,tmp);
    } 
    
    return res;
}


int main()
{
    int cs=0,T;
    scanf("%d",&T);
    while(++cs <= T){
        //printf("Case #%d: ",cs);
        
        scanf("%d",&n);
        FOR(i,n){
            scanf("%s",buf);
            process(v[i]);
        }
        
        printf("Case #%d: ",cs);
        
        if(check()==false){
            puts("Fegla Won");
            continue;    
        }
         
        int ans = 0;
        FOR(i,v[0].size()){
            VI tv;
            FOR(j,n) tv.PB( v[j][i].second );
            ans += mincost(tv);
        }
        
        printf("%d\n",ans);
    }
    
    return 0;    
}
