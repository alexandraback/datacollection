#include <bits/stdc++.h>
using namespace std;

#include <fstream>

int A[1005];

int main(){

	ifstream in("B-small-attempt0.in");
	ofstream out("upload.out");

	int t, ans, cost, temp, MAXM = 0, n;
	in>>t;

	for(int big = 1; big <= t; big++){
		ans = INT_MAX;
		in>>n;
		for(int i = 0; i < n; i++){
			in>>A[i];
			MAXM = max(MAXM, A[i]);
		}


		for(int i = 1; i <= MAXM; i++){
			cost = i;
			for(int j = 0; j < n; j++){
				temp = A[j]/i;
				if((A[j] % i) != 0)	temp++;
				temp--;
				cost += temp;
			}
			ans = min(ans, cost);
		}

		out<<"Case #"<<big<<": "<<ans<<endl;
	}
	
	return 0;
}