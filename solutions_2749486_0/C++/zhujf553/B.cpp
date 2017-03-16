#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main()
{
	int T;
	freopen("B.in","r", stdin);
	freopen("B.out" ,"w", stdout);
	cin >> T;
	for(int tt = 1 ; tt <= T ; tt++)
	{
		int x, y;
		cin >> x >> y;
		string sx, sy;
		if(x > 0) sx = "WE"; else sx = "EW", x = -x;
		if(y > 0) sy = "SN"; else sy = "NS", y = -y;
		cout << "Case #" << tt << ": ";
		for(int i = 1 ; i <= x ; i++) cout << sx;
		for(int i = 1 ; i <= y ; i++) cout << sy;
		cout << endl;
	}
	return 0;
}
