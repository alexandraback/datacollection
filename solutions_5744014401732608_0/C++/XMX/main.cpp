//
//  main.cpp
//  slides
//
//  Created by MichelleShieh on 5/8/16.
//  Copyright (c) 2016 MichelleShieh. All rights reserved.
//

#include <iostream>
using namespace std;

long long pow2(int x) {
    long long ans=1;
    for (int i=0;i<x;i++) {
        ans*=2;
    }
    return ans;
}

void dToB(long long m,int mm[],int &cnt) {
    cnt=0;
    while (m!=0) {
        if (m%2 == 1) {
            mm[cnt]=1;
        }
        else mm[cnt]=0;
        m/=2;
        cnt++;
    }
    /*
    for (int i=0;i<cnt;i++) {
        cout<<mm[i];
    }
     */
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    int b;
    unsigned long long m;
    
    for (int i=1;i<=t;i++) {
        int cnt;
        int mm[20];
        int ans[51][51];

        cin>>b>>m;
        for (int j=0;j<b;j++) {
            for (int k=0;k<b;k++) {
                ans[j][k]=0;
            }
        }
        cout<<"Case #"<<i<<": ";
        if (m>pow2(b-2)) {
            cout<<"IMPOSSIBLE"<<endl;
        }
        else if(m==pow2(b-2)) {
            //cout<<"inside"<<endl;
            cout<<"POSSIBLE"<<endl;
            for (int j=0;j<b-1;j++) {
                for (int k=j+1;k<b;k++) {
                    ans[j][k]=1;
                }
            }
            for (int j=0;j<b;j++) {
                for (int k=0;k<b;k++) {
                    cout<<ans[j][k];
                }
                cout<<endl;
            }
        }
        else {
            dToB(m,mm,cnt);
            //0->all except itself and the last
            for (int j=1;j<b-1;j++) {
                ans[0][j]=1;
            }
            ans[0][b-1]=mm[0];
            //1->b-2, j+1->b-2 1, last:see mm[j-1]
                for (int j=1;j<b-1;j++) {
                    for (int k=j+1;k<=b-2;k++) {
                        ans[j][k]=1;
                    }
                    if (j!=1 && j-1<cnt) {
                        ans[j][b-1]=mm[j-1];
                    }
                }
            //b-1 all 0
        
            cout<<"POSSIBLE"<<endl;
            for (int j=0;j<b;j++) {
                for (int k=0;k<b;k++) {
                    cout<<ans[j][k];
                }
                cout<<endl;
            }
        }
    }
    return 0;
}

