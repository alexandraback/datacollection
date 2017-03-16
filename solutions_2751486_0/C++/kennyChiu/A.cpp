#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int T;
	cin >> T;
	
	int i, j, k;

	for (i=1;i<=T;i++){
		string L;
		int n;
		cin >> L >> n;
		int count = 0;
		
		for (j=0; j< L.size()-n+1;j++){
			int con = 0;
			bool reach_min = false;
			for (k=j; k<L.size()-(n-con)+1 && !reach_min ;k++){
			
					if (L[k] != 'a' && L[k] != 'e' && L[k] != 'i' && L[k] != 'o' && L[k] != 'u'){
						con++;
					}else{
						con = 0;
					}
					if (con >= n){
						reach_min = true;
						//cout << L.substr(j,k) << endl;
						count = count + L.size() - k;
					}
			}
		}


		cout <<"Case #"<<i<<": " << count <<endl;
	}



	return 0;
}
