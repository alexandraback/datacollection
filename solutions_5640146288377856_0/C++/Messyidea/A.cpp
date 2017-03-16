/***********************************************\
 |Author: YMC
 |Created Time: 2015/5/10 18:35:34
 |File Name: A.cpp
 |Description: 
\***********************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#define L(rt) (rt<<1)
#define R(rt) (rt<<1|1)
#define mset(l,n) memset(l,n,sizeof(l))
#define rep(i,n) for(int i=0;i<n;++i)
#define maxx(a) memset(a, 0x3f, sizeof(a))
#define zero(a) memset(a, 0, sizeof(a))
#define srep(i,n) for(int i = 1;i <= n;i ++)
#define MP make_pair
const int inf=0x3f3f3f3f ;
const double eps=1e-8 ;
const double pi=acos (-1.0);
typedef long long ll;

using namespace std;
int R,W,C;
int cas = 1;
int solve(int r,int c,int w) {
    int ans = c / w * r + w;
    if(c % w == 0 || w == 1 || w == c) ans --;
    return ans;
}
int main() {
	//freopen("input.txt","r",stdin); 
	freopen("A-small-attempt1.in","r",stdin); 
	freopen("out.txt","w",stdout); 
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d %d",&R,&C,&W);
        //solve(R,C,W);
        printf("Case #%d: %d\n",cas ++, solve(R,C,W));
    }
	return 0;
}

