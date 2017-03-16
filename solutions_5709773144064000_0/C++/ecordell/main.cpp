#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <limits>

typedef std::numeric_limits< double > dbl;

int main(int argc, const char * argv[])
{
    std::ifstream infile("/Users/evan/Git/GoogleCodeJam/Qualification/Problem B/QualProblemB/QualProblemB/B-small-attempt0.in");
    std::ofstream outfile;
    outfile.open("/Users/evan/Git/GoogleCodeJam/Qualification/Problem B/QualProblemB/QualProblemB/small.out");
    
    
    int T; //number of test cases
    infile >> T;
    
    long double rate = 2.0;
    
    for (int tcase = 1; tcase<=T; tcase++) {
        long double farmCost, farmRate, goal, time, oldTime;
        infile >> farmCost >> farmRate >> goal;
        oldTime = (goal / rate);
        
        for (long double numFarms = 0; ; numFarms++) {
            long double pureTime = (goal / (rate + numFarms * farmRate));
            long double farmTime = 0;
            
            for (long double i = 1; i<=numFarms; i++) {
                farmTime += (farmCost/(rate + ((i-1) * farmRate)));
            }
            time = pureTime + farmTime;
            if (time <= oldTime) {
                oldTime = time;
            } else {
                break;
            }
        }
        outfile.precision(dbl::digits10);
        outfile << "Case #" << tcase << ": " << oldTime << '\n';
    }
    outfile.close();
    return 0;
}

