//
//  main.cpp
//  enclosure
//
//  Created by Minghui Liu on 5/11/14.
//  Copyright (c) 2014 Minghui Liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

void solve(int i, int N, int M, int K){
    if(K==1){
        cout << "Case #"<<i+1<<": "<<1<<endl;
    }else if(K==2){
        cout << "Case #"<<i+1<<": "<<2<<endl;
    }else if(K==3){
        cout << "Case #"<<i+1<<": "<<3<<endl;
    }else if(K==4){
        cout << "Case #"<<i+1<<": "<<4<<endl;
    }
    else{
    if(N==1 || M==1){
        cout << "Case #"<<i+1<<": "<<2<<endl;
    }else{
        if(N==2||M==2){
           cout << "Case #"<<i+1<<": "<<4<<endl;
        }else{
         
            if(N*M-3<=K){
                cout<<"Case #"<<i+1<<": "<<2*M+2*N-4-(N*M-K)<<endl;
            }else{
                  // cout << "f"<<endl;
                int tmp = (sqrt(16+4*K)-4)/2;
                tmp=tmp+1;
                //cout << tmp<<endl;
                double z;
                int zInt;
                //tmp = tmp+1;
                if(tmp<=N-2){
                    z = (double)(pow(tmp,2)+K)/(double)(tmp+2.0);
                    //cout << z<<endl;
                    zInt = (pow(tmp,2)+K)/(tmp+2.0);
                    //cout<<zInt<<endl;
                    if(z>zInt){
                        zInt+=1;
                    }
                }else{
                    z = (double)(pow(N-2,2)+K)/(double)N;
                    zInt = (pow(N-2,2)+K)/N;
                    if(z>zInt){
                        zInt +=1;
                    }
                }
                cout << "Case #"<<i+1<<": "<<2*zInt<<endl;
            }
        }
    }
}
}


int main(int argc, const char * argv[])
{
    freopen("/Users/minghui/Documents/C++/C-small-attempt0.in.txt", "r", stdin);
    freopen("/Users/minghui/Documents/C++/C-small-attempt0.out.txt", "w", stdout);
    int T;
    cin>>T;
    int i;
    for(i=0;i<T;i++){
        int N,M,K;
        cin >>  N >> M >> K;
        solve(i,N,M,K);
    }
    return 0;
}

