#include <QtCore/QCoreApplication>
#include <cmath>
#include <iostream>

#define ABS(x) ((x<0) ? (-(x)) : (x))
using namespace std;

int main(int argc, char *argv[])
{
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    //string tr =       "ynficwlbkuomxsevzpdrjgthaq";
    string tr =       "yhesocvxduiglbkrztnwjpfmaq";
    int cases;
    cin >> cases;
    for(int i = 0; i<cases;++i)
    {
        cout << "Case #" << i+1 << ": ";
        char c;
        cin >> c;
        while(c != '\n') {
            if(c == ' ') cout << ' ';
            else {
                //cout << " c:" << c << " tr:";
                cout << tr.at(c-'a');
                //cout << ' ' << c-'a' << ' ';
            }
            cin >> noskipws >> c;
        }
        cout << endl;
    }
    return 0;
}
