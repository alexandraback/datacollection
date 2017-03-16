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
    ifstream infile("B-large.in");
    ofstream outfile("B-large.out");

    int T, result;
    infile>>T;
    string str;
    bool flag;
    for(int it=1;it<=T;it++){
        infile>>str;
        flag = true;
        result = 0;
        for(int i=str.length()-1;i>=0;i--){
            if(flag){
                if(str[i]=='-'){
                    result++;
                    flag = false;
                }
            }
            else{
                if(str[i]=='+'){
                    result++;
                    flag = true;
                }
            }
        }
        outfile<<"case #"<<it<<": "<<result<<endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
