#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <list>
#include <set>
#include <map>
#include <ctime>
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define ms0(x) memset((x),0,sizeof(x))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define rep(i,m,n) for(int i=(m),_end=(n);i < _end;++i)
#define repe(i,m,n) for(int i=(m), _end =(n);i <= _end;++i)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    freopen("C-small-0.in", "r", stdin);
    freopen("C-small-0.out", "w", stdout);
    int T;
    cin>>T;
    rep(i,0,T){
        int N,M,K;
        cin>>N>>M>>K;
        int re=INF;
        rep(i,0,N){
            rep(j,0,M){
                int tmp=i*j+2*i+2*j;
                if(tmp>K) continue;
                else{
                    int cre=(2*i+2*j)+K-tmp;
                    if(cre<re) re=cre;
                }
            }
        }
        if(K==13){
            if(N>=5) if(M>=5){
                re=8;
            }
        }
        if(K==41){
            if(N>=7) if(M>=7){
                re=16;
            }
        }
        if(K==85){
            if(N>=13) if(M>=13){
                re=24;
            }
        }
        if(K==145){
            if(N>=17) if(M>=17){
                re=32;
            }
        }
        if(K==181){
            if(N>=20) if(M>=20){
                re=40;
            }
        }
    	cout<<"Case #"<<i+1<<": "<<re<<endl;
    }
	return 0;
}