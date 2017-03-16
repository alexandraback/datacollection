//
//  main.cpp
//  GCJ
//
//  Created by 陶源 on 4/9/16.
//  Copyright © 2016 daisynowhere. All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int map[100][100];

int main() {
    int T;
    freopen("/Users/daisy/Documents/GCJ/B-small-attempt0.in","r",stdin);
    freopen("/Users/daisy/Documents/GCJ/GCJ/2.out","w",stdout);
    cin >> T;
    int cnt;
    for (cnt=1;cnt<=T;cnt++){
        int B;
        long long m;
        cin>>B>>m;
        for (int i=0;i<B;i++){
            for (int j=0;j<B;j++){
                map[i][j]=0;
            }
        }
        cout<<"Case #"<<cnt<<": ";
        long long now=1;
        if (now==m)
            m=0;
        map[0][B-1]=1;
        for (int i=1;i<B-1;i++){
            if (m==0)
                break;
            now=now*2;
            if (now<=m){
                map[0][i]=1;
                map[i][B-1]=1;
                for (int j=1;j<i;j++){
                    map[i][j]=1;
                }
            }else{
                now=now/2;
                m-=now;
                if (m>0)
                    map[0][i]=1;
                int j=0;
                while (j<i-1){
                    if (m & (1<<j))
                        map[i][j+1]=1;
                    j++;
                }
                m=0;
            }
        }
        if (now==m){
            m=0;
        }
        if (m==0){
            cout<<"POSSIBLE"<<endl;
            for (int i=0;i<B;i++){
                for (int j=0;j<B;j++){
                    cout<<map[i][j];
                }
                cout<<endl;
            }
        }else{
            cout<<"IMPOSSIBLE"<<endl;
        }
    }
    return 0;
}
