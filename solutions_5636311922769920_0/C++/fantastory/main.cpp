#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <stdint.h>
#include <assert.h>

using namespace std;

string prepath = "..\\2016-D\\";
//string testin = "test";
string testin = "D-small-attempt0";
//string testin = "D-small-attempt1";
//string testin = "A-large-practice";


int work();
int test();

int main()
{
    test();
    work();
    return 0;
}

/// Path[0] tile number of the first transformation
typedef std::vector<uint64_t> Path;

struct TileTransformer {

    TileTransformer(uint64_t k, uint64_t c) :
        m_k(k),
        m_c(c)
    {}

    const uint64_t m_k; // home many tiles in block
    const uint64_t m_c; // hom many transformations, reCreations

    /// return path to get the sCheck transformed tile
    Path getPath(uint64_t sCheck) {
        if (sCheck >= pow(m_k, m_c)) {
            printf("scheck %I64u > %I64u ^ %I64u = %I64u out of band\n", sCheck, m_k, m_c, (uint64_t) pow(m_k, m_c));
            return Path();
        }

        Path path;

        for (uint64_t i = 0; i < m_c; ++i) {
            uint64_t lastOne = sCheck%m_k;
            sCheck /= m_k;
            path.push_back(lastOne);
        }

        std::reverse(path.begin(), path.end());
        return path;
    }

    uint64_t getScheck(const Path &path) {
        return getScheck(&path[0]);
    }

    uint64_t getScheck(const uint64_t* path) {
        uint64_t sCheck = 0;

        for (uint64_t i = 0; i < m_c; ++i) {
            const uint64_t &kCheck = path[i];

            sCheck *= m_k;
            sCheck += kCheck;
        }
        return sCheck;
    }
};

void check(TileTransformer &trans, const Path &path, uint64_t expected) {
    uint64_t s1 = trans.getScheck(path);

    for (uint64_t i = 0; i < trans.m_c; ++i) {
        printf("%I64u ", path[i]);
    }
    printf("\n");

    if (s1 != expected) {
        printf("%I64u = sCheck != expected %I64u\n", s1, expected);
    }

    uint64_t s2 = trans.getScheck(trans.getPath(s1));

    if (s1 != expected) {
        printf("s1 %I64u != s2 %I64u\n", s1, s2);
    }
}


int test() {

    //bad test should be k != c
    TileTransformer trans33(3, 3);

    check(trans33, {0ll,0ll,0ll},  0);
    check(trans33, {1ll,1ll,1ll}, 13);
    check(trans33, {2ll,2ll,2ll}, 26);
    check(trans33, {0ll,1ll,2ll},  5);
    check(trans33, {2ll,1ll,0ll}, 21);

    TileTransformer trans23(3, 2);
    check(trans23, Path({0ll,0ll}), 0);
    check(trans23, Path({0ll,1ll}), 1);
    check(trans23, Path({1ll,0ll}), 3);
    check(trans23, Path({1ll,1ll}), 4);
    check(trans23, Path({2ll,0ll}), 6);
    check(trans23, Path({2ll,1ll}), 7);

    printf("tests done\n");
    return 0;
}

int solve(FILE *fin, FILE *fout) {
    uint64_t k; // home many tiles in block
    uint64_t c; // hom many transformations, reCreations
    uint64_t s; // hom many students do check it

    int ret = fscanf(fin, "%I64u %I64u %I64u\n", &k, &c, &s);
    if (ret != 3) {
        printf("input");
        exit(0);
    }
    printf("k %I64u c %I64u s %I64u\n", k, c, s);

    //each check checks c tiles and we need to check k tiles
    if (s * c < k) {
        printf("we have %I64u studnets each checks %I64u but need to check %I64u\n", s, c, k);
        fprintf(fout, " IMPOSSIBLE\n");
        return 0;
    }

    TileTransformer transformer(k, c);

    /// it is the origin tile numbe we are currently checking
    uint64_t kCheck = 0; //start with 0 natural ordering transform it or output

    while (kCheck < k) {
        Path path;
        for (unsigned i = 0; i < c; ++i) {
            if (kCheck >= k) kCheck = k-1;
            path.push_back(kCheck);
            ++kCheck;
        }

        //the fractaled tile student is checking
        uint64_t sCheck = transformer.getScheck(path);

        //add plus 1 stupid human studnets does not know 0 number
        fprintf(fout, " %I64u", sCheck+1);
    }
    fprintf(fout, "\n");

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
    int ret = fscanf(fin, "%d", &problemc);
    if (ret != 1) {
        printf("problemc\n");
        exit(0);
    }
    printf("problemc %d\n", problemc);

    for (int n = 0; n < problemc; ++n) {
        fprintf(fout, "Case #%d:", n+1);

        solve(fin, fout);
    }

    return 0;
}

