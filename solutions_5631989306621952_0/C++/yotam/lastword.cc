// CodeJam
// Author:  Yotam Medini  yotam.medini@gmail.com -- Created: 2013/April/20

#include <iostream>
#include <fstream>
#include <string>

#include <cstdlib>
#include <cstring>

using namespace std;


static unsigned dbg_flags;

class Lastword
{
 public:
    Lastword(istream& fi);
    void solve();
    void print_solution(ostream&);
 private:
    string S;
    string solution;
};

Lastword::Lastword(istream& fi)
{
    fi >> S;
}

void Lastword::solve()
{
    const char *cS = S.c_str();
    const unsigned n = strlen(cS);
    solution = cS[0] + string("");
    for (unsigned i = 1; i < n; ++i)
    {
        char cleft = solution[0];
        char cnext = cS[i];
        if (cnext > cleft)
        {
            solution = cnext + solution;
        }
        else if (cleft > cnext)
        {
            solution = solution + cnext;
        }
        else // == 
        {
            string s1 = cnext + solution;
            string s2 = solution + cnext;
            solution = (s1 > s2 ? s1 : s2);
        }
    }
}

void Lastword::print_solution(ostream &fo)
{
    fo << " " << solution;
}

int main(int argc, char ** argv)
{
    const string dash("-");

    istream *pfi = (argc < 2 || (string(argv[1]) == dash))
         ? &cin
         : new ifstream(argv[1]);
    ostream *pfo = (argc < 3 || (string(argv[2]) == dash))
         ? &cout
         : new ofstream(argv[2]);

    if ((!pfi) || (!pfo) || pfi->fail() || pfo->fail())
    {
        cerr << "Open file error\n";
        exit(1);
    }

    if (argc > 3) { dbg_flags = strtoul(argv[3], 0, 0); }
    // bool large = (argc > 4) && !strcmp(argv[4], "-large");

    unsigned n_cases;
    *pfi >> n_cases;

    ostream &fout = *pfo;
    for (unsigned ci = 0; ci < n_cases; ci++)
    {
        Lastword lastword(*pfi);
        // cerr << "Case ci="<<ci << " (ci+1)="<<ci+1 << "\n";
        lastword.solve();
        fout << "Case #"<< ci+1 << ":";
        lastword.print_solution(fout);
        fout << "\n";
        fout.flush();
        
    }
    
    if (pfi != &cin) { delete pfi; }
    if (pfo != &cout) { delete pfo; }
    return 0;
}

