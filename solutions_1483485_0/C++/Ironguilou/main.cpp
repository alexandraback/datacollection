#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int main()
{
    map<char, char> dictionary ;

    string code = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv" ;
    string decode = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up" ;

    for (int i = code.size() - 1 ; i >= 0 ; i--)
    {
        dictionary.insert(make_pair(code[i], decode[i])) ;
    }
    dictionary.insert(make_pair('z', 'q')) ;
    dictionary.insert(make_pair('q', 'z')) ;

    cerr << "Nombre de lettres = " << dictionary.size() << endl ;

    for (map<char,char>::iterator it = dictionary.begin() ; it != dictionary.end() ; it++)
    {
        cerr << it -> first << " -> " << it -> second << endl ;
    }

    int nCases ;
    cin >> nCases ;

    string s ;
    string line ;

    getline(cin, s) ;
    char c ;
    for (int iCase = 0 ; iCase < nCases ; iCase++)
    {
        // reading input file
        getline(cin, line) ;
        istringstream stream(line) ;

        // writing output file
        cout << "Case #" << iCase + 1 << ": " ;

        while (stream.get(c))
        {
            cout << dictionary[c] ;
        }

        cout << endl ;
    }


    return 0;
}
