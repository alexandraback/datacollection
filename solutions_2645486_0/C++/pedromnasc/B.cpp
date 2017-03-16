#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdlib>

#define MAX 20

using namespace std;

typedef long long int ll;

int T,E,R,N;
int v[MAX];
int pd[10][MAX];

int doit(int energ,int atual){

    if(atual == N) return 0;

    if(pd[energ][atual]!=-1) return pd[energ][atual];

    int resp=0;
    for(int i=0;i<=energ;i++){
        resp=max(resp,i*v[atual]+doit(min(energ-i+R,E),atual+1));
    }

    return pd[energ][atual]=resp;

}

int main(void){

    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);


    scanf("%d",&T);

    for(int caso=1;caso<=T;caso++){

        memset(pd,-1,sizeof(pd));

        scanf("%d %d %d",&E,&R,&N);

        for(int i=0;i<N;i++){
            scanf("%d",&v[i]);
        }

        printf("Case #%d: %d\n",caso,doit(E,0));
    }

    return 0;
}
