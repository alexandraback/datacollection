#include <fstream>
#include <stdlib.h>
#include <set>
#include <iostream>

using namespace std;

int main(){
	ifstream fin("input.in");
	ofstream fout("output.txt");
	int t, n, s[200], min = 9001, min2 = 9001;
	double var1, avgbelow, sum;
	multiset<int>::iterator it;
	fin >> t;
	for(int i = 1;i<=t;i++){
		fout << "Case #" << i << ": ";
		fin >> n;
		sum = 0;
		for(int x = 0;x<n;x++){
			fin >> s[x];
			sum += s[x];
		}
		cout <<'\n';
		for(int x = 0;x<n;x++){
			multiset<int> ss;
			for(int y = 0;y<x;y++){
				ss.insert(s[y]);
			}
			for(int y = x+1;y<n;y++){
				ss.insert(s[y]);
			}
			it = ss.begin();
			avgbelow = 0;
			int y = 2;
			for(;it!=ss.end();y++){
				avgbelow = (avgbelow*(y-2) + *it)/(y-1);
				var1 = avgbelow-s[x];
				var1 /= (double)sum*y;
				var1 *= y-1;
				var1 += 1.0/y;
				it++;
				if((double)s[x]+var1*sum<=(double)*it){
					if(var1<0) fout << 0 << ' ';
					else fout << var1*100 << ' ';
					break;
				}
			}
			if(y>n){ if(var1<0) fout << 0 << ' ';
					else fout << var1*100 << ' '; }
			cout << '\n';
		}
		fout << '\n';
	}
	return 0;
}
