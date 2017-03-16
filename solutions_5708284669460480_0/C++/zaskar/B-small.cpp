#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

void test(
	int &max_ocur, int &cant_pos, int &cant_ocur,
	const string &keys, const string &word, int s, string &done, int p=0) 
{
	if (p==s) {
//		cerr<<done<<endl;
		int ocurs=0;
		size_t pos = done.find(word);
		while (pos!=string::npos) {
			cant_ocur++; ocurs++;
			pos = done.find(word,pos+1);
		}
		if (ocurs>max_ocur) max_ocur=ocurs;
		cant_pos++;
	} else {
		for(int i=0;i<keys.size();i++) { 
			done[p]=keys[i];
			test(
				max_ocur,cant_pos,cant_ocur,
				keys,word,s,done,p+1);

		}
	}
}

int main(int argc, char *argv[]) {
	ifstream fin("B-small-attempt1.in");
	ofstream fout("B-small-attempt1.out");
	int T;
	fin>>T;
	for(int I=0;I<T;I++) {
		int k,l,s;
		string keys,word;
		fin>>k>>l>>s;
		fin>>keys;
		fin>>word;
		
//		bool posible = true;
//		vector<int> nk(word.size(),0);
//		for(int i=0;i<word.size();i++) { 
//			for(int j=0;j<keys.size();j++) { 
//				if (word[i]==keys[j]) nk[i]++;
//			}
//			if (nk[i]==0) {
//				posible=false;
//				break;
//			}
//		}
		string done(s,' ');
		int max_ocur=0, cant_pos=0, cant_ocur=0;
		test(
			max_ocur, cant_pos, cant_ocur,
			keys,word,s,
			done,0);
		double val=0;
		if (cant_pos>0) val = double(max_ocur)-double(cant_ocur)/double(cant_pos);
		fout<<"Case #"<<I+1<<": "<<setprecision(15)<<val<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

