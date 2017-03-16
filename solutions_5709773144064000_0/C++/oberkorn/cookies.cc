#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

void syntax(char** argv) {
    printf("Syntax: %s <filename>\n", argv[0]);
}

double n_farms_cost() {
}

double get_result(double c, double f, double x) {
    double cost_of_farms = 0;
    double best_result = x / 2;
    for (;;) {
        for (int i=1; ; ++i) {
            cost_of_farms += c / ( 2 + (i - 1) * f);
            double result = cost_of_farms + x / (2 + i*f);
            if (result > best_result) {
                return best_result;
            }
            best_result = result;
        }
    }
}
 
int main(int argc, char** argv) {
    if (argc != 2) {
        syntax(argv);
        return 1;
    }
    ifstream in;
    in.open(argv[1], ios::in);
    if (!in) {
        cerr << "Could not open file " << argv[1] << endl;
        return 1;
    }
    int numTestCases;
    in >> numTestCases;
    for (int i=0; i<numTestCases; ++i) {
        double c,f,x;
        in >> c >> f >> x;
        printf("Case #%i: %0.7f\n", i+1, get_result(c,f,x)); 
    }
    in.close();
    return 0;
}
