#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <limits>


using namespace std;

int main() {

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int T;

	fin >> T;

    for (int t = 1; t <= T; ++t)
    {
        double C, F, X;
        fin >> C >> F >> X;

        // Test info received

        double prevResult = std::numeric_limits<double>::infinity();
        double curResult = std::numeric_limits<double>::infinity();
        double curSpeed = 2;
        double N = 0;

        do
        {
            prevResult = curResult;

            curResult = 0;
            for (int i = 0; i < N; ++i)
            {
                curResult += C / (2 + F * i);
            }
            curResult += X / (2 + F * N);

            N++;
        } while (curResult < prevResult);

        // Output

        fout << "Case #" << t << ": ";
        fout << fixed << setprecision(7) << prevResult << endl;
    }

	fin.close();
	fout.close();

	return 0;
}
