// CodeJam
// Author:  Yotam Medini  yotam.medini@gmail.com -- Created: 2013/April/20

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <utility>

#include <cstdlib>

using namespace std;

typedef unsigned long ul_t;
typedef vector<ul_t> vul_t;
typedef vector<vul_t> vvul_t;
typedef set<ul_t> setul_t;

static unsigned dbg_flags;

class Rank
{
 public:
    Rank(istream& fi);
    void solve();
    void print_solution(ostream&);
 private:
    unsigned N;
    vvul_t reports;
    vul_t solution;
};

Rank::Rank(istream& fi)
{
    fi >> N;
    for (unsigned r = 0, nr = 2*N - 1; r < nr; ++r)
    {
        vul_t report;
        for (unsigned i = 0; i < N; ++i)
        {
            unsigned h;
            fi >> h;
            report.push_back(h);
        }
        reports.push_back(report);
    }
}

void Rank::solve()
{
    setul_t heights;
    for (auto ri = reports.begin(); ri != reports.end(); ++ri)
    {
        const vul_t &report = *ri;
        for (auto hi = report.begin(); hi != report.end(); ++hi)
        {
            unsigned h = *hi;
            auto w = heights.find(h);
            if (w == heights.end())
            {
                heights.insert(w, h);
            }
            else
            {
                heights.erase(w);
            }
        }
    }
    if (heights.size() != N)
    {
        cerr << "#(heights)=" << heights.size() << " != N = " << N << "\n";
        exit(1);
    }
    for (auto hi = heights.begin(); hi != heights.end(); ++hi)
    {
        solution.push_back(*hi);
    }
}

void Rank::print_solution(ostream &fo)
{
    for (auto hi = solution.begin(); hi != solution.end(); ++hi)
    {
        fo << " " << *hi;
    }
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
        Rank rank(*pfi);
        // cerr << "Case ci="<<ci << " (ci+1)="<<ci+1 << "\n";
        rank.solve();
        fout << "Case #"<< ci+1 << ":";
        rank.print_solution(fout);
        fout << "\n";
        fout.flush();
        
    }
    
    if (pfi != &cin) { delete pfi; }
    if (pfo != &cout) { delete pfo; }
    return 0;
}

