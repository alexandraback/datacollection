#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, min, max;
	int dat[5];
	cin >> n;
	dat[0]=1;
	dat[1]=4;
	dat[2]=9;
	dat[3]=121;
	dat[4]=484;
	for (int i=1; i<=n; i++){
		cin >> min >> max;
		for (int j=4; j>=0; j--){
			if (max>=dat[j]){
				max=j;
				break;
			}
		}
		for (int j=0; j<=4; j++){
			if (min<=dat[j]){
				min=j;
				break;
			}
		}
		
		if (max-min+1<0){
			cout << "Case #" << i << ": " << 0 << endl;
		}
		else {
			cout << "Case #" << i << ": " << max-min+1 << endl;
		}
		
	}
	return 0;
}
