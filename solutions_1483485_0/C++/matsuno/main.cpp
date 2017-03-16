#include <iostream>
#include <map>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <string>

using namespace std;

int main()
{
    map<char, char> gton;
    map<char, char>::iterator gton_itr;
    /*vector<string> gg;
    vector<string> nm;
    gg.push_back("ejp mysljylc kd kxveddknmc re jsicpdrysi");
    gg.push_back("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
    gg.push_back("de kr kd eoya kw aej tysr re ujdr lkgc jv");
    nm.push_back("our language is impossible to understand");
    nm.push_back("there are twenty six factorial possibilities");
    nm.push_back("so it is okay if you want to just give up");
    size_t i;
    for (i=0;i<gg.size();++i) {
        const string &gstr = gg[i];
        const string &nstr = nm[i];
        size_t j;
        for(j=0;j<gstr.length();++j) {
            if(islower(gstr[j])) {
                gton[gstr[j]] = nstr[j];
            }
        }
    }
    cout << gton.size() << endl;
    for (gton_itr=gton.begin();gton_itr!=gton.end();++gton_itr) {
        cout << "gton['" << gton_itr->first << "']"
         << " = '" << gton_itr->second << "';"<< endl;
    }*/
    gton['a'] = 'y';
    gton['b'] = 'h';
    gton['c'] = 'e';
    gton['d'] = 's';
    gton['e'] = 'o';
    gton['f'] = 'c';
    gton['g'] = 'v';
    gton['h'] = 'x';
    gton['i'] = 'd';
    gton['j'] = 'u';
    gton['k'] = 'i';
    gton['l'] = 'g';
    gton['m'] = 'l';
    gton['n'] = 'b';
    gton['o'] = 'k';
    gton['p'] = 'r';
    gton['q'] = 'z';
    gton['r'] = 't';
    gton['s'] = 'n';
    gton['t'] = 'w';
    gton['u'] = 'j';
    gton['v'] = 'p';
    gton['w'] = 'f';
    gton['x'] = 'm';
    gton['y'] = 'a';
    gton['z'] = 'q';
    int t, T;
    cin >> T;
    getchar();
    for (t=0;t<T;++t) {
        cout << "Case #" << t+1 << ": ";
        char c;
        while ((c=getchar())!='\n') {
            if(islower(c)) {
                cout << gton[c];
            }
            else {
                cout << c;
            }
        }
        cout << endl;
    }
    return 0;
}
