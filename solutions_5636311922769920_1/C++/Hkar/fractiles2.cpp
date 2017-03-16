#include <iostream>
using namespace std;
int main(){
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		long long k,c,s;
		cin >> k >> c >> s;
		cout << "CASE #" << t << ":";
		if(s*c < k) cout << " IMPOSSIBLE" << endl;
		else {
			long long a = 0,p = 0,i = 0;
			while(i < k){
				a = i, p = 1;
				while(p++ < c)
					a = a*k + (++i < k ? i:0);
				++i;
				cout << " " << a+1;
			}
			cout << endl;
		}
	}
}