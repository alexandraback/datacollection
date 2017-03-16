#include <bits/stdc++.h>

using namespace std;

int main(){
	int t, m;
	cin >> t;
	for (m = 0; m < t; m++){
		cout << "Case #" << m+1 << ":";
		int n;
		cin >> n;
		n = (n*2 -1) * n;
		int arr[n+1], i;
		arr[n] = 0;
		for (i = 0; i < n; i++){
			cin >> arr[i];
		}
		sort(arr,arr+i);
		for(i = 1 ; i <= n; i++){
			if (arr[i] == arr[i-1]){
				arr[i] = 0;
				arr[i-1] = 0;
				continue;
			}
			if (arr[i-1])
				cout <<" "<< arr[i-1];
		}
		cout << endl;
	}
	return 0;
}