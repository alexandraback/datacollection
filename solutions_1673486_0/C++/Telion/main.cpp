//Christopher Mueller
//Made for Google Code Jam 2012

#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

double solve(istream& infile)
{
    int A, B;
    infile >> A >> B;

    vector <double> v(A);
    for(int i = 0; i < A; ++i)
    {
        double temp;
        infile >> temp;
        v[i] = temp;
    }

    double keystrokesGiveUp = B + 2;

    double keystrokesBackspace = 1.0e300;
    for(int i = 0; i < A; ++i)
    {
        double chanceOfSuccess = 1.0f;
        for(int j = 0; j < A - i; ++j)
            chanceOfSuccess *= v[j];

        double keystrokes = (B - A + 1 + 2 * i) * chanceOfSuccess + (2 * B - A + 2 + 2 * i) * (1.0 - chanceOfSuccess);
        if(keystrokes < keystrokesBackspace)
            keystrokesBackspace = keystrokes;
    }

    double keystrokes = keystrokesBackspace;
    if(keystrokesBackspace > keystrokesGiveUp)
        keystrokes = keystrokesGiveUp;

//    stringstream ss;
//    ss << keystrokes;
//    return ss.str();

    return keystrokes;
}

int main()
{
    string str;

    ifstream infile("A-small-attempt0.in");
    int T;
    infile >> T;
    getline(infile, str);

    ofstream outfile("output.txt");
    for(int i = 0; i < T; ++i)
    {
        outfile << "Case #" << i + 1 << ": ";

        double d = solve(infile);

        outfile << fixed << setprecision(6);
        outfile << d << endl;
    }

    return 0;
}
