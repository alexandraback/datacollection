#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <iomanip>
#define FOR(i, n) for(int i=0; i<n; i++)
#define MAX(a, b) ((a>b) ? a : b)
#define err 0.000000001
//#include "all.h"
using namespace std;

int main(){
	string file = "in.in";
	freopen(file.c_str(), "r", stdin);
	int t;
	cin >> t;
	ofstream of;
	of.open("out.txt");

	int n;
	double x;


	FOR(ti, t){
		cin >> n;
		vector<int> j(n);
		FOR(i, n) cin >> j[i];
		x = 0;

		FOR(i, n) x+= j[i];

		of << "Case #"<< ti + 1 << ": ";

		double l, h, mid, total;
		FOR(i, n) {
			l = 0; h = 1;
			while (l + err < h){
				mid = (l + h)/2;
				total = 0;
				FOR(k, n) {
					total += MAX(0, (j[i] - j[k])/x + mid);
				}
				if (total > 1) h = mid;
				else if (total < 1) l = mid;
				else {
					h = mid;
					break;
				}
			}
			if (h <= err) h = 0;

			of << setprecision(8) << h*100 << " ";
		}
		of << endl;

	}
	of.close();
	return 0;
}
