#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

void main()	{
	char fi[300] = "D:\\Study\\Topcoder\\GCJ\\A-small-practice-Safety in Numbers5.in";	//1	smal
	char ouci[300] = {"results_A_small_Safety in Numbers.txt"};//large

	ifstream ifs(fi);
	if(!ifs) {
		cout << "File open error!" << endl;
		return;
	}
	ofstream ou(ouci);  
    if(!ou)	{
		cout << "file open error!\n";
		return;
	}

	int T;
	ifs >> T;

	for(int i = 0; i < T; i++)	{
		ou << "Case #" << i + 1 << ": ";
		cout << "Case #" << i + 1 << ": ";
		
		long double N; 
		long double X = 0;;		
		ifs >> N;
		vector<long double> points;
		for(int j = 0; j < N; j++)	{
			long double temp;
			ifs >> temp;
			X += temp;
			points.push_back(temp);
		}

		long double total = 2 * X;
		long double weak = N;
		for(int j = 0; j < N; j++)	{
			if(points[j] >= total / N)	{
				total -= points[j];
				weak--;
			}
		}
		
		long double m;
		for(int j = 0; j < N; j++)	{
			if(points[j] >= 2 * X / N)	{
			m = ((long double)2 * X / N - points[j]) / X;
			ou << setprecision(8) << max(m * 100, (long double)0.0) << " ";//max(m * 100, 0.0)
			cout << setprecision(8) << max(m * 100, (long double)0.0) << " ";//max(m * 100, 0.0)
			}
			else	{
				m = ((long double)total / weak - points[j]) / X;
			ou << setprecision(8) << max(m * 100, (long double)0.0) << " ";//max(m * 100, 0.0)
			cout << setprecision(8) << max(m * 100, (long double)0.0) << " ";//max(m * 100, 0.0)
			}
		}

			ou << endl;
			cout << endl;
		
		
	}
}