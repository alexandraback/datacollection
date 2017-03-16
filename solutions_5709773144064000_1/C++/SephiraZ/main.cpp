#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[])
{
    double num;
    double fram,regenrate,traget;
    double timefinal = 999999999,timecurrent = 0,timebuy = 0;
    double regencurrent = 2.0;
    ifstream myfile ("B-large.in");
    ofstream myfile2 ("output.txt");
    myfile >> num;
    for(int aa=1;aa<=num;aa++)
{
    double abc = 0;
 timefinal = 999999999,timecurrent = 0,timebuy = 0;
 regencurrent = 2.0;
    myfile >> fram >> regenrate >> traget;
    timefinal = traget/2.0;
    // test buy1
    while(abc != -1)
 {
    timebuy = timebuy+(fram/regencurrent);
    regencurrent = regencurrent+regenrate;
    timecurrent = timebuy+(traget/regencurrent);
    if(timecurrent < timefinal)
    {
    timefinal = timecurrent;
    abc = 1;
    }
    else
    abc = -1;
}
    //
    //
    myfile2 << "Case #" << aa << ": "<< fixed<<setprecision(7) << showpoint <<timefinal << endl;
}
   // system("PAUSE");
    return EXIT_SUCCESS;
}
