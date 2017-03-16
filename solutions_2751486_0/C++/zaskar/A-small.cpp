#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

bool vocal(const char c) {
	return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
	
}

int main(int argc, char *argv[]) {
	ifstream fin("A-small-attempt0.in");
	ofstream fout("A-small-attempt0.out");
	int T;
	fin>>T;
	for(int I=0;I<T;I++) {
		static char *s=new char[1000000]; 
		static bool *b=new bool[1000000]; 
		int n,r=0;
		fin>>s>>n;
		int l=strlen(s), i0,cc=0,c0;
		bool vm=false;
		for(int i=0;i<l;i++) { 
			b[i]=false;
			if (vocal(s[i])) {
				cc=0;
			} else {
				cc++;
				if (cc>=n) {
					b[i]=true;
				}
			}
		}
		b[l]=true;
		int bl=-1,bll=-10; 
		for(int i=0;i<=l;i++) { 
			if (b[i]) {
				if (bll!=-10) {
					int fs=(bl+1)-(n-1);
					int fe=i-bl;
					r+=fs*fe;
				}
				bll=bl;
				bl=i;
			}
		}
		fout<<"Case #"<<I+1<<": "<<r<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

