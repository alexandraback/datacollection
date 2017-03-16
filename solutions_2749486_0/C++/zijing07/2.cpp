#include <iostream>

using namespace std;

int T;
int X,Y;

void Solve()
{
	cin >> X >> Y;
	if(X > 0){
		for(int i = 0; i < X; i++){
			cout << "WE";
		}
	}
	else if(X < 0){
		X = -1 * X;
		for(int i = 0; i < X; i++){
			cout << "EW";
		}
	}
	if(Y > 0){
		for(int i = 0; i < Y; i++){
			cout << "SN";
		}
	}
	else if(Y < 0){
		Y = -1 * Y;
		for(int i = 0; i < Y; i++){
			cout << "NS";
		}
	}
}

int main()
{
	cin >> T;
	for(int i = 1; i <= T; i++){
		cout << "Case #" << i << ": ";
		Solve();
		cout << endl;
	}

	return 0;
}
