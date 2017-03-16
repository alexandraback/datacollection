#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
 
using namespace std;
 
double solve(size_t index, const vector<int> &judgements) {
	int sum = accumulate(judgements.begin(), judgements.end(), 0);
	double left = 0.f, right = 1.f;
	while (right - left > 1e-9) {
		double middle = left + 0.5 * (right - left);
		double pointsAtIndex = judgements[index] + sum * middle;
		double percentageLeft = 1.f - middle;
		for (size_t i = 0; i < judgements.size(); ++i) {
			if (i == index) continue;
			percentageLeft -= max(pointsAtIndex - judgements[i], 0.0) / sum;
		}
		
		if (percentageLeft >= 0)
			left = middle;
		else
			right = middle;
	}
	
	return 100.0 * left;
}
 
int main() {
        size_t cases;
        cin >> cases;
        for (size_t c = 0; c < cases; ++c) {
                size_t n;
                cin >> n;
                vector<int> judgePoints;
                int x = 0;
                for (size_t i = 0; i < n; ++i) {
                        int j;
                        cin >> j;
                        x += j;
                        judgePoints.push_back(j);
                }
                
                cout << "Case #" << c + 1 << ": ";
                for (size_t i = 0; i < n; ++i) {
                        double ans = solve(i, judgePoints);
                        printf("%.6lf ", ans); 
                }
                cout << endl;
        }
        return 0;
}