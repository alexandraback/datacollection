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

vector<int> vs;
int E,R,N;
int solve(int e,int at){
    if(at==N) return 0;
    int ret=0;
    if(at==N-1) ret=e*vs[at];
    else{
        for(int i=0;i<=e;i++){
            ret=max(ret,i*vs[at]+solve(min(E,e-i+R),at+1));
        }
    }
    return ret;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int ix=0;ix<T;ix++){
        printf("Case #%d: ",ix+1);
        scanf("%d%d%d",&E,&R,&N);
        vs=vector<int>(N);
        for(int i=0;i<N;i++){
            scanf("%d",&vs[i]);
        }
        printf("%d\n",solve(E,0));
    }
}
