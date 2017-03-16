#include <QFile>
#include <QtGlobal>
#include <QTextStream>

#include <QDebug>

#include <vector>
#include <iostream>
#include <algorithm>

//#define STDOUT

QTextStream input;

#ifndef STDOUT
    QTextStream output;
#else
    std::ostream &output = std::cout;
#endif

int FairScore(std::vector<double> naomi, std::vector<double> ken)
{
    int result = 0;
    while(!naomi.empty()) {
        if(naomi.back() > ken.back()) {
            ++result; ken.erase(ken.begin());
        }
        else ken.pop_back();
        naomi.pop_back();
    }
    return result;
}

int CheaterScore(std::vector<double> naomi, std::vector<double> ken)
{
    int result = 0;
    for(int i = 0; i < naomi.size(); ++i) {
        if(naomi[i] > ken.front()) {
            ken.erase(ken.begin());
            ++result;
        }
        else ken.pop_back();
    }
    return result;
}

void SolveCase()
{
    int N; input >> N;
    std::vector<double> naomi(N), ken(N);
    for(int n = 0; n < N; ++n) input >> naomi[n];
    for(int n = 0; n < N; ++n) input >> ken[n];
    std::sort(naomi.begin(), naomi.end());
    std::sort(ken.begin(), ken.end());
    output << CheaterScore(naomi, ken) << ' ' << FairScore(naomi, ken) << '\n';
}

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    QFile infile("input.txt");
    infile.open(QIODevice::ReadOnly);
    input.setDevice(&infile);

#   ifndef STDOUT
        QFile outfile("output.txt");
        outfile.open(QIODevice::WriteOnly);
        output.setDevice(&outfile);
        output.setRealNumberPrecision(10);
#   endif

    uint T; input >> T;
    for(uint t = 1; t <= T; ++t)
    {
        output << "Case #" << t << ": ";
        SolveCase();
    }

    return 0;
}
