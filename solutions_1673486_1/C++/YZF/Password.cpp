#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

double expected(int total, vector<double> p)
{
    int typed = p.size();
    double eenter = total + 2.0;

    for(int bs=0; bs<typed; ++bs)
    {
        double pcorrect = 1.0;

        for(int i=0; i<p.size()-bs; ++i)
        {
            pcorrect = p[i] * pcorrect;
        }
        int remain = total - typed + 1;
        double ecorrect = pcorrect*(remain + bs*2) + (1.0-pcorrect)*(remain + bs*2 + total + 1);
//        cout << bs << " backspaces " << ecorrect << " " << remain + bs*2 << " " << remain + bs*2 + total + 1 << endl;
        if(ecorrect<eenter)
        {
            eenter = ecorrect;
        }
    }

    return eenter;
}

int main(int argc, char* argv[])
{
    ifstream infile;
    ofstream outfile;
    
//    infile.open( "/Users/Guy/Downloads/C-small-attempt0.in");
//    infile.open( "/Users/Guy/Downloads/A-small-attempt2.in");
//    infile.open( "/Users/Guy/Downloads/C-large.in");
//    infile.open( "/gcjam/input.txt");
    infile.open( "/Users/Guy/Downloads/A-large.in");
    outfile.open( "/gcjam/output.txt");

    int ntestcases;
    infile >> ntestcases;
    infile.ignore(1, '\n');

    for(int i=0; i<ntestcases; ++i)
    {
        int A, B;
        infile >> A;
        infile >> B;

        vector<double> p;
        p.clear();
        for(int j=0; j<A; ++j)
        {
            double prob;
            infile >> prob;
            p.push_back( prob );
        }

        outfile << "Case #" << i+1 << ": " << setprecision (10) << expected(B, p) << endl;
//        cout << "Case #" << i+1 << ": " << setprecision (10) << expected(B, p) << endl;
    }
	return 0;
}