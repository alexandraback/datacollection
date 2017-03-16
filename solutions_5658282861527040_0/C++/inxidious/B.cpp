#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<map>
#include<set>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define INF 2100000000
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

int main(){
    freopen("Bsmall.in","r",stdin);
    freopen("output.txt","w",stdout);
    /*REP(i,0,15){
        REP(j,0,15)
            printf("%2d ",i&j);
        printf("\n");
    }*/
    int tc,a,b,k,tot;
    scanf("%d",&tc);
    REP(nc,1,tc){
        tot=0;
        printf("Case #%d: ",nc);
        scanf("%d%d%d",&a,&b,&k);
        REP(i,0,a-1)
            REP(j,0,b-1)
                if((i&j)<k)
                    tot++;
        printf("%d\n",tot);
    }
    return 0;
}
