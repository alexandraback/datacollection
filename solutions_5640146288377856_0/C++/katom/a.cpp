#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <map>

using namespace std;

int answer;
int r;
int c;
int w;

void solve(int case_no){
	//input
    cin >> r >> c >> w;
	

	//calculate
    answer = 0;
    if((c % w) == 0){
        answer = r  * (c / w) + (w - 1);
    } else{
        answer = r * (c / w) + (w - 1) + 1;
    }

	//output
	cout << "Case #" << case_no << ": " << answer << endl;
}

int main(){
	int test_case_no;
	cin >> test_case_no;
	for (int i = 0; i < test_case_no; i++){
		solve(i + 1);
	}
	return 0;
}
