#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <utility>

using namespace std;

#define PI pair<int,int>

int toDigit[15];

int exp10(int b){
	int ret = 1;
	for (int i = 0; i < b; i++){
		ret *= 10;
	}
	return ret;
}

void calcToDigit(){
	toDigit[0] = 0;
	toDigit[1] = 10;
	for (int i = 2; i <= 15; i++){
		int first = i / 2;
		int second = i - first;
		toDigit[i] = exp10(first) + exp10(second) +1;
	}
}

int main(){
	freopen("input.in","r",stdin);
	calcToDigit();
	freopen("output.out","w",stdout);
	int n = 0; 
	int t;
	cin >> t;
	while (n++ < t){
		int r,c,w;
		cin >> r >> c >> w;
			
		int ans;
		//search time for n
		if (w == 1)
			ans = r * c;
		else{
			ans = (r-1) * (c / w);
			int search = (c - w) / w + 1;
			if ((c-w) % w == 0)
				search--;
			//ceiling
			ans += search  + w;
		}


		cout << "Case " << "#" << n << ": " << ans << endl;

	}
	return 0;
}