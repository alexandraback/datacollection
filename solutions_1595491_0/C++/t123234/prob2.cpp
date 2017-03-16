#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	ofstream outfile;
	outfile.open("outfile.txt");
	
	int t, s, n, p, ti, y;
	int score[100];
	cin >> t;
	for (int i=0; i<t; i++) {
		cin >> n >> s >> p;
		y = 0;
		for (int j=0; j<n; j++) {
			cin >> ti;
			if(ti>=(3*p-2)) y++;
			else if(ti>=(3*p-4) && ti>=2 && ti<=28 && s>0){
				y++;
				s--;
			}
		}
		cout << "Case #"<<(i+1)<<": "<<y<<endl;
	}
	
	
	return 0;
}