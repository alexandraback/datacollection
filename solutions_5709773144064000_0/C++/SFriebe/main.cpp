#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

ifstream in;
ofstream out;

// cps = cookies per second
double base_cps = 2.0;

/// When having start cookies and earning at rate, how long till you are at aim?
double waiting_time(double start, double rate, double aim)
{
    // y = m*x + n
    // x = (y - n) / m
    if (rate == 0)
        return 9999999;
    else
        return (aim - start) / rate;
}

double calc_min_time(double current_rate, double cost, double rate, double victory)
{

    // Time if a farm is build:
    // Time till buying a farm is possible
    double buy_waiting = waiting_time(0, current_rate, cost);
    // Waiting after the farm is build
    double buy_after = waiting_time(0, current_rate + rate, victory);
    // Time until victory if the farm has been build
    double buying = buy_waiting + buy_after;

    // Time if waiting:
    double waiting = waiting_time(0, current_rate, victory);

    // Is waiting faster than buying?
    if (waiting < buying)
        // Then return the waiting time
        return waiting;
    else
        // Else check again if another farm makes sense
        return buy_waiting + calc_min_time(current_rate + rate, cost, rate, victory);
}

/// Reads a line from the input and returns the min. needed time
void run_case()
{
    double cost;
    double bonus;
    double victory;

    in >> std::setprecision(20);
    in >> cost;
    in >> bonus;
    in >> victory;
    // Ignore rest of line
//    in.ignore(99999999, '\n');

    cout << std::setprecision(10) << "Costs: " << cost << "\tBonus-CpS: " << bonus << "\tVictory: " << victory;

    double mintime = calc_min_time(base_cps, cost, bonus, victory);

    cout << "\tMintime: " << mintime << "\n";
    out << mintime << "\n";
}

int main()
{

    int n_cases = 0;
    int n_case  = 0;

    in.open("B-small-attempt1.in");

    if (!in.is_open() || !in.good())
    {
        cerr << "Could not open input file!\n";
        return 1;
    }

    out.open("output.txt", ofstream::trunc);

    if (!out.is_open() || !out.good())
    {
        cerr << "Could not open output file!\n";
        return 2;
    }

    // Set precision
    out.precision(12);

    /*
    cout << waiting_time(0, 2, 500) << "\n";
    cout << waiting_time(0, 6, 500) << "\n";
    cout << waiting_time(0, 10, 500) << "\n";
    cout << waiting_time(0, 14, 500) << "\n";
    cout << waiting_time(0, 14, 2000) << "\n";
    */

    //int arr[] = {1,2,3,4};
    //cout << "isIn: " << isIn(1, arr) << "\n";
    //int arr2[] = {-1,20,30,40};
//    cout << "intersect: " << intersect(arr, arr2) << "\n";

    in >> n_cases;

    for (n_case = 1; n_case <= n_cases; n_case++)
    {
        out << "Case #" << n_case << ": ";
        run_case();
    }

    in.close();

    return 0;
}
