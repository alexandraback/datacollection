#include <iostream>
#include <fstream>
#include <algorithm>
#include <deque>
#include <sstream>
using namespace std;

const string INPUT_FILE = "b-large.in";
const string OUTPUT_FILE = "out.txt";

long long calculate(long long a, long long b, long long k) {
    long long score = 0;
    for (long long i = k; i < a; i++) {
        for (long long j = k; j < b; j++) {
            if ((i & j) < k) score++;
        }
    }
    return score;
}

string solveCase(ifstream & input) {
    long long a, b, k;
    input >> a;
    input >> b;
    input >> k;
    long long ak = min(a, k);
    long long bk = min(b, k);

    long long score = ak * bk;
    cerr << score << endl;

    if (a > k) {
        score += ((a-k) * bk);

    cerr << score << endl;
    }

    if (b > k) {
        score += ((b-k) * ak);

    cerr << score << endl;
    }

    if (a > k && b > k) {
        score += calculate(a,b,k);

    cerr << score << endl;
    }

    ostringstream conv;
    conv << score;

    return conv.str();
}

void solveAllCases(ifstream & input, ofstream & output) {
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
