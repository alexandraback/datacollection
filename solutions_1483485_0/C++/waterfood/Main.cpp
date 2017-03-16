#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <deque>
#include <iomanip>
using namespace std;

int main()
{
    ifstream in("A-small-attempt1.in");
    ofstream out("A-small-attempt1.out");

    vector<string> sampleIn, sampleOut;
    sampleIn.push_back("ejp mysljylc kd kxveddknmc re jsicpdrysi");
    sampleIn.push_back("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
    sampleIn.push_back("de kr kd eoya kw aej tysr re ujdr lkgc jv");
    sampleOut.push_back("our language is impossible to understand");
    sampleOut.push_back("there are twenty six factorial possibilities");
    sampleOut.push_back("so it is okay if you want to just give up");
    char mapping[26];
    for (int i = 0; i < 26; i++)
    {
        mapping[i] = '-';
    }
    mapping['y'-'a'] = 'a';
    mapping['e'-'a'] = 'o';
    mapping['q'-'a'] = 'z';

    for (int i = 0; i < sampleIn.size(); i++)
    {
        for (int j = 0; j < sampleIn[i].length(); j++)
        {
            char ci = sampleIn[i][j];
            char co = sampleOut[i][j];
            if (ci == ' ')
            {
                continue;
            }
            else if (mapping[ci-'a'] != '-')
            {
                if (mapping[ci-'a'] != co)
                {
                    throw new exception();
                }
            }
            else
            {
                mapping[ci-'a'] = co;
            }
        }
    }
    mapping['z'-'a'] = 'q';

    int T;
    in >> T;
    char c;
    in.readsome(&c, 1);
    for (int x = 0; x < T; x++)
    {
        out << "Case #" << (x+1) << ": ";
        while (1)
        {
            in.readsome(&c, 1);
            if (c == '\n')
            {
                break;
            }
            else
            {
                if (c != ' ')
                {
                    out << mapping[c - 'a'];
                }
                else
                {
                    out << ' ';
                }
            }
        }
        out << endl;
    }
    in.close();
    out.close();
    return 0;
}
