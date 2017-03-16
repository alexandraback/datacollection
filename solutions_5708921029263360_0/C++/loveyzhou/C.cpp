#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

bool used[15][15][15];
int countjp[15][15];
int countps[15][15];
int countjs[15][15];



int main(){

    freopen("C-small-attempt2.in","r",stdin);
    freopen("C-small-attempt2.out","w",stdout);

    int ti,t,j,p,s,k,ji,pi,si;
    int counttmp;
    scanf("%d",&t);
    for (ti=1;ti<=t;ti++){
        scanf("%d%d%d%d",&j,&p,&s,&k);
        for(ji=1;ji<=j;ji++)
            for(pi=1;pi<=p;pi++)
                for(si=1;si<=s;si++)
                    used[ji][pi][si]=false;
        for(ji=1;ji<=s;ji++)
            for(pi=1;pi<=s;pi++)
                countjp[ji][pi]=countps[ji][pi]=countjs[ji][pi]=0;
        counttmp=0;
        for(si=1;si<=s;si++)
            for(pi=1;pi<=p;pi++)
                for(ji=1;ji<=j;ji++){
                    int ji2=ji;
                    int pi2=(pi+ji)%p+1;
                    int si2=(si+pi)%s+1;
                    if(countjp[ji2][pi2]<k&&countps[pi2][si2]<k&&countjs[ji2][si2]<k){
                        countjp[ji2][pi2]++;
                        countps[pi2][si2]++;
                        countjs[ji2][si2]++;
                        counttmp++;
                        used[ji2][pi2][si2]=true;
                    }
                    }
        printf("Case #%d: %d\n",ti,counttmp);
        for(ji=1;ji<=j;ji++)
            for(pi=1;pi<=p;pi++)
                for(si=1;si<=s;si++)
                    if(used[ji][pi][si])
                        printf("%d %d %d\n",ji,pi,si);
    }
    return 0;
}
