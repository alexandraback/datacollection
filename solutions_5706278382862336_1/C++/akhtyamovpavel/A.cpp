#include <cstdio>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <complex>
#include <iomanip>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<vector<int> > graph;
const int INF = 1000000000;
const ll MOD = 1000000009;
#define FILEIN "A.in"
#define FILEOUT "A.out"

ll gcd(ll a, ll b){
    if(b == 0)
        return a;
    return gcd(b,a%b);
}
bool check(ll N){
    while(N!=1){
        if(N%2 == 1)
            return false;
        N/=2;
    }
    return true;
}
int main(){
    freopen(FILEIN,"r",stdin);
    freopen(FILEOUT,"w",stdout);
    int tests;
    cin>>tests;
    for(int _ = 1; _ <= tests; ++_){
    	string s;
        cin>>s;
        int pos = s.find("/");
        ll res1 = 0;
        for(int i =0; i < pos; ++i){
            res1 = res1*10 + s[i] - '0';
        }
        ll res2 = 0;
        for(int i = pos + 1; i < s.length(); ++i){
            res2 = res2*10 + s[i] - '0';
        }
        cout<<"Case #"<<_<<": ";

        ll g = gcd(res1, res2);
        res1/=g;
        res2/=g;
        bool f = check(res2);
        if(!f){
            cout<<"impossible"<<endl;
            continue;
        }
        if(res1 == 1 && res2 == 1){
            cout<<0<<endl;
            continue;
        }
        else{
            int gen = 0;
            while(res2 != 1){
                if(res2%2 == 1){
                    cout<<"impossible"<<endl;
                    goto endi;
                }
                else{
                    ++gen;
                    res2/=2;
                    if(res1 >= res2)
                        break;
                }
            }
            cout<<gen<<endl;
            endi:;
        }
    	
        
    }
    return 0;
}