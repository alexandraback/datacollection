#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <cmath>
using namespace std;


int main(){
	string input = "B-small-attempt1.in";
	string output = "B-small.out";
	ifstream fin;
	ofstream fout;
	fin.open(input.c_str());
	fout.open(output.c_str());

	int numCases;
	fin >> numCases;
	for(int c = 0; c < numCases; c++){
		long e, r, n;
		fin >> e >> r >> n;

		vector<long> max_avail;
		vector<long> min_req;
		vector<bool> used;
		vector<long> values;

		long total = 0;

		for(int i = 0; i < n; i++){
			max_avail.push_back(e);
			min_req.push_back(0);
			used.push_back(false);

			long val;
			fin >> val;
			values.push_back(val);
		}

		for(int i = 0; i < n; i++){
			long max = -1;
			int maxi = 0;
			for(int j = 0; j < n; j++){
				if(used[j]){
					continue;
				}
				if(values[j] > max){
					max = values[j];
					maxi = j;
				}
			}

			used[maxi] = true;
			long energy_used = max_avail[maxi] - min_req[maxi];
			if(energy_used < 0){
				energy_used = 0;
			} else if(energy_used > e){
				energy_used = e;
			}

			total += energy_used * values[maxi];

			// Update the possibilities for those behind it
			for(int j = maxi + 1; j < n; j++){
				if(used[j]){
					break;
				}
				max_avail[j] = min(min_req[maxi] + (j - maxi) * r, e);
			}

			// Constraints before
			for(int j = maxi - 1; j >= 0; j--){
				if(used[j]){
					break;
				}
				min_req[j] = max_avail[maxi] - (maxi - j) * r;
				if(min_req[j] < 0){
					min_req[j] = 0;
				}
			}

		}

		fout << "Case #" << (c+1) << ": " << total << endl;

	}

	fin.close();
	fout.close();

	return 0;
}
