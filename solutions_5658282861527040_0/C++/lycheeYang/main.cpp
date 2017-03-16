//
//  main.cpp
//  ProblemA
//
//  Created by Lydia Yang on 14-5-3.
//  Copyright (c) 2014年 杨荔雅5110309443. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in("/Users/apple/Desktop/in.txt");
    ofstream out("/Users/apple/Desktop/out.txt");

    int T;
   // int N;
    int A;
    int B;
    int K;
   // string str[100];
    int ans;
    int tmp;
    
    in >> T;
    for (int i = 0; i < T; i++) {
        in >> A;
        in >> B;
        in >> K;
        ans = 0;
        for (int j = 0; j < A; j++) {
            for (int k = 0; k < B; k++) {
                tmp = j&k;
                if (tmp < K) {
                    ans++;
                }
            }
        }
        out << "Case #"<<i+1<<": "<<ans<<endl;
        
    }
   
    
    in.close();
    out.close();
    return 0;
}

