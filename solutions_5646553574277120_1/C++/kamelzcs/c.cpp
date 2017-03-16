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
#include<set>
using namespace std;

typedef long long LL;

int main() {

    //Create an input file stream
    //fstream in("C-small.in",ios::in);
    //fstream out("C-small.out", ios::out);
    fstream in("C-large.in",ios::in);
    fstream out("C-large.out", ios::out);
    int T;
    in>>T;
    for(int index = 1; index <= T; ++index){
        LL C, D, V, ans = 0;
        in>>C>>D>>V;
        set<int> occured;
        for(int i = 0; i < D; ++i){
            int d;
            in>>d;
            occured.insert(d);
        }
        LL total = 0;
        for(LL i = 1; i <= V;){
            if(i > total){
                if(occured.find(i) == occured.end()){
                    ans++;
                    total += C * i;
                }
            }
            if(occured.find(i) != occured.end()){
                total += C * i;
            }
            i = total + 1;
        }
        string temp = "Case #";
        out << temp.c_str()<<index<<": "<<ans<<endl;
    }
	//Close the file stream
	in.close();
        out.close();
	return 0;
}


