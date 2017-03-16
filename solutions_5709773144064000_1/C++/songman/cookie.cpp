#include <iostream>
#include <iomanip>
using namespace std;

void solveCase(int caseNum){
	double cookiesPerFarm, farmCookiesPerSecond, goal;
	cin >> cookiesPerFarm >> farmCookiesPerSecond >> goal;


	int limit = goal / cookiesPerFarm;

	double bestTime = goal / 2;

	double currentCPS = 2;
	double currentTime = 0;

	for(int i=1;i<=limit;i++){

		currentTime+= cookiesPerFarm / currentCPS;	
		currentCPS += farmCookiesPerSecond;

		double newTime = currentTime + goal / currentCPS;
		 
		if(newTime < bestTime)
			bestTime = newTime;
	}

	cout << "Case #" << caseNum << ": " << fixed << setprecision(7) << bestTime << endl;
}

int main(){
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		solveCase(i+1);
	}	
	return 0;
}