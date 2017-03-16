// 2012Round!A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <set>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include "windows.h"


using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	size_t T;
	cin >> T;
//	Sleep(10*1000);
	for (size_t i = 0; i < T; ++i) {
		size_t N;
		cin >> N;
		vector<size_t> scores;
		size_t total = 0;
		for (size_t j = 0; j < N; ++j) {
			size_t score;
			cin >> score;
			scores.push_back(score);
			total += score;
		}
		cout << "Case #" << i+1 <<": " ;
		for (size_t j = 0; j < N; ++j) {
			double max = 1.0;
			double min = 0;
			double mid = (max+min)/2;
			const size_t index = j;
			double lastMid = mid;
			const double delta = ((double)1)/100000000000;
			while(1) {
				if (mid > max || mid < min) {
					cout << "Met an exception" << std::endl;
					break;
				}
				bool possibe = false;
				
				const double myscore = scores[index] + mid * total;
				vector<size_t> less;
				size_t count = 0;
				bool equals = false;
				for (vector<size_t>::iterator itr = scores.begin(); itr != scores.end(); ++itr) {
					if (count == index) {
						++count;
						continue;
					}
					if (*itr < myscore)
						less.push_back(*itr);
					else {
						double diff = myscore - *itr;
						if (diff < delta)
							equals = true;
					}
					++count;
				}
				double remaining  = (1 - mid) * total;
				
				
				for (vector<size_t>::iterator itr = less.begin(); itr != less.end(); ++itr) {
					double lessdiff = myscore - *itr;
					if (delta > lessdiff)
						continue;
					if (remaining > lessdiff)
						remaining -= lessdiff;
					else {
						possibe = true;
						break;
					}
				}
				if (true == equals && remaining < delta)
					possibe = true;

				lastMid = mid;
				double diff = 0;
				if (possibe) {
					max = mid;
					mid = (max+min)/2;
					diff = lastMid - mid;
				} else {
					min = mid;
					mid = (max+min)/2;
					diff = mid - lastMid;
				}
				
				if ( diff < delta)
					break;
			}
			cout << std::fixed << setprecision(6) << lastMid * 100 << " ";
		}
		std::cout << std::endl;
	}



}