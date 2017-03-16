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
    freopen("c.txt","r",stdin);
    freopen("d.txt","w",stdout);
    scanf("%d",&T);
    for (int datanum=1;datanum<=T;datanum++){
        LL N;
        cin>>N;
        printf("Case #%d: ",datanum);
        if (N<=10) {printf("%d\n",N);continue;}
        LL Tm=10;
        int len=2;
        LL ans=10;
        LL tmp=9;
        while (Tm*10<=N){
            Tm=Tm*10;
            len++;
            if (len%2){
                ans+=tmp+tmp+1;
            }else{
                ans+=tmp*10+9+tmp+1;
                tmp=tmp*10+9;
            }
        }
        int ttt=0;
        if (N%10==0) ttt=1,N-=1;
        LL ans1=ans+N-Tm,ans2=ans;
        int num[20];
        ans=N;
        for (int i=1;i<=len;i++){
            num[len-i+1]=N%10;
            N/=10;
        }
        for (int i=0;i<=len;i++){
            LL t1=0,t2=0;
            for (int j=i;j>0;j--) t1 = t1 * 10 + num[j];
            for (int j=i+1;j<=len;j++) t2 = t2 * 10 + num[j];
            ans=min(ans,t1+t2);
        }
        ans1=min(ans+ans2,ans1)+ttt;
        cout<<ans1<<endl;
    }
    return 0;
}
