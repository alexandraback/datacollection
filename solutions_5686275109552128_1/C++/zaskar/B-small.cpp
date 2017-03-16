#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
	ifstream fin("B-large.in");
//	ifstream fin("B-sample.in");
	ofstream fout("B-large.out");
	int T;
	fin>>T;
	for(int I=0;I<T;I++) {
		int n;
		fin>>n;
		vector<int> d(n,0);
		for(int i=0;i<n;i++) 
			fin>>d[i];
		sort(d.begin(),d.end());
		reverse(d.begin(),d.end());
		int mx=d[0]; int r=mx;
		for(int i=1;i<mx;i++) { 
			int x=i, j=0;
			while (j<n && d[j]>i) {
				int dv = d[j]/i, dr = d[j]%i;
				x+=dv; if (dr==0) x--;
				j++;
			}
			if (x<r) r=x;
		}
		fout<<"Case #"<<I+1<<": "<<r<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

