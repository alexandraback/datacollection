#include <fstream>

using namespace std;

int main() {
	int test;
	ifstream fin;
	ofstream fout;
	fin.open("B-small-attempt0.in");
	fout.open("gcj2.out");

	fin>>test;
	fin.get();
	int i;
	int n,s,p,p1,p2,j,t;
	int lim1,lim2;
	int count;
	for (i = 0; i<test;i++) {
		fout<<"Case #"<<i+1<<": ";
		fin>>n>>s>>p;
		p1 = ((p-1>0)?(p-1):0);
		p2 = ((p-2>0)?(p-2):0);
		lim1 = p + p1 + p1;
		lim2 = p + p2 + p2;
		count = 0;
		for (j = 0; j<n;j++) {
			fin>>t;
			if (t >= lim1) {
				count++;
			} else if (t >= lim2) {
				if (s>0) {
					s--;
					count++;
				}
			}
		}
		fout<<count<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}