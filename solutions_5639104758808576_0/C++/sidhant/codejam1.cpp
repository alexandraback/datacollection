#include <bits/stdc++.h>
#include <fstream>
using namespace std;

char A[1005];
int B[1005];

int main(){

	ifstream in("A-small-attempt1.in");
	ofstream out("upload.out");

	int t, n;
	in>>t;
	for(int big = 1; big <= t; big++){
		in>>n;
		in>>A;

		for(int i = 0; i <= n; i++)	B[i] = A[i] - '0';

		int tot = 0, ans = 0;
		for(int i = 0; i <= n; i++){
			for(int j = 1; j <= B[i]; j++){
				if(i > tot){
					ans += (i - tot);
					tot += (i - tot);
				}
				tot++;
			}
		}

		out<<"Case #"<<big<<": "<<ans<<endl;
	}
	
	return 0;
}