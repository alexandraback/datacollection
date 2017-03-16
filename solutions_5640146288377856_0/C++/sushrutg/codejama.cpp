#include <math.h>
#include <iostream>
using namespace std;
int main() {
 	int T;
	cin >> T;
	for (int i = 1; i<=T; i++)
	{
		long long int r, c, w;
		long long int res = 0;
		cin >> r >> c >> w;
  		long long wid = c / w *r;
 		wid =wid+( w - 1);
		if (c%w != 0)
			wid++;
		cout<<"Case #"<<i<<": "<<wid << endl;
	}
 
	return 0;
}
