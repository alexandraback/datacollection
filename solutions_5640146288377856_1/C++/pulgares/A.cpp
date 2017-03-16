
#include <iostream>
using namespace std;

int main(){
	int T;
	cin >> T;
	for(int caso=1;caso<=T;caso++){
		int R, C, W, count=0;
		cin >> R >> C >> W;
		for(int r = 0; r < R; r++){
			for(int c=W-1;c<C;c+=W){
				count++;
			}
		}
		if(C%W)
			count+=W;
		else
			count+=W-1;
	

		if(count > C*R)
			cout << "ERROR" << endl;
		//cout << R << " " << C << " " << W << endl;
		cout << "Case #" << caso<<": " << count << endl;
	}
}