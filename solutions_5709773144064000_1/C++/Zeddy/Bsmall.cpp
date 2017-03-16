#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w+", stdout);
	int t;
    cin >> t;

	
	cout.precision(20);


	double C;
	double F;
	double X;
	double rate;

	double cookiesLeft;
	double curTime;
	double prevTime;

	double bestTime;

	for(int ti = 0; ti < t; ti++){
		
		cout << "Case #" << (ti+1) << ": ";
		
		cin >> C;
		cin >> F;
		cin >> X;

		cookiesLeft = X - C;
		curTime = 0;
		prevTime = 0;
		rate = 2;
		
		bestTime = X/rate;

		if (C < X){
			while(1){
				bestTime = X/rate + curTime;
				curTime = curTime + C/rate;
				if(curTime >= bestTime){
					break;
				}
				if(cookiesLeft/rate > X/(rate + F)){
					rate = rate + F;
				}
				else{
					break;
				}
			
			}
		}


		cout << bestTime;
		cout << endl;
	}

	fclose(stdout);
	fclose(stdin);
	return 0;
}