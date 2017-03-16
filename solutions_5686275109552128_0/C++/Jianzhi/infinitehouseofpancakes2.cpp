#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

double arr[1001];

int main(){
	
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	
	int tc;
	cin >> tc;
	
	int a, b;
	int maxi = 1000000000;
	int cur = 0;
	
	for (int i = 0; i < tc; i++){
		maxi = 1000000000;
		cin >> a;
		for (int j = 0; j < a; j++){
			cin >> arr[j];
		}
		
		sort(arr, arr + a);
		
		for (int j = 1000; j > 0; j--){
			cur = 0;
			for (int k = a - 1; arr[k] > j; k--){
				cur = cur + ceil((arr[k]/j)) - 1;
			}
			maxi = min(maxi, cur + j);
		}
		
		cout << "Case #" << i + 1 << ": " << maxi << endl;
	}
	
	
	
}
