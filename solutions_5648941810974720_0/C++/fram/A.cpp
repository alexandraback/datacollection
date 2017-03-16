#include <iostream>
#include <vector>
#include <string>
using namespace std;

string s;
int q[300];
int a[10];

void solve(){
	for(int i='A'; i<='Z'; i++) q[i] = 0;
	for(int i=0; i<10; i++) a[i] = 0;
	
	cin >> s;
	for(char c:s) q[(int)c]++;
	
	a[0] = q['Z'];
	a[2] = q['W'];
	a[4] = q['U'];
	a[6] = q['X'];
	a[8] = q['G'];
	a[3] = q['T'] - a[2] - a[8];
	a[5] = q['F'] - a[4];
	a[7] = q['S'] - a[6];
	a[9] = q['I'] - a[5] - a[6] - a[8];
	a[1] = q['N'] - a[7] - 2*a[9];
	
	for(int i=0; i<10; i++) for(int j=0; j<a[i]; j++) cout << i;
	cout << endl;
}

int main(){
	int t; cin >> t;
	for(int i=1; i<=t; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
