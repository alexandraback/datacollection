#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

const double eps = 1e-9;
const int inf = 1e9 + 23;

const int size = 40 * 1000;

int x, y;
int d, sum;
char ans[size];

void go (int a){
	int h = d - a;
	if (a == d){
		assert((x == 0) && (y == 0));
		return;
	}
	if (abs(x) >= abs(y)){
		if (x > 0){
			ans[a] = 'E';
			x -= h;
		}
		else{
			ans[a] = 'W';
			x += h;
		}
	}
	else{
		if (y > 0){
			ans[a] = 'N';
			y -= h;
		}
		else{
			ans[a] = 'S';
			y += h;
		}
	}
	return go(a + 1);
}

int main (void){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	
	for (int it = 1; it <= t; it++){
		printf("Case #%d: ", it);

		cin >> x >> y;
		
		sum = 0;
		d = 0;
		while (true){
			d++;
			sum += d;
			if ((abs(x) + abs(y) <= sum) && ((sum - x - y) % 2 == 0))
				break;
		}
		go(0);
		reverse(ans, ans + d);
		for (int i = 0; i < d; i++)
			printf("%c", ans[i]);
		printf("\n");
	}

	return 0;
}