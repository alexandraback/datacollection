#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iomanip>

using std::endl;
using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;
using std::set;
using std::set_intersection;
using std::inserter;
using std::fixed;

double calc(double C, double F, double X, int n)
{
	double result = C/2 + X/(n*F+2);
	for (int i=1; i!=n; ++i)
		result += C/(i*F+2);
	return result;
}

int main()
{
	ifstream cin("B-small.in");
	ofstream cout("B-small.out");

	int cases;
	cin >> cases;
	cin.ignore();

	for (int case_no = 1; case_no != cases+1; ++case_no) {
		double C, F, X;
		cin >> C >> F >> X;
		double time = X/2;
		int i=1;
		double result = time;
		do {
			time = result;
			result = calc(C,F,X,i++);
		} while (result < time);
		cout.precision(7);
		cout << "Case #" << case_no << ": " << fixed << time << endl;
	}
	return 0;

}