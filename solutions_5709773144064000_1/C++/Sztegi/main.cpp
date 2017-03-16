#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct TestCase
{

    vector< vector<int> > _cards1;
    vector< vector<int> > _cards2;

    int _answer1;
    int _answer2;

    string answer()
    {
        int count = 0;
        int card = 0;

        vector<int> &row2 = _cards2[_answer2-1];

        for(int i = 0; i <4; ++i)
        {
            if(row2.end() != find(row2.begin(), row2.end(), _cards1[_answer1-1][i]))
            {
                card = _cards1[_answer1-1][i];
                ++count;
            }
        }

        if(count == 0) return  "Volunteer cheated!";

        if(count == 1)
        {
            char buf[3];
            sprintf(buf, "%d", card );
            return  string(buf);
        }

        return "Bad magician!";
    }

};

double solve(double factoryCost, double prodPerFactory, double goal)
{
    double lastProdPerSec = 2;
    double lastGoalSec = goal/lastProdPerSec;
    double lastFactorySec = 0;

    while(true)
    {
        double factorySec = factoryCost/lastProdPerSec;
        double prodPerSec = lastProdPerSec + prodPerFactory;
        double goalSec = lastFactorySec + factorySec + goal/prodPerSec;

        if(goalSec>=lastGoalSec) break;

        lastFactorySec = lastFactorySec + factorySec;
        lastGoalSec = goalSec;
        lastProdPerSec = prodPerSec;
    }

    return lastGoalSec;
}

int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");

    out.precision(15);

    int t;
    string line;

    {
        std::getline(in, line);
        istringstream iss(line);
        iss >> t;
    }

    for(int i = 0; i < t; ++i)
    {

        double c, f, x;

        std::getline(in, line);
        istringstream iss(line);
        iss >> c >> f >> x;

        out << "Case #" << i + 1 << ": " << solve(c,f,x) << endl;
    }

    return 0;
}

