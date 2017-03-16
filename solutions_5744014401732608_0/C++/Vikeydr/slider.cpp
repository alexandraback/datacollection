#include <fstream>
#include <iostream>
#include<set>
#include <algorithm>
using namespace std;


int main(){
	int t;
	ifstream in("B-small-attempt2.in");
	ofstream out("slider.out"); 
	in >> t;
	long long two[30];
	two[0] = 1;
	for (int i = 1; i <= 29;i++) two[i] = two[i-1]*2; 
	for (int tt = 0; tt < t;tt++){
		int b;
		long long m;
		in >> b >> m;
		//cout << b << ' ' << m << endl;
		out << "Case #" << tt+1 << ": ";
		if (m > two[b-2]){
			out << "IMPOSSIBLE" << endl;
			continue; 
		}
		out << "POSSIBLE" << endl;
		set<int> minus;
		minus.clear();
		long long cha = two[b-2] -m;
		//cout << b-2 << ' ' << two[b-2] << ' ' << m << ' ' << cha << endl; 
		for (int i = b-2;i >= 0;i--){
			cout << i << ' ' << cha << endl; 
			if (cha < two[i]) continue;
			cha = cha - two[i];
			minus.insert(b-i-1);
		}
		if (cha == 1) minus.insert(b);
		for (int i = 1; i <= b; i++){
			for (int j = 1; j <= b;j++){
				if (i >= j){out << "0"; continue;}
				if (i == 1 && minus.find(j) != minus.end()) {out << "0"; continue;}
				out << "1";
			}
			out << endl;
		}
	}
	in.close();
	out.close();
}
