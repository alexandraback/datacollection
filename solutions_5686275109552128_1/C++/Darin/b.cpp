#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int max(int a, int b){
	return a>b? a:b;
}
int main(){
	freopen("B-large.in","r",stdin);
	freopen("B-large.txt","w",stdout);

	int tests;
	cin >> tests;
	for (int test=1; test<=tests; test++){
		int n;
		cin >> n;
		int cake[n];
		int max_cake = 0;
		for (int i=0; i<n; i++){
			cin >> cake[i];
			max_cake = max(max_cake, cake[i]);
		}
		int ans = 210000000;
		for (int i=1; i<=max_cake; i++){
			int temp = i;
			for (int j=0; j<n; j++){
				temp += (cake[j]-1) / i;
			}
			if (temp < ans)
				ans = temp;
		}
		cout << "Case #" << test << ": " << ans << endl;

	}
}