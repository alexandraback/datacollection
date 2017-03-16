#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <map>
#include <iomanip.h>

using namespace std;

int main(int argc, const char * argv[])
{
	ifstream ifs( "Input.txt" );
    int T = 0;
    ifs >> T;
    for (int i = 0; i < T; i++) {
		int N;
		ifs >> N;
		vector<int> J;
		int sum = 0;
		for (int j = 0; j < N; j++) {
			int sj;
			ifs >> sj;
			sum+=sj;
			J.push_back(sj);
		}
		
		cout << "Case #" << i+1 << ":";
		map<pair<int, int> , double> sub;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				double a = (double)(J[k]-J[j
										   ])/sum;
				sub.insert(make_pair(make_pair(j, k), a));
			}
		}
		
		for (int j = 0; j < N; j++) {
			double t = 1;
			for (int k = 0; k < N; k++) {
				if (k != j) {
					t += sub[make_pair(j, k)];
				}
			}
			t /= N;
			
			cout << " " << setprecision(8) << t*100;
		}
		
		cout << endl;
		
	}
}

