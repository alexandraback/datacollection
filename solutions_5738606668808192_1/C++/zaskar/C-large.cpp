#include <iostream>
#include <fstream>
#include <cmath>
#include <set>
using namespace std;

using number = unsigned long long;

int get_div(number n) {
	if (n%2==0) return 2;
	for(number i=3, j=number(sqrt(n)); i<=j; ++i) {
		if (n%i==0) return i;
		if (j>10000) return false;
	}
	return 0;
}

bool is_jc(bool jc[], int l, number divs[]) {
	for(int b=2;b<=10;b++) { 
		number n = 0;
		for(int i=0;i<l;i++) { 
			n *= b;
			if (jc[i]) n += 1;
		}
		divs[b] = get_div(n);
		if (divs[b]==0) return false;
	}
	return true;
}

int main(int argc, char *argv[]) {
	ifstream fin("C-large.in");
	ofstream fout("C-large.out");
	int T;
	fin>>T;
	bool b[30];
	set<string> done;
	number divs[11];
	for(int I=0;I<T;I++) {
		int n,j;
		fin >> n >> j;
		fout<<"Case #"<<I+1<<":"<<endl;
		while(j) {
			b[0] = b[n-1] = 1;
			for(int i=1;i<n-1;i++) b[i] = rand()%2;
			string s;
			for(int i=0;i<n;i++) s += b[i]?"1":"0";
			if (done.count(s)) continue;
			if (is_jc(b,n,divs)) {
				done.insert(s);
				cout << s << endl;
				fout << s;
				for(int i=2;i<=10;++i) fout << " " << divs[i];
				fout << endl;
				--j;
			}
		}
	}
	fin.close();
	fout.close();
	return 0;
}

