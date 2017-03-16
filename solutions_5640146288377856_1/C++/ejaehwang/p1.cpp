#include <iostream>

using namespace std;


void solve(int t);
int main(){
	int testCase;

	cin >> testCase;

	for(int i=1; i<=testCase; i++)
		solve(i);
}
void solve(int t){

	int result=0;
	int R, C, W;
	cin >> R >> C >> W;

	int divv;

	divv = C/W;

	if( R != 1){
		result = (R-1)*divv;
	}


	if( C-(divv*W) == 0 )
		result += divv+W-1;
	else
		result += divv+W;




	cout << "Case #" << t << ": " << result << endl;
}