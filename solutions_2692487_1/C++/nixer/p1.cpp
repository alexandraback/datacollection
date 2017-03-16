#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

bool myfunction (int i,int j) { return (i<j); }

int main(){
	int n;
	scanf("%d", &n);

	for(int l=0; l<n; l++){
		int a, c;
		vector<int> arr;
		scanf("%d %d", &a, &c);
		for(int i=0; i<c; i++) {
			int temp; scanf("%d", &temp);
			arr.push_back(temp);
		}
		sort(arr.begin(), arr.end());

		int mi = 99999;
		int actual = 0;
		int arm = a;
		for(int i=0; i<c; i++){
			if (arm > arr[i]) {
				arm += arr[i];
			} else {
				mi = min(actual + c - i, mi);
				
				if (arm - 1 == 0) {
					actual = 99999999;
					break;
				}

				while(arm <= arr[i]) {
					arm += arm - 1;
					actual += 1;
				}
				arm += arr[i];
			}
		}

		printf("Case #%d: %d\n", l+1, min(mi, actual));
	}
	return 0;
}