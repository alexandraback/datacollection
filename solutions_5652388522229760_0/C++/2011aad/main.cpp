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
    ifstream infile("A-small-attempt0.in");
    ofstream outfile("A-small-attempt0.out");

    int N, num, counter, tmp, result = 0;
    infile>>N;
    int digits[10];

    for(int it=1;it<=N;it++){
        infile>>num;
        if(num==0){
            outfile<<"case #"<<it<<": INSOMNIA"<<endl;
            continue;
        }

        counter = 0;
        for(int i=0;i<10;i++) digits[i] = 0;
        for(int i=1;i<=100;i++){
            result = i*num;
            tmp = result;
            while(tmp>0){
                if(digits[tmp%10]==0){
                    counter++;
                    digits[tmp%10] = 1;
                }
                tmp /= 10;
            }
            if(counter==10) break;
        }
        if(counter==10) outfile<<"case #"<<it<<": "<<result<<endl;
        else outfile<<"case #"<<it<<": INSOMNIA"<<endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
