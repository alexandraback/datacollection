#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>
#include <cstdio>

using namespace std;

int main(){
	int tcase;
	cin >> tcase;
	
	for(size_t casen = 0; casen < tcase; ++casen)
	{
		double C, F, X;
		cin >> C >> F >> X;
		double cur = 2, cur_time = 0, best = X / 2.;
		while (cur_time <= X / 2.) {
			cur_time += C / cur;
			cur += F;
			if (best > cur_time + X / cur) 
				best = cur_time + X / cur;
			else break;
		}
		cout << "Case #" << casen + 1 << ": ";
		printf("%.7lf\n", best);
		
	}
	

	return 0;
}
