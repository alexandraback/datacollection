#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
	ifstream fin("A-small-attempt4.in");
	ofstream fout("A-small-attempt4.out");
	int T;
	fin>>T;
	fin.ignore();
	for(int I=0;I<T;I++) {
		string num;
		getline(fin,num);
		int r=1;
		while (num!="1") {
			{
				int i=num.size()-1;
				if (i>0) {
					int m=10;
					for(int j=1;i-j>=j;j++) {
						if (num[i-j]!='0') {
							r+=(num[i-j]-'0')*m; 
							m*=10; num[i-j]='0';
						}
					}
				}
			}
			{
				int i=num.size()-1;
				if (i>0 && num[i]!='0') {
					while(num[i]!='1') { r++; num[i]--; }
					string onum=num;
					reverse(num.begin(),num.end());
					if (onum<=num) num=onum; 
					else { r++; continue; }
				}
			}
			{
				int i=num.size()-1;
				do {
					if (num[i]=='0') num[i]='9';
					else num[i]--;
				} while (num[i--]=='9');
				r++;
				while (num[0]=='0') num=num.substr(1);
			}
		}
		fout<<"Case #"<<I+1<<": "<<r<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

