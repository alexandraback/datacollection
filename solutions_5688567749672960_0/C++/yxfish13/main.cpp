//
//  main.cpp
//  beaty
//
//  Created by yxfish13 on 15/5/2.
//  Copyright (c) 2015年 x-yu13. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
const int maxn = 1001000;
using namespace std;
#define LL long long
int opt[maxn];
LL reverse(LL a){
    //int num[20];
    LL X=0;
    if (a%10==0) return a;
    int len=0;
    while (a){
      //  num[len]=a%10;
        //len++;
        X=X*10+a%10;
        a/=10;
    }
    return X;
}
int main(int argc, const char * argv[]) {
    int T;
    freopen("a.txt","r",stdin);
    freopen("b.txt","w",stdout);
    scanf("%d",&T);
    for (int datanum=1;datanum<=T;datanum++){
        LL N;
        cin>>N;
        memset(opt,10,sizeof(opt));
        printf("Case #%d: ",datanum);
        opt[0]=0;
        for (int i=1;i<=N;i++){
            opt[i]=min(opt[reverse(i)]+1, opt[i-1]+1);
        }
        printf("%d\n",opt[N]);
    }
    return 0;
}
