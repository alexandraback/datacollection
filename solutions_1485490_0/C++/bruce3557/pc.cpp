//
//  pc.cpp
//  
//
//  Created by mac on 12/5/6.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int n,m;
long long tmp;
long long max;
struct node {
    int label;
    long long num;
    
    node() {}
    node(long long _num, int _label) {
        label = _label;
        num = _num;
    }
} toy[110], box[110];

void go(int a, int b, long long sum) {
    if(a >= n || b >= m) {
        if(sum > max)   max = sum;
        return;
    }
    
    go(a+1, b, sum);
    
    long long total = 0;
    int type = toy[a].label;
    for(int i=b;i<m;++i) 
        if(type == box[i].label) {
            if(total > toy[a].num)  break;
            double prv = total;
            total += box[i].num;
            long long dx = (total < toy[a].num) ? total : toy[a].num;
            box[i].num -= dx-prv;
            toy[a].num -= dx;
            go(a+1, i, sum+dx);
            box[i].num += dx-prv;
            toy[a].num += dx;
        }
    
}

int main() {
    int t, cases=0;
    
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i) {
            long long num;
            int label;
            scanf("%lld%d", &num, &label);
            toy[i] = node(num, label);
        }
        for(int i=0;i<m;++i) {
            long long num;
            int label;
            scanf("%lld%d", &num, &label);
            box[i] = node(num, label);
        }
        max = 0;
        go(0, 0, 0);
        printf("Case #%d: %lld\n", ++cases, max);
    }

    return 0;
}
