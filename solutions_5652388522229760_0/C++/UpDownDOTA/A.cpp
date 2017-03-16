#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("A-small-attempt1.in");
ofstream fout("output.txt");

int flag[10];
int r;

void update(int n) {
	while (n) {
		if (flag[n%10]==0) {
			flag[n%10]=1;
			r--;
		}
		n/=10;
	}
}

int main() {
	int n;
	fin>>n;
	int index=0;
	while (n--) {
		index++;
		fout<<"Case #"<<index<<": ";
		int i;
		fin>>i;
		for (int k = 0; k < 10; k++)
			flag[k]=0;
		r=10;
		int j;
		for (j = 1; j < 10000; j++) {
			update(i*j);
			if (!r) {
				fout<<i*j;
				break;
			}
		}
		if (j==10000)
			fout<<"INSOMNIA";
		fout<<endl;
	}
}