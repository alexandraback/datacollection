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


	string s;
	cin >> s;

	vector<char> result;

	for(int i = 0; i < s.size(); ++i){
		if(result.size() == 0 || s.at(i) >= result.at(0)){
			result.insert(result.begin(), s.at(i));
		}else{
			result.push_back(s.at(i));
		}
	}


	printVector(result, false);

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
