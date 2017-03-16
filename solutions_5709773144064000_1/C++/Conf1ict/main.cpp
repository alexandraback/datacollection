#include <fstream>
#include <iomanip>
#include <string>
#include <list>
#include <unordered_map>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>

using namespace std;

ifstream input ("input.txt",  ios_base::in);
ofstream output("output.txt", ios_base::out);

void solveCase()
{
    output << fixed << setprecision(7);

    const double rate = 2.0;
    double cost, f, goal;
    input >> cost >> f >> goal;

    double ot = cost / f;
    int best_number = int(((f*goal/cost)-rate)/f);
    if(best_number < 0) best_number = 0;
    double sum = 0;
    for(int i = 0; i < best_number; ++i)
        sum += cost / ( rate + f * i );
    sum += goal / ( rate + f * best_number );
    output << sum;
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
