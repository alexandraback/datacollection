#include <iostream>
using namespace std;
int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	
	int tc;
	cin >> tc;
	
	int a;
	int arr[1002];
	char b;
	int friends = 0;
	int cur = 0;
	
	for (int i = 0; i < tc; i++){
		cur = 0;
		friends = 0;
		cin >> a;
		for (int j = 0; j <= a; j++){
			cin >> b;
			arr[j] = (int)b - 48;
		}
		
		cur = arr[0];
		
		for (int j = 1; j <= a; j++){
			if (cur >= j){
				cur = cur + arr[j];
			} else {
				friends = friends + j - cur;
				cur = j + arr[j];
			}
		}
		
		cout << "Case #" << i + 1 << ": " << friends << endl;
		
		
	}
	
	
	
	
}
