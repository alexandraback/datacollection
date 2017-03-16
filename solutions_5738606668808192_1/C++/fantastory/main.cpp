#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <stdint.h>
#include <assert.h>

using namespace std;

string prepath = "..\\2016-C\\";
//string testin = "test";
//string testin = "C-small-attempt0";
//string testin = "C-small-attempt1";
string testin = "C-large";


int work();
int test();

int main()
{
    test();
    work();
    return 0;
}

struct Jamcoin {
    vector<uint8_t> m_c;

    Jamcoin(int n) {
        m_c.resize(n, 0);
    }

    uint64_t toNumber(int base) const {
        uint64_t ret = 0;
        for (int i = m_c.size()-1; i >= 0; --i) {
            ret *= base;
            ret += m_c[i];
        }
        return ret;
    }

    void plus2() {
        for (unsigned i = 1; i < m_c.size(); ++i) {
            m_c[i] = !m_c[i];
            if (m_c[i]) {
                break;
            }
        }
    }

    std::string toString() const {
        string ret;
        ret.reserve(m_c.size());
        for (int i = m_c.size()-1; i >= 0; --i) {
            if (m_c[i]) ret += '1';
            else ret += '0';
        }
        return ret;
    }
};

int test() {
    Jamcoin j1001(4);
    j1001.m_c[0] = 1;
    j1001.m_c[3] = 1;

    if (j1001.toNumber(10) != 1001) {
        printf("%I64u != 1001\n", j1001.toNumber(10));
    }

    if (j1001.toNumber(2) != 9) {
        printf("%I64u != 1001\n", j1001.toNumber(10));
    }

    if (j1001.toString() != "1001") {
        printf("%s != 1001\n", j1001.toString().c_str());
    }

    j1001.plus2();
    if (j1001.toString() != "1011") {
        printf("%s != 1011\n", j1001.toString().c_str());
    }

    j1001.plus2();
    if (j1001.toString() != "1101") {
        printf("%s != 1101\n", j1001.toString().c_str());
    }

    j1001.plus2();
    if (j1001.toString() != "1111") {
        printf("%s != 1111\n", j1001.toString().c_str());
    }

    printf("tests done\n");
    return 0;
}

int solve(FILE *fin, FILE *fout) {
    uint64_t n, j;

    fscanf(fin, "%I64u %I64u\n", &n, &j);
    printf("%I64u %I64u\n", n, j);

    Jamcoin halfbase(n/2);
    halfbase.m_c[0] = 1;
    halfbase.m_c[n/2-1] = 1;
    printf("halfbase %s\n", halfbase.toString().c_str());

    //they all are dividable by this:
    Jamcoin proof(n/2+1);
    proof.m_c[0] = 1;
    proof.m_c[n/2] = 1;
    printf("proof %s\n", proof.toString().c_str());

    for (uint64_t i = 0; i < j; ++i) {
        string jamcoin = halfbase.toString();
        jamcoin += jamcoin;
        fprintf(fout, "\n%s" , jamcoin.c_str());
        printf("\n%s" , jamcoin.c_str());
        for (int base = 2; base < 11; ++base) {
            fprintf(fout, " %I64u" , proof.toNumber(base));
            printf(" %I64u" , proof.toNumber(base));
        }
        halfbase.plus2();
    }

    return 0;
}

int work () {
    string path = prepath + testin + "_out.in";
    FILE *fout = fopen(path.c_str(), "w");
    if (fout == NULL) {
        printf("can not open out\n");
        exit(0);
    }
    fflush(fout);

    path = prepath + testin + ".in";
    FILE *fin = fopen(path.c_str(), "r");
    if (fin == NULL) {
        printf("can not open in\n");
        exit(0);
    }

    int problemc;
    int ret = fscanf(fin, "%d\n", &problemc);
    if (ret != 1) {
        printf("problemc\n");
        exit(0);
    }
    printf("problemc %d\n", problemc);

    for (int n = 0; n < problemc; ++n) {
        fprintf(fout, "Case #%d:", n+1);
        printf("Case #%d:", n+1);

        solve(fin, fout);
    }

    return 0;
}

