#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

long long X, L;
string line;
int data[10005];

// i - 2, j - 3, k - 4
int matrix[5][5] = {
                        {0, 0, 0, 0, 0},
                        {0, 1, 2, 3, 4},
                        {0, 2, -1, 4, -3},
                        {0, 3, -4, -1, 2},
                        {0, 4, 3, -2, -1}
                    };

int index(char x)
{
    switch (x) {
    case '1':
        return 1;
    case 'i':
        return 2;
    case 'j':
        return 3;
    case 'k':
        return 4;
    }
}

int mult(int a, int b)
{
    int sa = a < 0 ? -1 : 1;
    int sb = b < 0 ? -1 : 1;

    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;

    return sa * sb * matrix[a][b];
}

int pow(int a, long long w)
{
    if (a == 1)
        return 1;
    if (a == -1)
        return w%2 == 0 ? 1 : -1;
    switch (w % 4) {
    case 0:
        return 1;
    case 1:
        return a;
    case 2:
        return -1;
    case 3:
        return -a;
    }
}

string solution()
{
    long long MAX = L * X;

    if (MAX < 3)
        return "NO";

    int product = 1;
    for (int i=0; i<L; i++) {
        data[i] = index(line.c_str()[i]);
        product = mult(product, data[i]);
    }

    int total = pow(product, X);
    if (total != -1)
        return "NO";

    long long p = 0;

    string si = "", sj = "", sk = "";

    int str_i, str_j, str_k;
    str_i = 1;
    while (p < MAX) {
        str_i = mult(str_i, data[p%L]);
        si += line.substr(p%L, 1);
        p++;

        if (str_i == 2) break;
        if (p > 6*L) return "NO";
    }
    if (str_i != 2)
        return "NO";

    str_j = 1;
    while (p < MAX) {
        str_j = mult(str_j, data[p%L]);
        sj += line.substr(p%L, 1);
        p++;

        if (str_j == 3) break;
        if (p > 12*L) return "NO";
    }

    if (str_j != 3)
        return "NO";

    str_k = 1;
    while (p < MAX && p%L != 0) {
        str_k = mult(str_k, data[p%L]);
        sk += line.substr(p%L, 1);
        p++;
    }

    if (mult(str_k, pow(product, X-p/L)) != 4)
        return "NO";


    return "YES";
}

string solution2()
{
    int prod = 1;
    for (int i=0; i<X*L; i++) {
        data[i] = index(line.c_str()[i%L]);
        prod = mult(prod, data[i]);
    }

    if (prod != -1)
        return "NO";


    int p = 1;
    for (int i=0; i<X*L; i++) {
        p = mult(p, data[i]);
        if (p == 2) {
            int q = 1;
            for (int j=i+1; j<X*L; j++) {
                q = mult(q, data[j]);
                if (q == 3) {
                    return "YES";
                }
            }
        }
    }

    return "NO";
}

int main()
{
    ifstream fin("C-large.in");
    ofstream fout("C-large.out");

    int TC;
    fin >> TC;

    for (int T=1; T<=TC; T++) {
        fin >> L >> X;
        fin >> line;

        fout << "Case #" << T << ": " << solution() << endl;
        cout << "Case #" << T << ": " << solution() << endl;
    }


    fin.close();
    fout.close();

    return 0;
}
