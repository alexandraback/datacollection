#include <iostream>
using namespace std;
char res[555]={0};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t, x, y;
	cin >> t;
	for (int i=1; i<=t; ++i)
	{
		cin >> x >> y;
		cout << "Case #" << i << ": ";

		if (x>0)
			for (int j=0; j<x; ++j)
				cout << "WE";
		if (x<0)
			for (int j=0; j<-x; ++j)
				cout << "EW";
		if (y>0)
			for (int j=0; j<y; ++j)
				cout << "SN";
		if (y<0)
			for (int j=0; j<-y; ++j)
				cout << "NS";
		cout << "\n";
	}
	return 0;
}