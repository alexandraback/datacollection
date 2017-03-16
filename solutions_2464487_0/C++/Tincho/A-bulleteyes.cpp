#include <iostream>

using namespace std;

int main(){
	
	unsigned long long T, r, t, k=1,cant;
	
	cin >> T;
	
	while (k<=T){
		cant=0;
		
		cin >> r >> t;
		
		unsigned long long aUsar;
		
		aUsar = 2*r + 1;
		while (t >= aUsar){
			t -= aUsar;
			++cant;
			
			aUsar += 4;
		}
		
		cout << "Case #" << k << ": " << cant << endl;
		++k;
	}
	
	return 0;
}
