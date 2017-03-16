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

const LL Mod = 1000000007LL;


const int N = 110;
string s[N];
int Right[30],Left[30],mid[30], all[30];
bool same[N];

LL f[30];

int pre[30];

bool test(VI& v)
{
    memset(pre,-1,sizeof(pre));
    //FOR(i,30)vs[i].clear();
    int len = 0;
    FORI(it,v){
        FOR(j,s[*it].length()){
            int k = s[*it][j]-'a';
            if( pre[ k ] == -1 || pre[k]==len+j-1) pre[k] = len + j;
            else return false;
        }
        len += s[*it].length();    
    }    
    
    return true;
}


bool test2(VI& v)
{
    string res = "";
    FORI(it,v) res+= s[ *it ];
    
    int i=0;
    //FOR(i,s.length()){
    while(i<res.length()){
        int j=i;
        while(j<res.length() && res[i]==res[j])++j;
        int cp = j;
        
        while(++j<res.length()){
            if(res[j]==res[i]) return false;
        }
        
        i = cp;
    }    
    
    //cout<<"true: "<<res<<endl;
    
    return true;
}


int main()
{
    f[0]=1;
    for(int i=1;i<=26;++i)f[i]=(i*f[i-1])%Mod;
    
    int cs=0,T;
    scanf("%d",&T);
    while(++cs <= T){
        //printf("Case #%d: ",cs);

        int n;
        cin>>n;
        
        FOR(i,n)cin>>s[i];
        
        VI v(n,0);
        
        int cnt = f[n];
        FOR(i,n)v[i]=i;
        
        int ans = 0;
        while(cnt--){
            if(test(v)) ++ans;
             next_permutation(v.begin(),v.end());    
        }
        printf("Case #%d: ",cs);
        cout<<ans<<endl;
        
    }
    
    return 0;    
}
