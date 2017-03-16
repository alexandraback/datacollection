//code compiled under g++ / c++11
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;
int solve_case(int R,int C,int W);

int main(void){
    int case_all;

    cin >> case_all;

    for(int i=1;i <= case_all;i++){
		int r,c,w;

		cin >> r;
		cin >> c;
		cin >> w;

        cout << "Case #" << i << ": "
				<< solve_case(r,c,w) << endl;
	}
}

int solve_case(int R,int C,int W){
	
	int rowX = C / W;
	int total = rowX * R;
	
	if(C % W == 0){
		total += (W - 1);
	}else{
		total += W;
	}

	return total;
}

