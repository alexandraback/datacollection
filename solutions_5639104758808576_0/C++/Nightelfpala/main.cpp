#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>

using namespace std;

class feladat
{
public:
    void read(FILE* inf);
    int mego();
private:
    int smax;
    vector<int> shyness;
};

void feladat::read(FILE* inf)
{
    fscanf(inf, "%d", &smax);
    shyness.resize(smax + 1);
    for (int i = 0; i < smax + 1; ++i)
    {
        fscanf(inf, "%1d", &shyness[i]);
    }
    //cout << endl << "thx" << endl;
}

int feladat::mego()
{
    int van = 0;
    int kell = 0;
    for (int i = 0; i < smax + 1; ++i)
    {
        //cout << "\t sh: " << shyness[i];
        if (shyness[i] != 0 && van < i)
        {
            kell += i - van;
            van = i;
        }
        van += shyness[i];
        //cout << "\t" << van << "\t" << kell << endl;
    }
    return kell;
}

int main()
{
    int t;
    FILE* infile = fopen("A-small-attempt0.in","r");
    fscanf(infile, "%d", &t);
    ofstream kifile("ki.txt");
    for (int i = 0; i < t; ++i)
    {
        feladat eset;
        eset.read(infile);
        //cout << "Case #" << i + 1 << ": " << eset.mego() << endl;
        kifile << "Case #" << i + 1 << ": " << eset.mego() << endl;
    }
    kifile.close();
    return 0;
}
