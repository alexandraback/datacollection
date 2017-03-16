#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("D-small-attempt0.in");
ofstream fout("output.txt");

int main() {
	int n;
	int k, c, s;
	long long power[100];

	fin>>n;
	for (int i = 0; i < n; i++) {
		fout<<"Case #"<<i+1<<":";
		fin>>k>>c>>s;
		if (s*c < k) {
			fout<<" IMPOSSIBLE\n";
			continue;
		}
		power[0] = 1;
		for (int j = 1; j < c; j++)
			power[j] = power[j-1]*k;

		for (int a1 = 0; a1 < k; a1 += c) {
			long long tmp = 0;
			for (int a2 = 0; a2 < c; a2++)
				if (a1+a2 <= k-1) {
					tmp += power[a2]*(a1+a2);
					//fout<<"{"<<a1<<" "<<a2<<"}";
				}
			fout<<" "<<tmp+1;
		}
		fout<<endl;
	}
}