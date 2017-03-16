//
//  main.cpp
//  CodeJamQ1
//
//  Created by Ha Young Park on 4/13/12.
//  Copyright (c) 2012 UCLA. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main ()
{
    ifstream fin("A-small-attempt1.in", istream::in);
    ofstream fout("A-small-attempt1.out", ofstream::out);

    char googlerese[26];

    googlerese[(int)'y'-97] = 'a';
    googlerese[(int)'n'-97] = 'b';
    googlerese[(int)'f'-97] = 'c';
    googlerese[(int)'i'-97] = 'd';
    googlerese[(int)'c'-97] = 'e';
    googlerese[(int)'w'-97] = 'f';
    googlerese[(int)'l'-97] = 'g';
    googlerese[(int)'b'-97] = 'h';
    googlerese[(int)'k'-97] = 'i';
    googlerese[(int)'u'-97] = 'j';
    googlerese[(int)'o'-97] = 'k';
    googlerese[(int)'m'-97] = 'l';
    googlerese[(int)'x'-97] = 'm';
    googlerese[(int)'s'-97] = 'n';
    googlerese[(int)'e'-97] = 'o';
    googlerese[(int)'v'-97] = 'p';
    googlerese[(int)'z'-97] = 'q';
    googlerese[(int)'p'-97] = 'r';
    googlerese[(int)'d'-97] = 's';
    googlerese[(int)'r'-97] = 't';
    googlerese[(int)'j'-97] = 'u';
    googlerese[(int)'g'-97] = 'v';
    googlerese[(int)'t'-97] = 'w';
    googlerese[(int)'h'-97] = 'x';
    googlerese[(int)'a'-97] = 'y';
    googlerese[(int)'q'-97] = 'z';
    
    int N;
    fin >> N;

    fin.ignore(INT_MAX, '\n');
    for(int i = 0; i < N; i++){
        string s;
        getline(fin, s);
        
        for(int j = 0; j < s.length(); j++) {
            if(s[j] != ' ')
                s[j] = googlerese[(int)s[j] - 97];
        }
        fout << "Case #" << i + 1 << ": " << s << endl;
    }
    fin.close();
    return 0;
}