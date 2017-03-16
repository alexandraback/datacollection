#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	int n;
	cin >> n;
	for (int c = 0; c < n; ++c){
		int m;
		cin >> m;
		string s;
		cin >> s;
		int sum = 0;
		int cont = 0;
		for (int i = 0; i <= m; ++i){
			int a = s[i] - '0';
			if (sum >= i) sum += a;
			else{
				int x = i - sum;
				sum += a+x;
				cont +=x;
			}
		}
		cout << "Case #" << c+1 << ": " << cont << endl;
	}
}
