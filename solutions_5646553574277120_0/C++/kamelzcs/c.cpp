/*
 * c.cpp
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
    fstream in("C-small.in",ios::in);
    fstream out("C-small.out", ios::out);
    //fstream in("B-large.in",ios::in);
    //fstream out("B-large.out", ios::out);
    int T;
    in>>T;
    for(int index = 1; index <= T; ++index){
        int C, D, V, ans = 0;
        in>>C>>D>>V;
        int occured[1000];
        memset(occured, 0, sizeof(occured));
        for(int i = 0; i < D; ++i){
            int d;
            in>>d;
            occured[d] = 1;
        }
        int total = 0;
        for(int i = 1; i <= V; ++i){
            if(i > total){
                if(!occured[i]){
                    ans++;
                    total += i;
                }
            }
            if(occured[i]){
                total += i;
            }
        }
        string temp = "Case #";
        out << temp.c_str()<<index<<": "<<ans<<endl;
    }
	//Close the file stream
	in.close();
        out.close();
	return 0;
}


