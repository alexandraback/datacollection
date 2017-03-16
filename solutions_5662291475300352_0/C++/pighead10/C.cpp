#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

typedef long long int bignum;
typedef long double ld;

int
gcd(int a, int b)
{
	int c;
	while (a != 0) {
		c = a; a = b%a;  b = c;
	}
	return b;
}

int main(){
	ifstream fin("C-small-1-attempt4.in");
	ofstream fout("output.txt");

	int T;
	fin >> T;
	for (int t = 1; t <= T; t++){
		int n;
		fin >> n;
		int totalh = 0;
		vector<pair<int, int>> hikers;
		for (int i = 0; i < n; i++){
			int d, h, m;
			fin >> d >> h >> m;
			totalh += h;
			for (int j = 0; j < h; j++){
				hikers.push_back(make_pair(d, m+j));
			}
		}
		string output;
		if (totalh == 1){
			output = "0";
		}else if(totalh == 2){
			if (hikers[0].second == hikers[1].second){
				/*pair<int, int> mind = hikers[0].first < hikers[1].first ? hikers[0] : hikers[1];
				pair<int, int> maxd = mind == hikers[0] ? hikers[1] : hikers[0];*/
				output = "0";
			}
			else{
				pair<int, int> mind = hikers[0].first < hikers[1].first ? hikers[0] : hikers[1];
				pair<int, int> maxd = mind == hikers[0] ? hikers[1] : hikers[0];
				pair<int, int> mins = hikers[0].second < hikers[1].second ? hikers[0] : hikers[1];
				pair<int, int> maxs = mind == hikers[0] ? hikers[1] : hikers[0];

				ld t1 = (ld)mind.second * ((ld)(360.0 - mind.first) / 360.0);
				ld d2 = (ld)(t1/maxd.second) * 360.0;
				ld t2 = (ld)maxd.second * ((ld)(360.0 - maxd.first)/360.0);
				ld d1 = (ld)(t2 / mind.second) * 360.0;
				if (d2 >= (360 + (360 - maxd.first))-0.001){
					output = "1";
				}
				else if (d1 >= ((360 - mind.first) + 360) - 0.001){
					output = "1";
				}
				else{
					output = "0";
				}
			}
		}
		else{
			output = "N/A";
		}
		fout << "Case #" << t << ": " << output << endl;
	}
	fout.close();
	return 0;
}