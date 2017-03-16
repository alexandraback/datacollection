#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


long long a[20];
int n;

int was[2000001];

void Out(int m) {
 	for (int j = 0; j < 20; j++) {
 		if (m & (1 << j)) cout << a[j] << ' ';
 	}
 	cout << "\n";	

}

void Solve()
{                     
	cin >> n;
	memset(was, 0, sizeof(was));
	int i;
	for (i = 0; i < 20; i++)
		cin >> a[i];
   	for (int m = 1; m < (1 << 20); m++) {
   		int sum = 0;
   		for (int j = 0; j < n; j++) {
   			if (m & (1 << j)) 
   				sum += a[j];
   		}
   		if (was[sum] == 0) was[sum] = m;
   		else {
   			cout << "\n";
   		    Out(m);
   		    Out(was[sum]);
   		    return;
   		}
   	}
   	cout << "\nImpossible\n";

}

int main()
{
	int nt, tt;
	cin >> nt;
	for (tt = 1; tt <= nt; tt++) {
		cout << "Case #" << tt << ": ";
		Solve(); 
	}
	return 0;
}
