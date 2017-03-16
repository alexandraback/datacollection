#include<stdio.h>
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
typedef long long int ll;
using namespace std;
int main()
{
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	int i;
	int cases;
	cin >> cases;
	int ans;
	int r;
	int c;
	int w;
	for(int i1 = 1;i1 <= cases;i1++) {
		cin >> r >> c >> w;
		int t1 = c/w;
		if(c % w != 0) {
			t1++;
		}
		ans = t1 * r + (w-1);
		
		printf("Case #%d: %d\n", i1, ans);
	}
	return 0;
}
