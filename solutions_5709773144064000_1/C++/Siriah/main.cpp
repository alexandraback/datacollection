#include <iostream>
#include <fstream>
using namespace std;

const string INPUT_FILE = "B-large.in";
const string OUTPUT_FILE = "output_B_large.txt";

const double EPSILON = 0.000001;

double getBestTime(double timeToGoal, double farmCost, double farmRevenue, double cookiesPerSecond, double goal) {
    //It's always best to buy a farm immediately or not at all.
    double timeToFarm = farmCost / cookiesPerSecond;
    if (timeToFarm < EPSILON) {
        //INFINITE FARMS!
        return 0.0;
    }
    cookiesPerSecond += farmRevenue;
    double newTimeToGoal = timeToFarm + (goal / cookiesPerSecond);
    if (newTimeToGoal > timeToGoal) {
        return timeToGoal;
    }
    else
        return timeToFarm + getBestTime(goal / cookiesPerSecond, farmCost, farmRevenue, cookiesPerSecond, goal);
}

double solveCase(ifstream & input) {
    double cookiesPerSecond = 2.0;
    double farmCost, farmRevenue, goal;
    input >> farmCost;
    input >> farmRevenue;
    input >> goal;
    double timeToGoal = goal / cookiesPerSecond;

    cerr << "CASE: " << farmCost << " " << farmRevenue << " " << goal << endl;
    return getBestTime(timeToGoal, farmCost, farmRevenue, cookiesPerSecond, goal);
}

void solveAllCases(ifstream & input, ofstream & output) {
    output.precision(7);
    output.setf(ios::fixed);
    int cases;
    input >> cases;
    cout << "Testcases to run: " << cases << endl;
    for (int i = 1; i <= cases; i++) {
        output << "Case #" << i << ": ";
        output << solveCase(input);
        output << endl;
    }
}

int main()
{
    ifstream input(INPUT_FILE.c_str(), ios::in);
    ofstream output(OUTPUT_FILE.c_str(), ios::out);
    solveAllCases(input, output);
    input.close();
    output.close();
    return 0;
}
