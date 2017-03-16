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

int solve(VI& v1, VI& v2, bool first)
{
    int res = 0, res2=0;
    for(int i=0,j=0; i<v1.size(); ++i){
        while(j<v2.size() && v2[j] < v1[i]) ++j;
        if(j<v2.size()){
            ++res;
            ++j;    
        }
        else ++res2;
    }    
    return first ? res : res2;
}


int main()
{
	int T,cs=0;
	cin>>T;
	while(++cs <= T){
        VI va,vb;
        int n;
        scanf("%d",&n);
        int a,b;
        FOR(i,n){ scanf("%d.%d",&b,&a); va.PB(a);}
        FOR(i,n){ scanf("%d.%d",&b,&a); vb.PB(a);}
        sort(va.begin(), va.end());
        sort(vb.begin(), vb.end());
        
        //puts("va:");
        //copy(va.begin(), va.end(), ostream_iterator<int>(cout,",")); puts("");
        
        //puts("vb:");
        //copy(vb.begin(), vb.end(), ostream_iterator<int>(cout,",")); puts("");
        
        printf("Case #%d: %d %d\n",cs, solve(vb,va,true), solve(va,vb,false));
    }
    return 0;   
}
