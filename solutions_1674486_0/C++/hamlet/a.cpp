#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdio.h>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;  // H A M L E T
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}long long lcm(long long a,long long b){return a*(b/gcd(a,b));}

vector<int>v[1001];
int n;
int memo[1001][1001];

int dp(int ini,int fini){
    if(ini==fini)return 1;
    if(v[ini].size()==0)return 0;
    
    int dev=0;
    for(int i=0;i<v[ini].size();i++){
        dev+=dp(v[ini][i],fini);
    }
    
    dev=min(dev,2);
    memo[ini][fini]=dev;
    return dev;
}

int main(){
    
   // cout<<24+75*0.34666666666<<" "<<30+75*0.26666666666<<" "<<21+75*0.38666666666666666<<endl;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
   	int tc;cin>>tc;
	for(int caso=1;caso<=tc;caso++){
        cin>>n;
        for(int i=0;i<1001;i++)v[i].clear();
        
        for(int i=0;i<n;i++){
            int t;
            cin>>t;
            for(int j=0;j<t;j++){
                int val;cin>>val;
                v[i].push_back(val-1);    
            }
        }
        
        bool ok=0;
        memset(memo,-1,sizeof(memo));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if( dp(i,j)>=2){
                    ok=1;break;
                }    
            }
            if(ok)break;
        }
        
        
        cout<<"Case #"<<caso<<": ";
        if(ok)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        
    }
	
	return 0;
}
