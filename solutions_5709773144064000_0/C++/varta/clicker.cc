#include <fstream>
#include <iostream>
#include <limits>


double get_time(double C, double F, double target, int n, double stn)
{
    double r0 = 2.0;
    double T = (target + n * C + F * stn) / (r0 + n * F);
    return T;
}
void solve_case(int icase, std::ifstream& ifile)
{
    double C, F, X;
    ifile >> C >> F >> X;
    bool bsolve = false;
    int nx = 0;
    double tnext = std::numeric_limits<double>::max();
    double tbest = tnext;
    double stn = 0.0;
    while (!bsolve)
    {
	tbest = tnext;
	double tX = get_time(C, F, X, nx, stn);
	double tc = get_time(C, F, C, nx, stn);

	stn += tc;
	tnext = tX;

	bsolve = tnext >= tbest;
	++ nx;
    }

    std::cout.precision(7);
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout << "Case #" << icase << ": " << tbest << std::endl;
}

void all_cases(std::ifstream& ifile)
{
    int ncases;
    ifile >> ncases;
    for (int i = 0; i < ncases; ++ i)
    {
	solve_case(i+1, ifile);
    }
}

int main(int argv, char** argc)
{
    if (argv < 2)
    {
	std::cerr << "Usage: " << std::string(argc[0]) << " inputfile\n";
	return -1;
    }
    std::ifstream infile(argc[1]);
    all_cases(infile);
}
