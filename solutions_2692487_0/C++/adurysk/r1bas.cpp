#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

#define LL long long
#define LD long double

#define VI vector<int>

#define sd(x) scanf("%d",&x)

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define PI pair< int , int >
#define PP pair< PI , PI >

int m[1000],a,n,k;

inline void solve(int test){
    int i,j,l,ans=100000;
    cin>>a>>n;
    for(i=0;i<n;i++){
        sd(m[i]);
    }
    sort(m,m+n);
    ans=n;
    if(a>1){
        for(j=0;j<n;j++){
            k=a;
            l=n-1-j;
            for(i=0;i<=j;i++){
                //cout<<j<<" "<<i<<" "<<k<<endl;
                while(k<=m[i]){
                    l++;
                    k+=k-1;
                }
                k+=m[i];
            }
            if(l<ans){
                ans=l;
            }
        }
    }
    printf("Case #%d: %d\n",test,ans);
}

int main(){
    freopen("A-small-attempt1.in","r",stdin);
    freopen("1bas2out.txt","w",stdout);

    int t,test=1;
    sd(t);
    while(t--){
        solve(test);
        test++;
    }
    return 0;
}
