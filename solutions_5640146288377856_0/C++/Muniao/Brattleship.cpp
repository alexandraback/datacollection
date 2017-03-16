#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <cmath>
#include <set>
using namespace std;

int main()
{
	int T, r, c, w, I=0;  
	scanf ("%d", &T); 
	while (I++ < T)
	{
		scanf ("%d%d%d", &r, &c, &w); 
		int ans = r * (c / w) + w - 1; 
		if (c % w != 0) ans ++; 
		printf ("Case #%d: %d\n", I, ans); 
	}
}