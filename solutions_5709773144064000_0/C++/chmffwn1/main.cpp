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
    freopen("/Users/hao/Dropbox/chmffwn1/gcj/Qualification2014/B/B/B-small-attempt0.in", "r", stdin);
    freopen("/Users/hao/Dropbox/chmffwn1/gcj/Qualification2014/B/B/B.out", "w", stdout);
    //ios_base::sync_with_stdio(false);
    int T;
    cin>>T;
    repe(c,1,T){
        double C,F,X;
        cin>>C>>F>>X;
        double get=2;
        double re=0;
        get=(X-C)*F/C;
        if(get<=0) re=X/2;
        else{
            int num=0;
            num=(int)((get-2)/F+1);
            rep(i,0,num){
                re+=C/(2+i*F);
            }
            re+=X/(2+F*num);
        }
        cout.precision(7);cout.setf(ios::fixed);
        cout<<"Case #"<<c<<": "<<re<<endl;
    }
	return 0;
}