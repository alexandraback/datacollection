#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stdlib.h>
#include<cmath>
using namespace std;


int main(){
    const int N = 1008;
    int T, nn, d[N], n[N], w[N], e[N], s[N], dd[N], dp[N], ds[N];
    int h[1000], nh[1000];
    scanf("%d",&T);
    for(int t=1; t<=T; t++){
        scanf("%d",&nn);
        int MaxDay = -1;
        for(int i=0; i<nn; i++){
            scanf("%d%d%d%d",&d[i],&n[i],&w[i],&e[i]);
            scanf("%d%d%d%d",&s[i],&dd[i],&dp[i],&ds[i]);
            MaxDay = max( MaxDay, d[i]+dd[i]*(n[i]-1) );
        }
        memset( h, 0, sizeof(h) );

        int total = 0;
        for(int day=0; day<=MaxDay;day++){
            //for(int i=0; i<10000; i++) nh[i] = h[i];
            int first = 0;
            for(int i=0; i<nn; i++){
                if( day>=d[i] && (day-d[i])%dd[i]==0 && day<=d[i]+(n[i]-1)*dd[i] ){
                    if( first==0 ){
                        first = 1;
                        for(int j=0; j<1000; j++) nh[j] = h[j];
                    }

                    //cout<<day<<" "<<i<<" -- ";
                    int time = (day-d[i])/dd[i], S = s[i]+time*ds[i];
                    bool success = false;
                    for(int we=(w[i]+time*dp[i]+200)*2; we<=(e[i]+time*dp[i]+200)*2; we++){
                        //cout<<we<<" "<<h[we+100]<<"  --  ";
                        if( h[we]<S ){ success = true; nh[we] = max(nh[we],S); }
                    }
                    if( success ) total++;
                    //cout<<total<<endl;
                }
            }
            if( first==1 ) for(int i=0; i<1000; i++) h[i] = nh[i];
        }
        printf("Case #%d: %d\n",t,total);
    }
    return 0;
}

