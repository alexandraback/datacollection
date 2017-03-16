#include <fstream>
#include <iomanip>
#include <string>
#include <list>
#include <unordered_map>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <cassert>

using namespace std;

ifstream input ("input.txt",  ios_base::in);
ofstream output("output.txt", ios_base::out);

int war(const vector<double> &naomi, const vector<double> &ken)
{
    auto npos = naomi.begin();
    auto kpos = ken.begin();
    while(npos < naomi.end() && kpos < ken.end()) {
        while(*kpos < *npos) {
            ++kpos;
            if(kpos == ken.end())
                return distance(npos, naomi.end());
        }
        ++npos;
        ++kpos;
    }
    return distance(npos, naomi.end());
}

int d_war(const vector<double> &naomi, const vector<double> &ken)
{
    int score = 0;

    auto npos = naomi.begin();
    auto kpos = ken.begin();

    while(npos < naomi.end() && kpos < ken.end()) {
        if(*npos > *kpos) {
            ++score;
            ++kpos;
        }
        ++npos;
    }

    return score;
}

void solveCase()
{
    int n;
    input >> n;

    vector<double> naomi;
    vector<double> ken;

    for(int i = 0; i < n; ++i) {
        double buf;
        input >> buf;
        naomi.push_back(buf);
    }

    for(int i = 0; i < n; ++i) {
        double buf;
        input >> buf;
        ken.push_back(buf);
    }

    sort(naomi.begin(), naomi.end());
    sort(ken.begin(),   ken.end());
    output  << d_war(naomi, ken)
            << " "
            << war(naomi, ken);

}

int main()
{
    int n;
    input >> n;

    for(int i = 1; i <= n; ++i)
    {
        output << "Case #" << i << ": ";
        solveCase();
        output << endl;
    }
}
