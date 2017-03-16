//  jama
//
//  Created by Serhiy Semenyuk on 14.04.12.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <math.h>
using namespace std;

/*
 ejp mysljylc kd kxveddknmc re jsicpdrysi
 our language is impossible to understand
 
 rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
 there are twenty six factorial possibilities
 
 de kr kd eoya kw aej tysr re ujdr lkgc jv
 so it is okay if you want to just give up
*/ 

map<char, char> codes;

void init_codes()
{
    codes[' '] = ' ';
    codes['a'] = 'y';
    codes['b'] = 'h';
    codes['c'] = 'e';
    codes['d'] = 's';
    codes['e'] = 'o';
    codes['f'] = 'c';
    codes['g'] = 'v';
    codes['h'] = 'x';
    codes['i'] = 'd';
    codes['j'] = 'u';
    codes['k'] = 'i';
    codes['l'] = 'g';
    codes['m'] = 'l';
    codes['n'] = 'b';
    codes['o'] = 'k';
    codes['p'] = 'r';
    codes['q'] = 'z';
    codes['r'] = 't';
    codes['s'] = 'n';
    codes['t'] = 'w';
    codes['u'] = 'j';
    codes['v'] = 'p';
    codes['w'] = 'f';
    codes['x'] = 'm';
    codes['y'] = 'a';
    codes['z'] = 'q';
}

char encode(char in)
{
    return codes[in];
}

int main (int argc, const char * argv[])
{
    init_codes();
    vector<string> lines;
    ifstream dat ("test.in");
    if (dat.is_open())
    {
        string line;
        while (dat.good())
        {
            getline (dat, line);
            if (line.empty())
                continue;
            lines.push_back(line);
        }
        dat.close();
    }  
    lines.erase(lines.begin()); //drop firts line with number
    cout << "Loaded " << lines.size() << " lines" << endl;
    
    for (int i = 0, ci = lines.size(); i < ci; ++i)
        for(int j = 0, cj = lines[i].size(); j < cj; ++j)
        {
            lines[i][j] = encode(lines[i][j]);
        }
    
    ofstream res("test.out");
    for (int i = 0, c = lines.size(); i < c; ++i)
        res << "Case #" << i + 1 << ": " << lines[i] << endl;
    res.close();
    
    return 0;
}

