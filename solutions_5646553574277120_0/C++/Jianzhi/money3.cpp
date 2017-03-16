#include <iostream>
#include <cstring>
#include <set>
using namespace std;

int tc;
int c, d, v;
int temp;
set<int> s;
int last = 1;
int ans = 0;

int arr[10000];
int coins[10000];

void putcoin(int a){
	
	s.clear();
	for (int i = 0; i <= v; i++){
		if (arr[i] == -1) continue;
		if (i + a > v) continue;
		s.insert(i + a);
	}
	
	for (set<int>::iterator it = s.begin(); it != s.end(); it++){
		arr[*it] = 1;
	}
	s.clear();
	
}

int main(){
	
	freopen("C-small-attempt2.in", "r", stdin);
	freopen("C-small-attempt2.out", "w", stdout);
	
	cin >> tc;
	
	for (int i = 0; i < tc; i++){
		cin >> c >> d >> v;
		memset(arr, -1, sizeof(arr));
		memset(coins, -1, sizeof(coins));
		arr[0] = 1;
		last = 100000000;
		ans = 0;
		
		for (int j = 0; j < d; j++){
			cin >> temp;
			putcoin(temp);
			coins[temp] = 1;
		}
		
		for (int j = 0; j <= v; j++){
			if (arr[j] == -1) {
				last = j;
				break;
			}
		}
		
		
		while (last <= v){
			putcoin(last);
			ans = ans + 1;
			last = 100000000;
			for (int j = 0; j <= v; j++){
				if (arr[j] == -1) {
					last = j;
					break;
				}
			}	
		}
		
		
		cout << "Case #" << i + 1 << ": " <<  ans << endl;
		
		
	}
	
	
	
	
	
	
}
