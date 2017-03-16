#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
using namespace std;

ifstream fin("A.in");
ofstream fout("A.out");

int main()
{
	int testcases;
	fin >> testcases;
	for (int test = 0; test < testcases; ++test){
		double ans = 0.0;
		int k, l, s;
		string key, target;
		fin >> k >> l >> s >> key >> target;
		if (l >= target.length()){
			// character hit probability .
			map<char, double> prob;
			for (int i = 0; i < k; ++i){
				prob[key[i]] += 1;
			}
			for (map<char, double>::iterator it = prob.begin(); it != prob.end(); ++it){
				it->second = it->second / k;
			}

			//minimum.
			int overlap = l;
			for (int i = 1; i < l; ++i){
				if (target.substr(0, l - i) == target.substr(i)){
					overlap = i;
					break;
				}
			}
			//fout << overlap << endl;

			double ptarget = 1.0;
			for (int i = 0; i < l; ++i){
				ptarget *= prob[target[i]];
			}

			int mini = 0;
			if (ptarget > 0){
				mini = 1 + ((s - l) / overlap);
				//fout << mini << endl;
			}


			double expected = 0.0;
			//fout << ptarget << endl;
			expected = (s - l + 1)*ptarget;
			ans = mini - expected;
		}
		
		fout << "Case #" << test + 1 << ": " << ans << endl;
	}
	return 0;
}