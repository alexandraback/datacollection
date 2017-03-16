#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>

using namespace std;

ifstream fin("B.in");
ofstream fout("B.out");

int main()
{
	int T;
	fin >> T;
	for(int caseID=1; caseID<=T; caseID++) {
		fout << "Case #" << caseID << ": ";
		int N;
		fin >> N;
		vector<int> a(N);
		vector<int> b(N);
		for(int i=0; i<N; i++) {
			fin >> a[i] >> b[i];
		}
		int left = N;
		int stars = 0;
		int steps = 0;
		vector<int> level(N, 0);
		while(left>0) {
			// find 0->2 
			int b02 = -1;
			for(int i=0; i<N; i++) {
				if(level[i]==0 && stars >= b[i]) {
					if(b02==-1) 
						b02 = i;
					else if (b[i]<b[b02])
						b02 = i;
				}
			}
			if(b02 != -1) {
				level[b02] = 2;
				stars += 2;
				left--;
				steps++;
				continue;
			}
			// find 1->2 
			int b12 = -1;
			for(int i=0; i<N; i++) {
				if(level[i]==1 && stars >= b[i]) {
					if(b12==-1) 
						b12 = i;
					else if (b[i]<b[b12])
						b12 = i;
				}
			}
			if(b12 != -1) {
				level[b12] = 2;
				stars += 1;
				left--;
				steps++;
				continue;
			}
			// find 0->1
			int b01 = -1;
			for(int i=0; i<N; i++) {
				if(level[i]==0 && stars >= a[i]) {
					if(b01==-1) 
						b01 = i;
					else if (b[i]> b[b01])
						b01 = i;
				}
			}
			if(b01 != -1) {
				level[b01] = 1;
				stars += 1;
				steps++;
				continue;
			}
			break;
		}
		if(left > 0)
			fout << "Too Bad" << endl;
		else
			fout << steps << endl;
	}

	return 0;
}
