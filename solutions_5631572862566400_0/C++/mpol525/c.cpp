#include "cjheader.h"


using namespace std;
int currCase = 0;
int t;

/*
 * Global variables that are needed should be declared here
 */


/**********************************************************/

int checkLength(const vector<int> a, const vector<int> b){
	int size = a.size();
	bool nextSize = false;
	while(size > 1){
		for(int i = 0; i < size; ++i){
			if(i == 0){
				if(!(a[i+1] == b[a[i] - 1] || a[size - 1] == b[a[i] - 1])){
					nextSize = true;
					//cout <<"yep1" << endl;
					break;
				}

			}else if(i == size - 1){
				if(!(a[i - 1] == b[a[i] - 1] || a[0] == b[a[i] - 1])){
					nextSize = true;
					//cout <<"yep2" << endl;
					break;
				}
			}else{
				if(!(a[i - 1] == b[a[i] - 1] || a[i + 1] == b[a[i] - 1])){
					nextSize = true;
					//cout <<"yep3" << endl;
					break;
				}

			}


		}
		if(nextSize == true){
			nextSize = false;
			size--;
			//cout << "here, size = " << size << endl;
		}else{
			//cout << "here, returning size = " << size << endl;
			return size;
		}

	}
	return 1;
}

void runTestCase(){
	printf("Case #%d: ", ++currCase);

	int n;
	cin >> n;
	vector<int> bffs;
	for(int i = 0; i < n; ++i){
		int temp;
		cin >> temp;
		bffs.push_back(temp);
	}

	vector<int> arrangement;
	for(int i = 1; i < n + 1; ++i){
		arrangement.push_back(i);
	}

	int maxLength = 0;
	bool searchStillGoing = true;
	while(searchStillGoing){
		//cout << "current arrangement = ";// << endl;
		//printVector(arrangement, true);
		int tempLength = checkLength(arrangement, bffs);
		if(maxLength < tempLength){
			maxLength = tempLength;
		}
		if(maxLength == n)
			break;

		searchStillGoing = next_permutation(arrangement.begin(), arrangement.end());

	}


	printf("%d\n", maxLength);

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
