/*
 * a.cpp
 * Copyright (C) 2015 zhao <zhao@kamel-ThinkPad-X201>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

typedef long long LL;

int main() {

    //Create an input file stream
    fstream in("A-small.in",ios::in);
    fstream out("A-small.out", ios::out);
    //fstream in("A-large.in",ios::in);
    //fstream out("A-large.out", ios::out);
    int T;
    in>>T;
    for(int index = 1; index <= T; ++index){
        int r,c,w,ans;
        in>>r>>c>>w;
        if(c % w){
            ans = c / w + w;
        }
        else{
            ans = c / w + w - 1;
        }
        string temp = "Case #";
        out << temp.c_str()<<index<<": "<<ans<<endl;
    }
	//Close the file stream
	in.close();
        out.close();
	return 0;
}


