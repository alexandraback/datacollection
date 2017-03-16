#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;




int main() {
	ifstream in("B-large.in");
	ofstream out;
	out.open("b.output");
	int t; 
	in >> t;
	for(int z = 0; z < t; z++) {
		int d;
		in >> d;
		vector<int> v;
		vector<int> time;
		int max = 0;
		for(int i = 0; i < d; i++){
			int temp;
			in >> temp;
			if (temp > max)
				max = temp;
			v.push_back(temp);
		}
		int res = 100000;
		for(int i = 1; i <= max; i++) {
			int times = i;
			for(int j = 0; j < d; j++){
				if(v[j] > i){
					times += (int)ceil((double)v[j]/i);
					times--;
				}	
			}
			cout << i << ": " << times << endl;
			if(times < res)
				res = times;
		}
		//cout << (int)
		out << "Case #" << z+1 << ": " << res << endl;
	}

	out.close();
	return 0;
}
