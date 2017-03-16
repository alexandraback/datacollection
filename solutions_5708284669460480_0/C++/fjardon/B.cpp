#include "common.hpp"
using namespace std;

typedef long double ldouble;


struct small_monkey {
    ullong K;
    ullong L;
    ullong S;
    string KEYS;
    string T;
    ullong Nwords;
    ullong Nbananas;
    ullong Ntries;
    string word;
    ldouble pt;

    void evaluate()
    {
        Ntries ++;
        ullong nb = 0;
        auto idx = word.find(T);
        while(string::npos != idx) {
            Nwords++;
            nb++;
            idx++;
            if(idx >= word.size())
                break;
            idx = word.find(T, idx);
        }
        Nbananas = max(Nbananas, nb);
    }

    ldouble result() {
        return (ldouble)Nbananas -
                ((ldouble)Nwords / (ldouble)Ntries);
    }

    void generate() {
        if(word.size() == S) {
            evaluate();
        }
        else {
            for(unsigned k=0; k<KEYS.size(); ++k) {
                word.push_back(KEYS[k]);
                generate();
                word.pop_back();
            }
        }
    }

    void setup(std::istream& in) {
        string line1, line2, line3;
        getline(in, line1);
        getline(in, line2);
        getline(in, line3);
        stringstream buf1(line1);
        stringstream buf2(line2);
        stringstream buf3(line3);
        buf1 >> K >> L >> S;
        buf2 >> KEYS;
        buf3 >> T;
        cerr << K << " " << L << " " << S <<endl;
        cerr << KEYS << "\n";
        cerr << T << endl;
        Nwords = 0;
        Nbananas = 0;
        Ntries = 0;
        pt = 0;
        word.clear();
    }
};


void codejam::solve_small(int testno, std::istream& in, std::ostream& out)
{
    small_monkey monkey;
    monkey.setup(in);
    monkey.generate();

    out << testcase(testno) << setprecision(20) << monkey.result() << endl;
}

void codejam::solve_large(int testno, std::istream& in, std::ostream& out)
{
    int K, L, S;
    string KEYS, T;
    in >> K >> L >> S >> KEYS >> T;
    string sKEYS;
    vector<long double> freqs;
    vector<int> KMAP(256);

    sort(begin(KEYS), end(KEYS));
    for(unsigned i=0; i<KEYS.size(); ++i) {
        auto c = KEYS[i];
        if(sKEYS.empty() || sKEYS.back() != c) {
            KMAP[(unsigned char)c] = i;
            sKEYS.push_back(c);
            freqs.push_back(0.0);
        }
        freqs.back() += 1.0;
    }
    auto s = accumulate(freqs, 0.0);
    for(auto& f : freqs)
        f = f/s;
    KEYS.swap(sKEYS);

    vector<int> target;
    long double pt = 1.0;
    for(auto c : T) {
        unsigned i = (unsigned)c;
        pt = pt * freqs[i];
        target.push_back(KMAP[i]);
    }

    solve_small(testno, in, out);
}

int main(int argc, char* argv[]) {
    codejam cj("B");
    return cj.run(argc, argv);
}
