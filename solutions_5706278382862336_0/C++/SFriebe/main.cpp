#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <vector>
#include <math.h>

using namespace std;

ifstream in;
stringstream out;


void run_case()
{
    long A, B;
    char slash;
    in >> A >> slash >> B;
    //cout << "--" << A << "--" << " --"<<B << "--\n";
    int generations = 0;
    int min = 99;
    while (generations < 40)
    {
        if (A >= B)
        {
            A -= B;
            if (min == 99)
                min = generations;
        }
        if (A == 0)
        {
            out << min;
            return;
        }
        A *= 2;
        generations++;
    }
    out << "impossible";
}

int main(int argc, char **argv)
{
    int n_cases = 0;
    int n_case  = 0;


    //string input_file = "sample.in";
    string input_file = "A-small-attempt0.in";
    //string input_file = "A-large.in";
    //string input_file = "a.in";
    string output_file;

    if (argc > 1)
        input_file = argv[1];

    if (argc > 2)
        output_file = argv[2];
    else
    {
        output_file = input_file;
        string::size_type pos = output_file.rfind('.');

        if (pos != string::npos)
        {
            output_file.replace(pos + 1, string::npos, "out");
        }
        else
        {
            output_file += ".out";
        }
    }

    in.open(input_file);

    if (!in.is_open() || !in.good())
    {
        cerr << "Could not open input file '" << input_file << "'!\n";
        return 1;
    }

    ofstream outfile(output_file, ofstream::trunc);

    if (!outfile.is_open() || !outfile.good())
    {
        cerr << "Could not open output file '" << output_file << "'!\n";
        return 2;
    }

    // Set precision
    out.precision(12);

    in >> n_cases;
    cout << n_cases << " testcases in file.\n";

    for (n_case = 1; n_case <= n_cases; n_case++)
    {
        cout << "\nCase #" << n_case << ":\n";
        out << "Case #" << n_case << ": ";
        run_case();
        out << "\n";
    }

    // Write contents to file
    outfile << out.str();

    // Output file-data
    cout << "\nWritten to file:\n================\n" << out.str() << "\n================\n";

    if (!outfile.good())
        cerr << "Error writing output file!\n";

    in.close();
    outfile.close();

    if (input_file.compare("sample.in") == 0)
    {
        cout << "Comparing:\n";
        int status = system("diff sample.out sample.lst");
        if (status == 0)
            cout << "Equal! :)\n";
    }

    return 0;
}
