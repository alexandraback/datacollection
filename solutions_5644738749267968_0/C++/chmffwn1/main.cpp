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
    freopen("/Users/hao/Dropbox/chmffwn1/gcj/Qualification2014/D/D/D-small-attempt0.in", "r", stdin);
    freopen("/Users/hao/Dropbox/chmffwn1/gcj/Qualification2014/D/D/D.out", "w", stdout);
    //ios_base::sync_with_stdio(false);
    int T;
    cin>>T;
    repe(c,1,T){
        map<int,int> st_honest,st_cheat;
        int n;
        cin>>n;
        vector<double> girl, boy;
        girl.resize(n);
        boy.resize(n);
        rep(i,0,n){
            cin>>girl[i];
        }
        rep(i,0,n){
            cin>>boy[i];
        }
        sort(girl.begin(),girl.end());
        sort(boy.begin(),boy.end());
        int idx=0;
        int re_cheat=0,re_honest=0;
        rep(i,0,n){
            if(girl[i]<boy[idx]) continue;
            else{
                re_cheat++;
                idx++;
            }
        }
        idx=0;
        rep(i,0,n){
            if(boy[i]<girl[idx]) continue;
            else{
                re_honest++;
                idx++;
            }
        }
        re_honest=n-re_honest;
        cout<<"Case #"<<c<<": "<<re_cheat<<" "<<re_honest<<endl;
    }
	return 0;
}