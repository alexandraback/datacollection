#include "cjheader.h"


using namespace std;
int currCase = 0;
int t;

/*
 * Global variables that are needed should be declared here
 */


/**********************************************************/

void runTestCase(){
	printf("Case #%d: ", ++currCase);

	int n;
	cin >> n;

	int heightCount[2501];

	for(int i = 0; i < 2501; ++i){
		heightCount[i] = 0;
	}

	for(int i = 0; i < (2*n-1)*n; ++i){
		int temp;

		cin >> temp;
		heightCount[temp]++;
	}


	vector<int> soln;
	for(int i = 0; i < 2501; ++i){
		if((heightCount[i] % 2) != 0){
			soln.push_back(i);
		}
	}


	sort(soln.begin(), soln.end());

	for(int i = 0; i < soln.size(); ++i){
		cout << soln[i];
		if(i != soln.size() - 1)
			cout << " ";
		else
			cout << "\n";
	}

	return;
}

void setUp(){

	return;
}

int main(){
	setUp();

	int t;


	assert(scanf("%d", &t) == 1);

	while(t > 0){

		runTestCase();
		t--;
	}

	return 0;
}
