#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void main(){
	ifstream inp("E:\\Note\\input.txt");
	cin.rdbuf(inp.rdbuf());
	ofstream outp("E:\\Note\\output.txt");
	cout.rdbuf(outp.rdbuf());
	int t;
	cin >> t;
	for (int cas = 0; cas < t; cas++){
		long long a, b, k;
		cin >> a >> b >> k;
		long long ans = 0;
		for (int i = 0; i < a; i++)
			for (int j = 0; j < b; j++)
				if ( (i&j) < k)
					ans++;
		cout << "Case #" << cas + 1 << ": " << ans << endl;
	}
}