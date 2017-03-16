//
//  main.cpp
//  gcj
//
//  Created by Jinfu Leng on 4/11/14.
//  Copyright (c) 2014 jinfu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void Solve(){
    int A, B, K;
    scanf("%d %d %d", &A, &B, &K);
    int cnt=0;
    for(int i=0;i<A;i++){
        for(int j=0;j<B;j++){
            //cout<<K<<" "<<(A&)<<endl;
            if((i&j) < K) cnt++;
        }
    }
    printf("%d\n",cnt);
}
int main(int argc, const char * argv[])
{
    freopen("/Users/jinfu/Workspace/test/input.in","r",stdin);
    freopen("/Users/jinfu/Workspace/test/output","w",stdout);
    int T;
    scanf("%d", &T);
    for(int t=0; t<T; t++){
        printf("Case #%d: ", t+1);
        Solve();
    }
    return 0;
}