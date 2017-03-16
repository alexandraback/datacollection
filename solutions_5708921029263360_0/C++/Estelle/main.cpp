//
//  main.cpp
//  1C_C
//
//  Created by Estelle :) on 08/05/2016.
//  Copyright © 2016 Estelle :). All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int k=1; k<=T; k++) {
        bool die=false;
        int J,P,S,K;
        scanf("%d%d%d%d", &J, &P, &S, &K);
        int ans=J*P*min(S,K);
        int v1[J+2][P+2], v2[P+2][S+2], v3[J+2][S+2];
        memset(v1,0,sizeof(v1));
        memset(v2,0,sizeof(v2));
        memset(v3,0,sizeof(v3));
        printf("Case #%d: %d\n", k, ans);
        int st[P+2];
        for (int i=0; i<P; i++) st[i+1]=(i*min(S,K))%S+1;
        for (int i=1; i<=J; i++) {
            for (int j=1; j<=P; j++) {
                int s=st[j];
                for (int m=s; m<s+min(S,K); m++) {
                    int x=m>S ? m-S : m;
                    v1[i][j]++, v2[j][x]++, v3[i][x]++;
                    if (v1[i][j]>K||v2[i][x]>K||v3[i][x]>K) die=true;
                    printf("%d %d %d\n", i, j, x);
                    st[j]++;
                    if (st[j]>S) st[j]-=S;
                }
            }
        }
        //if (die) printf("!!!");
    }
}
