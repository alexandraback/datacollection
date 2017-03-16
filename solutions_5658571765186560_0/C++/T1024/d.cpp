#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

void win(int t)
{
	cout << "Case #" << t << ": GABRIEL\n";
}

void loss(int t)
{
	cout << "Case #" << t << ": RICHARD\n";
}

int main() {
	int t;
	int x, r, c;
	
	cin >> t;
	for(int tt=1; tt<=t; ++tt)
	{
		cin >> x >> r >> c;

		if(4 < x || ((r*c)%x != 0) || (min(r,c) < (x+1)/2)) {
			loss(tt);
			continue;
		}
		
		if(x <= 2) {
			win(tt);
			continue;
		}
		
		//cout << x << " " << r << " " << c << "\n";
		if(x == 3) {
			if(min(r,c) == 3 && r%2 == 1 && c%2 == 1)
				loss(tt);
			else
				win(tt);
			continue;
		}
		
		loss(tt);
	}

	return 0;
}
