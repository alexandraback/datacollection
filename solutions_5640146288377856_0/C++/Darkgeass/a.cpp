#include <iostream>
#include <vector>

using namespace std;

int r,c,w;

int main(){
	int t;
	cin >> t;
	for(int cass = 1; cass <= t; ++cass){
		cin >> r >> c >> w;
		int a = c/w;
		int b = w-1;
		if(c%w) b++;
		cout << "Case #" << cass << ": " << r*(a+b) << endl;
	}
}