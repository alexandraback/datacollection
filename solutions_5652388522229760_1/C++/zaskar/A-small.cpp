#include <iostream>
#include <fstream>
using namespace std;

using number = unsigned long long;

int main(int argc, char *argv[]) {
	ifstream fin("A-large.in");
	ofstream fout("A-large.out");
	int T;
	fin>>T;
	for(int I=0;I<T;I++) {
		bool seen[10] = {false,false,false,false,false,false,false,false,false,false};
		int nseen = 0;
		number n;
		fin>>n;
		if (n==0) {
			fout<<"Case #"<<I+1<<": INSOMNIA"<<endl;
		} else {
			number x = n;
			while (true) {
				number r = x;
				while (r) {
					int d = r%10; r/=10;
					if (!seen[d]) { seen[d]=true; nseen++; }
				}
				if (nseen==10) break;
				x += n;
			}
			fout<<"Case #"<<I+1<<": "<<x<<endl;
		}
	}
	fin.close();
	fout.close();
	return 0;
}

