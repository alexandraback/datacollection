#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <stack>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
using namespace std::tr1;

string solve(string& input)
{
	stringstream ssin(input);
	int N;
	ssin >> N;
	vector<int> points(N);
	double X = 0.0;
	for (int i = 0; i < N; ++ i) {
		ssin >> points[i];
		X += points[i];
	}
	double minPoints = 2 * X / N;
	vector<double> minPercentages(N);
	double sumNegPercentages = 0.0;
	int numAlreadySafeContestants = 0;
	for (int i = 0; i < N; ++ i) {
		minPercentages[i] = 100 * (minPoints - points[i]) / X;
		if (minPercentages[i] < 0.0) {
			sumNegPercentages += minPercentages[i];
			++numAlreadySafeContestants;
			minPercentages[i] = 0.0;
		}
	}
	if (numAlreadySafeContestants > 0) {
		double meanNegPercentage = sumNegPercentages / (N - numAlreadySafeContestants);
		for (int i = 0; i < N; ++ i) {
			if (minPercentages[i] > 0.0) {
				minPercentages[i] += meanNegPercentage;
			}
		}
	}
	stringstream ssout;
	for (int i = 0; i < N; ++ i) {
		ssout << " " << fixed << setprecision(5) << minPercentages[i];
	}
	return ssout.str();
}

int main()
{
	int numCases;
	cin >> numCases;
	cin.ignore();
	vector<string> input(numCases);
	vector<string> output(numCases);
	for (int i = 0; i < numCases; ++i) {
		getline(cin, input[i]);
	}
	#pragma omp parallel for
	for (int i = 0; i < numCases; ++i) {
		output[i] = solve(input[i]);
	}
	for (int i = 0; i < numCases; ++i) {
		cout << "Case #" << i + 1 << ":" << output[i] << endl;
	}
}
