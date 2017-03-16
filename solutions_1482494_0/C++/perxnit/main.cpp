#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

int main(int argc, const char * argv[])
{
	ifstream ifs( "Input.txt" );
    int T = 0;
    ifs >> T;
    for (int i = 0; i < T; i++) {
		int N;
		ifs >> N;
		vector<pair<int,int> > req;
		vector<pair<int,int> > clear;
		for (int j = 0; j < N; j++) {
			int r1, r2;
			ifs >> r1 >> r2;
			req.push_back(make_pair(r1, r2));
			clear.push_back(make_pair(0, 0));
		}
		
		//sort(req.begin(), req.end());
		
		int star = 0;
		int step = 0;
		bool tb = false;
		while (1) {
			bool nomore = true;
			for (int j = 0; j < N; j++) {
				if (!clear[j].second) {
					if (req[j].second <= star) {
						step++;
						if (clear[j].first) {
							star++;
						}else {
							star+=2;
						}
						clear[j].second = 1;
						clear[j].first = 1;
						nomore = false;
					}
				}
			}
			
			if (star == 2*N) {
				break;
			}
			
			if (!nomore) {
				continue;
			}
			
			for (int j = 0; j < N; j++) {
				if (!clear[j].first) {
					if (req[j].first <= star) {
						step++;
						star+=1;
						clear[j].first = 1;
						nomore = false;
						break;
					}
				}
			}
			
			if (nomore) {
				tb = true;
				break;
			}

		}
		
		if (tb) {
			cout << "Case #" << i+1 << ": " << "Too Bad" << endl;
		}else {
			cout << "Case #" << i+1 << ": " << step << endl;
		}
	}
}

