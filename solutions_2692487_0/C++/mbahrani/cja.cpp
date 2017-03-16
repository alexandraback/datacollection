#include<iostream>
#include<algorithm>
#define MN (100 + 5)

using namespace std;

int arr[MN], num, a;

int solve(int ind, int size);

int main(){
	int T, ans;
	cin >> T;
	for(int tt = 0; tt < T; tt++){
		ans = 0;
		cin >> a >> num;
		for(int i = 0; i < num; i++){
			cin >> arr[i];
		}
		
		if(a == 1){
			cout << "Case #" << tt + 1 << ": " << num << endl;
			continue;
		}
		sort(arr, arr+num);
		cout << "Case #" << tt + 1 << ": " << solve(0, a) << endl;
	}
	return 0;
}

int solve(int ind, int size){
	if(ind >= num)
		return 0;
	if(arr[ind] < size){
		return solve(ind + 1, size + arr[ind]);
	}
	else{
		return min(num - ind, solve(ind, size + size - 1) + 1);
	}
}
