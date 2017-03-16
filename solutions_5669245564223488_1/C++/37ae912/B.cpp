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


int pre[N];

int p[N];
bool vis[N];

bool check(int j)
{
    if(j==-1)return true;
    if(vis[j])return false;
    
    vis[j]=true;
    check(p[j]);
}

bool test(string& res)
{
    memset(pre,-1,sizeof(pre));

    FOR(j,res.length()){
        int k = res[j]-'a';
        if( pre[ k ] == -1 || pre[k]==j-1) pre[k] = j;
        else return false;
    }
    
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
        
        memset(Left,0,sizeof(Left));
        memset(Right,0,sizeof(Right));
        memset(mid,0,sizeof(mid));
        memset(all,0,sizeof(all));
        memset(same,0,sizeof(same));

        int n;
        cin>>n;
        FOR(i,n)cin>>s[i];
        
        /*
        if(cs != 57)continue;
        cout<<n<<endl;
        FOR(i,n)cout<<s[i]<<endl;
        continue;
        */
        
        bool valid=true;
        
        // check aaaxxaaa
        
        FOR(i,n){
            if(s[i][0] != s[i][ s[i].length()-1 ])    continue;
            FOR(j,s[i].length()){
                if(s[i][j] != s[i][0]){
                    valid = false;
                    break;    
                }    
            }
            if(valid==false)break;
            
            same[i]=true;
            all[ s[i][0]-'a' ]++;
        }
        
        FOR(i,n){
            if(test(s[i])==false){
                
                valid = false;
                break;    
            }    
        }

        FOR(i,n){
            if(same[i])continue;
            char lc = s[i][0];
            char rc = s[i][ s[i].length()-1 ];
            
            Left[ lc-'a' ]++;
            Right[rc-'a' ]++;
            FOR(j,s[i].length()){
                if(s[i][j] == lc || s[i][j] == rc) continue;
                mid[ s[i][j]-'a' ]++;    
            }
        }
        
        FOR(i,26){
            if(mid[i]){
                if( Left[i] || Right[i] || all[i]) valid = false;    
            }    
            else{
                if(Left[i]>1 || Right[i]>1) valid = false;    
            }
        }
        
        
                
        LL ans = 1LL;
        int cnt = 0;
        

        memset(p,-1,sizeof(p));
        
        VI fix(30,0);
        FOR(i,n){
            if( same[i] ){
                char c = s[i][0];
                if( Right[c-'a'] || Left[c-'a'] )   fix[c-'a'] = 1;
                continue;
            }
            
            // not the head of a chain
            if( Right[ s[i][0]-'a' ] ){
                
                continue;
            }
            
            ++cnt;
        }
        
        //cout<<"p[0]="<<p[0]<<endl;
        
        FOR(i,n) vis[i]=false;
        
        FOR(i,n){
            if( (vis[i]==false) && check(i)==false){
                cout<<"check "<<i<<" is false"<<endl;
                valid = false;
                break;
            }    
        }
        
        if(valid==false){
            printf("Case #%d: ",cs);
            puts("0");
            continue;    
        }


        FOR(i,30){
            ans = (ans * f[ all[i] ] ) % Mod;
            if(all[i] && fix[i]==0) ++cnt;  
        }
        
        //cout<<"cnt="<<cnt<<", cur="<<ans<<endl;
        
        ans = (ans * f[ cnt ])%Mod;
        printf("Case #%d: ",cs);
        cout<<ans<<endl;
    }
    
    return 0;    
}
