#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <limits> 
#include <set>
#include <utility>
#include <algorithm>
#include <iterator>

using namespace std;

int main(){
	int T;
	cin >> T;
	for(int t = 1; t < T + 1; t++){
		int R, C, W;
		cin >> R >> C >> W;
		int temp = (C / W);
		//cout << temp;
		int total = temp * R;
		total += W;
		if(C%W == 0) total -= 1;
		
		cout << "Case #" << t << ": " << total << "\n";
	}
}
