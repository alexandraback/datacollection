#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

int main (void)
{
	ifstream in("C.in");
	ofstream out("C.out");
	cin.rdbuf(in.rdbuf());
	cout.rdbuf(out.rdbuf());
	int T;
	cin >> T;
	
	for (int t = 1; t <= T; t++)
	{
		long R, C, W;
		cin >> R >> C >> W;
		
		long ans = C/W * R + W-1 + bool(C % W > 0);
			
		cout << "Case #" << t << ": ";
		
		cout << ans << endl;
		
		
	}
	
	return 0;
	
}