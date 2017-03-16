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

	for (i=1;i<= T;i++){
		string L;
		int n;
		cin >> L >> n;
		long long count = 0;

		//vector<int> con_interval;

		int con = 0;
		//bool first_n = false;
		int pre_string = 0;

		for (j=0;j<L.size();j++){
			pre_string++;
			if (L[j] != 'a' && L[j] != 'e' && L[j] != 'i' && L[j] != 'o' && L[j] != 'u'){
				con++;
			}else{
				//con_interval.push_back(con);
				if (con >= n){
					//cout << L.substr(j-con,j) << endl;
					count += (pre_string -1 -con+1)*( L.size() - (j-1) + con-n);
					//count += (con - n) * ( L.size() - (j-1));
					for (k=0;k< con-n;k++){
						count += ( L.size() - (j-1) + con-n -(k+1));
					}
					pre_string = n-1 + 1;
				}
				con = 0;
			}
		}
		
		if (con >= n){
					count += (pre_string-con+1)*( 1 + con - n );
					for (k=0;k<con-n;k++){
						count += 1 + con-n - (k+1);
					}
					//count += (con - n) * ( 1 );

					pre_string = n-1;
		}
		
		
		cout <<"Case #"<<i<<": " << count <<endl;
	}

/*
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
*/


	return 0;
}
