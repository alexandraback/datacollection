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
	int r, c, w;
	cin >> r;
	cin >> c;
	cin >> w;

	int firstHit = 0;
	int toSink;
	int lastCol = 0;
	for(int i = w; i <= c; i += w){
		firstHit++;
		lastCol = i;
	}

	toSink = (w - 1);
	if(c - lastCol > 0)
		toSink++;
	//cout << "lastCOl = " << lastCol << endl;
	//cout << "firstHit = " << firstHit << ", toSink = " << toSink << endl;

	int score = firstHit + toSink;
	printf("%d\n", score);

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
