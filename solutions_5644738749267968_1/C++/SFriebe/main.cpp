#include <iostream>
#include <fstream>
#include <set>

using namespace std;

ifstream in;
ofstream out;

/// Comparator with delta to avoid problems when checking for equality
bool compareDelta(const double& lhs, const double& rhs)
{
    static const double DELTA = 0.00000001;
    bool res = lhs - DELTA < rhs && lhs + DELTA < rhs;
//    cout << "cmp "<< lhs << " " << rhs << " " << res << "\n";
    return res;
}

/// Naomi's honest play
double naomi_move_normal(set<double, bool (*)(const double&, const double&)>& naomi)
{
    auto iter = naomi.begin();
    double choice = *iter;
    naomi.erase(iter);

    return choice;
}

/// Naomi's deceitful play
double naomi_move_deceitful(set<double, bool (*)(const double&, const double&)>& naomi, double& naomi_used, set<double, bool (*)(const double&, const double&)>& ken, double& told)
{
    // Find the biggest one of Ken
    double max_ken = 0.0;
    for (auto d : ken)
        if (max_ken < d)
            max_ken = d;
    double min_ken = 1.0;
    for (auto d : ken)
        if (min_ken > d)
            min_ken = d;

    double max_naomi = 0.0; // Can not be this small
    for (auto d : naomi)
        if (max_naomi < d)
            max_naomi = d;
    double min_naomi = 1.0; // Can not be this big
    for (auto d : naomi)
        if (min_naomi > d)
            min_naomi = d;

    // Take the block that is the minimum heavier as Kens smallest block and pretend it is veeery heavy
    for (auto d : naomi)
    {
        if (min_ken < d)
        {
            min_ken = d;
            // Set is sorted ascending
            naomi_used -= 0.00000001;
            while (ken.find(naomi_used) != ken.end())
                naomi_used -= 0.00000001;
            told = naomi_used;
            naomi.erase(d);
            return d;
        }
    }

    // Non found, take the smallest one
    auto iter = naomi.begin();
   told = *iter;
    naomi.erase(iter);
    return told;
}

/// Kens optimal move
double ken_move_normal(set<double, bool (*)(const double&, const double&)>& ken, const double naomi_choice)
{
    // Ken always use the smallest one that is bigger than Naomis one
    double min = 1.0; // Can not be this big
    for (auto d : ken)
        if (min > d && d > naomi_choice)
            min = d;
    // If no winning block could be found, take the smallest one
    if (min == 1.0)
    {
        for (auto d : ken)
            if (min > d)
                min = d;
    }
    //cout << "erase(" << min << ")\n";
    //cout << "erased: " << ken.erase(min) << "\n";
    ken.erase(min);

    return min;
}

/// Reads a line from the input and calculates the results
void run_case()
{
    // Load data
    int nStones;
    in >> nStones;
    set<double, bool (*)(const double&, const double&)> naomi(compareDelta);
    set<double, bool (*)(const double&, const double&)> ken(compareDelta);
    double value;

    for (int i = 0; i < nStones; i++)
    {
        in >> value;
        naomi.insert(value);
    }
    for (int i = 0; i < nStones; i++)
    {
        in >> value;
        ken.insert(value);
    }

    cout << "Naomi's stones:  ";
    for (double n : naomi)
        cout << n << "; ";
    cout << "\nKen's stones:\t ";
    for (double n : ken)
        cout << n << "; ";
    cout << "\n";

    // Calculate normal points
    int pointsNormal = 0;

    auto naomi_normal = naomi;
    auto ken_normal = ken;
    double naomi_choice, ken_choice;
    for (int round = 1; round <= nStones; round++)
    {
        // Take (a random) one from Naomi
        naomi_choice = naomi_move_normal(naomi_normal);

        // Find the best one for Ken
        ken_choice = ken_move_normal(ken_normal, naomi_choice);

        //cout << naomi_choice << " against " << ken_choice << ": " << (naomi_choice > ken_choice) << "\n";

        // Give Naomi a point if she won
        if (ken_choice < naomi_choice)
            pointsNormal++;
    }


    // Calculate deceitful points
    int pointsDeceitful = 0;

    auto naomi_deceitful = naomi;
    ken_normal = ken;
    double naomi_used = 1.0;
    double naomi_real_choice;
    for (int round = 1; round <= nStones; round++)
    {

        naomi_real_choice = naomi_move_deceitful(naomi_deceitful, naomi_used, ken_normal, naomi_choice);

        // Find the best one for Ken
        ken_choice = ken_move_normal(ken_normal, naomi_choice);

        //cout << naomi_choice << " (" << naomi_real_choice << ") against " << ken_choice << ": " << (naomi_choice > ken_choice) << "\n";

        // Give Naomi a point if she won
        if (ken_choice < naomi_real_choice)
            pointsDeceitful++;
    }


    cout << "Decietful:\t " << pointsDeceitful << "\n";
    cout << "Normal:\t\t " << pointsNormal << "\n";
    out << pointsDeceitful << " " << pointsNormal << "\n";
}

int main()
{
    int n_cases = 0;
    int n_case  = 0;

    cout.precision(10);

    //in.open("D-small-attempt_sample.in");
    //in.open("D-small-attempt0.in");
    in.open("D-large.in");

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

    in >> n_cases;

    for (n_case = 1; n_case <= n_cases; n_case++)
    {
        cout << "\nCase #" << n_case << ":\n";
        out << "Case #" << n_case << ": ";
        run_case();
    }

    in.close();

    return 0;
}
