#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int optimal_score(int R, int C, int W){
	return R*(C/W) + (((C%W)==0)?(W-1):(W));
}

int main(){
	int T;
	cin>>T;
	for (int i=1;i<=T;i++){
		int R,C,W;
		cin >> R >> C >> W;
//		cout << R << " " << C << " " << W << endl;
		cout<<"Case #"<<i<<": "<< optimal_score(R,C,W)<< endl;
	}
}
