#include <iostream>
#include <sstream>
#include <numeric>
#include <set>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <strings.h>

using namespace std;

struct Hiker {
	long initial;
	long minutes;
};

const double EPSILON = 1e-6;

int main(){
	int tests;
	cin >> tests;
	for (int t = 0; t < tests; t++){
		vector<Hiker> hikers;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++){
			int Di, Hi, Mi;
			cin >> Di >> Hi >> Mi;
			for (int j = 0; j < Hi; j++){
				struct Hiker hiker;
				hiker.initial = Di;
				hiker.minutes = Mi + j;
				hikers.push_back(hiker);
			}
		}
		vector<double> completes;
		long bestSolution = hikers.size();
		for (int i = 1; i <= hikers.size() + 1; i++){
			for (int j = 0; j < hikers.size(); j++){
				double t = (360 * (i - 1) + 360.0 - hikers[j].initial) * hikers[j].minutes / 360.0;
				completes.push_back(t);
				completes.push_back(t+EPSILON);
				completes.push_back(t-EPSILON);
			}
		}
		for (int i = 0; i < completes.size(); i++){
			double time = completes[i];
			long cross = 0;
			for (int j = 0; j < hikers.size(); j++){
				double timeFirst = (360.0 - hikers[j].initial) * hikers[j].minutes / 360.0;
				if (timeFirst > time){//0 vueltas
					cross++;
				} else {
					double timeRem = time - timeFirst;
					long others = (timeRem / hikers[j].minutes);
					others++;
					if (others > 1){
						cross += (others - 1);
					}
				}
			}
			bestSolution = min(bestSolution, cross);
		}
		cout << "Case #" << (t+1) << ": " << bestSolution << endl;
	}
}
