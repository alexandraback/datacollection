#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	int t,ile,wyn,n,j,a_l,i;
	cin >> t;
	for(i=0; i<t; i++){
		cin >> n >> s;
		ile = 0;
		wyn = 0;
		for(j=0; j<=n; j++){
			a_l = (int)s[j]-(int)'0';
			if(ile < j && a_l > 0) {
				wyn += j-ile;
				ile += j-ile;
			}
			ile += a_l;
		}
		cout << "Case #" << i+1 << ": " << wyn << "\n";  
	}
	return 0;
}
