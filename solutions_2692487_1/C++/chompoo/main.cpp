//
//  main.cpp
//  A
//
//  Created by Panida Nimnual on 5/4/56 BE.
//  Copyright (c) 2556 Panida Nimnual. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
#include <vector>

using namespace std;

vector<int> q;
int in[101];
int compare(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int main(){
    int t,a,n;
    int i,j;
    int count;
    int count1;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        q.clear();
        count=0;
        scanf("%d %d",&a,&n);
        for (j=0; j<n; j++) {
            scanf("%d",&in[j]);
        }
        qsort(in,n, sizeof(int), compare);
        j=0;
        while(j<n){
            if(a>in[j]){
                a+=in[j];
                j++;
            }
            else if(j<n-1&&a>1){
                count1=0;
                int ta=a;
                while(ta<=in[j]){
                    ta+=ta-1;
                    count1++;
                }
                q.push_back(count+n-j);
                a=ta;
                count+=count1;
            }
            else break;
        }
        count+=n-j;
        q.push_back(count);
        int min=q[0];
        for (j=0; j<q.size(); j++) {
            if(min>q[j])    min=q[j];
        }
        printf("Case #%d: %d\n",i+1,min);
    }
    return 0;
}
