// {{{
// vim:filetype=cpp foldmethod=marker foldmarker={{{,}}}
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <climits>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define ALL(A)		(A).begin(),(A).end()
#define DUMP(A)    cout<<#A<<"="<<(A)<< endl
#define SIZE(A)    (int)((A).size())
#define MP  make_pair
#define PB  push_back
using namespace std;
typedef long long ll;

int vx[]={1,0,-1,0},vy[]={0,1,0,-1};
// }}}

vector<ll> pal;
bool is_pal(ll n){
    stringstream ss;
    ss<<n;
    string now=ss.str(),rev=now;
    reverse(ALL(rev));
    return now==rev;
}
int main(){
    int T;
    scanf("%d",&T);
    for(ll i=1;i<=10000000;i++){
        if(is_pal(i) && is_pal(i*i)) pal.PB(i*i);
    }
    for(int ix=0;ix<T;ix++){
        printf("Case #%d: ",ix+1);
        int A,B;
        scanf("%d%d",&A,&B);
        int ret=0;
        for(int i=0;i<pal.size();i++){
            if(A<=pal[i] && pal[i]<=B) ret++;
        }
        printf("%d\n",ret);
    }
}
