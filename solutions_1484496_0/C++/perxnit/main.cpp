#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <map>
#include <iomanip.h>
#include <set>
#include <algorithm>
#include "comb.h"

using namespace std;

int main(int argc, const char * argv[])
{
	ifstream ifs( "Input.txt" );
    int T = 0;
    ifs >> T;
    for (int i = 0; i < T; i++) {
		int N;
		ifs >> N;
		vector<long long> S;
		for (int k = 0; k < N; k++) {
			long long d;
			ifs >> d;
			S.push_back(d);
		}
		sort(S.begin(), S.end());
		
		map<long long, vector<long long> > maf;
		vector<long long> ans1, ans2;
		bool found = false;
		for (int k = 1; k <= N; k++) {
			do{
				vector<long long> f;
				long long sum = 0;
				for (int a = 0; a < k; a++) {
					f.push_back(S[a]);
					sum+=S[a];
				}
				map<long long, vector<long long> >::iterator it = maf.find(sum);
				if (maf.end() != it) {
					found = true;
					ans1 = it->second;
					ans2 = f;
				}else
					maf.insert(make_pair(sum, f));
				
			}while(boost::next_combination(S.begin(), S.begin()+k, S.end()) && !found);
		}
		
		cout << "Case #"<<i+1<<":" << endl;
		if (found) {
			for (int j = 0; j < ans1.size(); j++) {
				cout << ans1[j] << " ";
			}
			cout << endl;
			for (int j = 0; j < ans2.size(); j++) {
				cout << ans2[j] << " ";
			}
			cout << endl;
		}else 
			cout << "Impossible" << endl;
	}
}

