#include <vector>
#include <list>
#include <map>
#include <set>
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
using namespace std;
#define maxn 100010
#define LL long long
int T,R,N,M,K;
int S[20];
int A[10];
int m[20];
bool f;
bool check(int h){
    int r=1<<K;
    for(int i=0;i<r;i++){
        int hh=i;
        int cnt=1;
        for(int j=0;j<N;j++){
            if(hh%2==1){
                cnt*=A[j];
            }
            hh/=2;
        }
        if(cnt==h) return true;
    }
    return false;
}
void dfs(int h){
    if(f) return;
    if(h==N){
        int i;
        for(i=0;i<K;i++){
            if(!check(S[i])) break;
        }
        if(i>=K){
            for(int j=0;j<N;j++)printf("%d",A[j]);
            printf("\n");
            f=true;
        }
        return;
    }
    for(int i=2;i<=M;i++){
        A[h]=i;
        dfs(h+1);
    }
    return;
}
int main(int argc, const char * argv[])
{
    freopen("C-small-1-attempt0.in","r",stdin),freopen("C-small-1-attempt0.out","w",stdout);
    cin>>T;
    for(int ca=1;ca<=T;ca++){
        printf("Case #%d:\n",ca);
        cin>>R>>N>>M>>K;
        while(R--){
            for(int i=0;i<K;i++){
                cin>>S[i];
            }
            f=false;
            dfs(0);
        }
    }
}

