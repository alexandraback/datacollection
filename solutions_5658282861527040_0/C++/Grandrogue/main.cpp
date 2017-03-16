#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

ifstream fin("B-small-attempt0.in");
ofstream fout("out.txt");

int main() {
	int tests;
	fin>>tests;
	int a,b,k;
	for(int _t=0;_t<tests;_t++) {
		fin>>a>>b>>k;
		int ans=0;
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
				if((i&j)<k) ans++;
		fout<<"Case #"<<_t+1<<": "<<ans<<endl;
	}
	return 0;
}