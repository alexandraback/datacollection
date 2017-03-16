//
//  main.cpp
//  abcd
//
//  Created by cyanic MayDay on 12-4-14.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <math.h>

char map['z' + 1];




int main(int argc, const char * argv[])
{
    ifstream is("/Users/ccyanic/Downloads/A-small-attempt0.in.txt");
    ofstream os("/Users/ccyanic/Downloads/A.txt");
    string str;
    map['a']='y';
    map['b']='h';
    map['c']='e';
    map['d']='s';
    map['e']='o';
    map['f']='c';
    map['g']='v';
    map['h']='x';
    map['i']='d';
    map['j']='u';
    map['k']='i';
    map['l']='g';
    map['m']='l';
    map['n']='b';
    map['o']='k';
    map['p']='r';
    map['q']='z';
    map['r']='t';
    map['s']='n';
    map['t']='w';
    map['u']='j';
    map['v']='p';
    map['w']='f';
    map['x']='m';
    map['y']='a';
    map['z']='q';
    map[' ']=' ';
    
    int n = 0;
    is >> n;
    getline(is, str);
    for (int i = 0; i < n; i ++) {
        getline(is, str);
        for (int j = 0; j < str.size(); j ++) {
            str[j] = map[str[j]];
        }
        os << "Case #"<< i + 1 <<": "<< str << endl;
    }
    
    return 0;
}

