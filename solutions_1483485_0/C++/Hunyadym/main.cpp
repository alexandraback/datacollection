#include <iostream>
#include <fstream>

using namespace std;

char keres(char c)
{
    string s = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv yeqz" ;
    string q = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up aozq" ;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == c)
        {
            return q[i] ;
        }
    }
    return '*' ;
}

int main()
{
    ifstream bef("a.in") ;
    ofstream kif("a.out") ;
    int db ;
    bef >> db >> ws ;

    for (int testcase = 1; testcase <= db; testcase++)
    {
        string sor ;
        getline(bef, sor) ;
        for (int i = 0; i < sor.length(); ++i)
        {
            sor[i] = keres(sor[i]) ;
        }
        kif << "Case #" << testcase << ": " << sor << endl ;
    }

}
