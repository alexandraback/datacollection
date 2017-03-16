// CodeJam
// Author:  Yotam Medini  yotam.medini@gmail.com -- Created: 2013/April/20

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <utility>

using namespace std;

class Costs
{
 public:
    Costs(double C=0, double F=0, double X=0, int n=0):
        tn(X / (n*F + 2.)),
        cnext(C / (n*F + 2)),
        tnext(cnext + X / ((n+1)*F + 2.))
    {}
    double tn;
    double cnext;
    double tnext;
};

class Problem
{
 public:
    Problem(istream& fi);
    void solve();
    void print_solution(ostream&);
 private:
    double C, F, X;
    double t;
};

Problem::Problem(istream& fi)
{
    fi >> C >> F >> X;
    // cerr << "C="<<C << ", F="<<X << ", X="<<X << "\n";
}

void Problem::solve()
{
    int n = 0;
    
    t = 0;
    Costs costs(C, F, X, n);
    while (costs.tnext < costs.tn)
    {
        t += costs.cnext;
        ++n;
        costs = Costs(C, F, X, n);
    }
    t += costs.tn;
}

void Problem::print_solution(ostream &os)
{
    // os << " " << setprecision(6) << t;
    char b[0x20];
    sprintf(b, "%.7f", t);
    os << " " << b;
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

    unsigned n_cases;
    *pfi >> n_cases;

    ostream &fout = *pfo;
    for (unsigned ci = 0; ci < n_cases; ci++)
    {
        Problem problem(*pfi);
        // cerr << "Case ci="<<ci << " (ci+1)="<<ci+1 << "\n";
        problem.solve();
        fout << "Case #"<< ci+1 << ":";
        problem.print_solution(fout);
        fout << "\n";
        fout.flush();
        
    }
    
    if (pfi != &cin) { delete pfi; }
    if (pfo != &cout) { delete pfo; }
    return 0;
}

