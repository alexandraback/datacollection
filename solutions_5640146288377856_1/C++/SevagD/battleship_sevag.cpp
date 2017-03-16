#include <iostream>
#include <fstream>
using namespace std;

int T;
int R,C,W;

int main()
{
	ifstream cin;
	cin.open("A-large.in");

	ofstream cout;
	cout.open("battleship_sevag_large.out");

	cin>>T;

	for (int t=1; t<=T; t++)
	{
		cin>>R>>C>>W;

		int ans;
		if (W==1) {
			ans = R*C;
		} else {

			ans = R*(C/W) + W - 1;
			if (C%W)
				ans++;
		}

		cout<<"Case #"<<t<<": "<<ans<<endl;
	}

	return 0;
}