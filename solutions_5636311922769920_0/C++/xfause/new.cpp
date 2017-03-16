#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include<set>
#include<stack>
#include<map>
#include<ctime>
#include<bitset>
#define LL long  long
#define db double
#define EPS 1e-15
#define inf 1e10

using namespace std;

int main(){
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int T,cas=1;
    scanf("%d",&T);
    while (T--){
        int k,c,s;
        scanf("%d%d%d",&k,&c,&s);
        printf("Case #%d:",cas++);
        for (int i=1;i<=s;i++)
            printf(" %d",i);
        puts("");
    }
    return 0;
}
