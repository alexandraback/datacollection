#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
	ifstream fin("B-small-attempt0.in");
	ofstream fout("B-small-attempt0.out");
	int T;
	fin>>T;
	for(int I=0;I<T;I++) {
		string s;
		fin>>s;
		int f = 0, pe = s.size();
		while(pe>0 && s[pe-1]=='+') --pe;
		while(pe>0) {
			if (s[0]=='+') {
				int pb=0;
				while (s[pb]=='+') s[pb++]='-';
				f++;
			}
			reverse(s.begin(),s.begin()+pe);
			for(int i=0;i<pe;i++) s[i] = s[i]=='+'?'-':'+';
			f++;
			while(pe>0 && s[pe-1]=='+') --pe;
		}
		fout << "Case #"<<I+1<<": "<<f<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

