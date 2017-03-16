#include <iostream>

using namespace std;


int solve(int x, int y)
{
	if (x >= 0)
	       	for (int i = 0; i < x; i++)
			cout <<"WE";
	else
		for (int i = 0; i < -x; i++)
			cout <<"EW";
	if (y >= 0)
	       	for (int i = 0; i < y; i++)
			cout <<"SN";
	else
		for (int i = 0; i < -y; i++)
			cout <<"NS";
}
int solve(int x0, int y0, int x, int y, int step)
{
	
}
int main() {
	int T, x, y;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> x >> y;
		cout << "Case #" << i << ": ";
	       	solve(x, y);
		cout << endl;
	}
}
