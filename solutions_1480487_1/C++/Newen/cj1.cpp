// cj1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int t;
	cin >> t;
//	cout << t << endl;
	for (int i = 0; i < t ; i++){
		int n = 0;
		cin >> n;
	//	cout << n << endl;
		int sum = 0;
		vector<int> scores;
		scores.clear();
		for(int j = 0; j< n;j++){
			int tmp = 0;
			cin >> tmp;
		//	cout << tmp << endl;
			scores.push_back(tmp);
		//	cout << scores[j] << endl;
			sum += tmp;
		}
		//cout << sum << endl;
		cout << "Case #" << i+1 << ":";
		double s = (double)sum;
	//	cout << s << endl;
		vector<double> res;
		int act = n;
		for(int j = 0; j< n;j++){
		//	cout << scores[j] << endl;
			double r = (2*(double)sum/((double)n) - (double)scores[j])*(double)100;
			res.push_back(r);
			if (r < 0.0){
				act--;
				s -= (double)scores[j];
				r = 0;
			}
		}
		for(int j = 0; j< n;j++){
			double r = (((double)sum +s)/((double)act) - (double)scores[j])*(double)100;
			if (res[j] < 0.0){
				r= +0.0;
			}
			cout << " " << r/(double)sum ;
		}
	//	cout << "     " << act << " "  << s << "  "<< sum<< endl;
		cout << endl;
	}
	return 0;
}

