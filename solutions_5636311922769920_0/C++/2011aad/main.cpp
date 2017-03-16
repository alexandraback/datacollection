//
//  main.cpp
//  Codejam2016QRoundA
//
//  Created by 张健 on 16/4/9.
//  Copyright © 2016年 张健. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    ifstream infile("D-small-attempt3.in");
    ofstream outfile("D-small-attempt3.out");

    int T, K, C, S;
    unsigned long long tests[100];
    infile>>T;

    for(int t=1;t<=T;t++){
        infile>>K>>C>>S;
        if(S*C<K){
            outfile<<"Case #"<<t<<": "<<"IMPOSSIBLE"<<endl;
            continue;
        }
        if(C>K) C = K;
        if(K%C==0) S = K/C;
        else S = K/C+1;

        for(int i=0;i<S;i++){
            tests[i] = i * C;
        }
        for(int it=1;it<C;it++){
            for(int i=0;i<S;i++){
                tests[i] *= K;
                if(it>=K) tests[i] += 0;
                else if(i*C+it>=K) tests[i] += K-1;
                else tests[i] += ((i*C) + it);
            }
        }

        outfile<<"Case #"<<t<<":";
        for(int i=0;i<S;i++) outfile<<' '<<tests[i]+1;
        outfile<<endl;
    }


    infile.close();
    outfile.close();

    return 0;
}
