#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using std::vector;
void solve(int id) {
	// local variables
    vector<double> naomi;
    vector<double> ken;
    int n = 0;
    std::cin>>n;
	// read data
    double temp = 0;
    for (int i = 0; i < n; i++) {
        std::cin>>temp;
        naomi.push_back(temp);
    }
	for (int i = 0; i < n; i++) {
        std::cin>>temp;
        ken.push_back(temp);
    }
    // process
    std::sort(naomi.begin(), naomi.end());
    std::sort(ken.begin(), ken.end());
    // deceitful war
    int dscore = 0, na = 0;
    for (int i = 0; i < n; i++) {
        for (; na < n; na++) {
            if (naomi[na] > ken[i]) {
                dscore++;
                na++;
                break;
            }
        }
    }
    // war
    int score = n, k = 0;
    for (int i = 0; i < n; i++) {
        for (; k < n; k++) {
            if (ken[k] > naomi[i]) {
                score--;
                k++;
                break;
            }
        }
    }
    // output
	printf("Case #%d: %d %d\n", id, dscore, score);
}

int main(int argc, char *argv[]) {
	int t = 0;
	std::cin>>t;
	for (int i = 1; i <= t; i++) {
		solve(i);
	}
}