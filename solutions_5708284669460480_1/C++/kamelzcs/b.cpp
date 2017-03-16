/*
 * a.cpp
 * Copyright (C) 2015 zhao <zhao@kamel-ThinkPad-X201>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <memory.h>
using namespace std;

int main() {

    //Create an input file stream
    //fstream in("B-small.in",ios::in);
    //fstream out("B-small.out", ios::out);
    fstream in("B-large.in",ios::in);
    fstream out("B-large.out", ios::out);
    int T;
    in>>T;
    for(int index = 1; index <= T; ++index){
        int K, L, S;
        string keys, target;
        double ans = 0.0;
        int occured[30];
        int suffix_L = 0;
        memset(occured, 0, sizeof(occured));
        in>>K>>L>>S;
        in>>keys>>target;
        for(int i = 0; i < K; ++i){
            occured[keys[i] - 'A']++;
        }
        for(int i = 1; i < L; ++i){
            if(target.substr(i) == target.substr(0, L - i)){
                suffix_L = L - i;
                break;
            }
        }
        //cout<<suffix_L<<endl;
        double total = 0.0;
        for(int i = S; i >= 1; --i){
            if(i * L - (i - 1) * suffix_L <= S){
                total = i * 1.0;
                break;
            }
        }
        //cout<<total<<endl;
        double single = 1.0;
        bool invalid = false;
        for(int i = 0; i < L; ++i){
            int d = target[i] - 'A';
            if(!occured[d]){
                //cout<<target<<" "<<target[i]<<endl;
                invalid = true;
                break;
            }
            single *= 1.0 * occured[d] / K;
        }
        if(invalid){
            ans = 0.0;
        }
        else{
            ans = total - single * (S - L + 1);
        }
        string temp = "Case #";
        out.precision(10);
        out << temp.c_str()<<index<<": "<<fixed<<ans<<endl;
    }
	//Close the file stream
	in.close();
        out.close();
	return 0;
}


