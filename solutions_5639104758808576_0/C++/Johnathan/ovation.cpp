#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t, Smax,n;
	string s;
	//int aud[1000];
	n = 0;
	cin >> t;
	while ((n++)<t){
		cin >> Smax;
		cin >> s;
		int pals = 0;
		int total = stoi(s.substr(0,1));
		for (int i = 1; i <= Smax; i++){
			int p = stoi(s.substr(i,1));
			//cout << "total " << total << " i " << i << endl;
			if ( (total < i) && (p!=0) ){
				pals += i - total;
				total += (i - total);
			}
			total += p;
		}
		cout << "Case #" << n << ": " << pals << endl;
	}
	return 0;
}