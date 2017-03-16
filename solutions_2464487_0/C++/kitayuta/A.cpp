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

int main(){
    int T;
    scanf("%d",&T);
    for(int ix=0;ix<T;ix++){
        printf("Case #%d: ",ix+1);
        double r,t;
        scanf("%lf%lf",&r,&t);
        double x=(-(2*r-1)+sqrt((2*r-1)*(2*r-1)+8*t))/4;
        ll n1=x-1,n2=x,n3=x+1;
        if(2*n3*n3+(2*r-1)*n3<=t) printf("%lld\n",n3);
        else if(2*n2*n2+(2*r-1)*n2<=t) printf("%lld\n",n2);
        else printf("%lld\n",n1);
    }
}
