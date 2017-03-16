#include<iostream>
using namespace std;

int runtime, n, num[2000];
string str;

bool check(int init){
	for (int i = 0; i <= n; i++)
		if (init >= i) init += num[i];
		else return false;
	return true;
}
int main(){
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	cin >> runtime;
	for (int run = 1; run <= runtime; run++){
		cin >> n;
		cin >> str;
		for (int i = 0; i <= n; i++) 
			num[i] = (int)(str[i] - '0');
		int l = 0, r = n;
		while (l != r){
			int mid = (l + r) / 2;
			if (check(mid)) r = mid;
			else l = mid + 1;
		}
		cout << "Case #" << run << ": " << l << endl;
	}
} 
