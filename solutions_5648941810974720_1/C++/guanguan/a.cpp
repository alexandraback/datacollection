#include <iostream>
#include <fstream>

using namespace std;

int nnum[15];
int charcnt[35];

int main(){
	ifstream fin("a.txt");
	ofstream fout("a_out.txt");
	int t;
	fin >> t;
	for (int aa=0; aa<t; aa++){
		string s;
		fin >> s;
		for (int i=0; i<=26; i++){
			charcnt[i]=0;
		}
		for (int i=0; i<s.length(); i++){
			charcnt[s[i]-'A']+=1;
		}
		for (int i=0; i<=9; i++){
			nnum[i] = -1;
		}
		nnum[0]=charcnt['Z'-'A'];
		nnum[6]=charcnt['X'-'A'];
		nnum[2]=charcnt['W'-'A'];
		nnum[4]=charcnt['U'-'A'];
		nnum[5]=charcnt['F'-'A']-nnum[4];
		nnum[1]=charcnt['O'-'A']-nnum[0]-nnum[2]-nnum[4];
		nnum[3]=charcnt['R'-'A']-nnum[0]-nnum[4];
		nnum[8]=charcnt['H'-'A']-nnum[3];
		nnum[9]=charcnt['I'-'A']-nnum[5]-nnum[6]-nnum[8];
		nnum[7]=charcnt['N'-'A']-nnum[9]*2-nnum[1];
		fout << "Case #" << aa+1 << ": ";
		for (int i=0; i<=9; i++){
			for (int j=0; j<nnum[i]; j++){
				fout << i;
			}
		}
		fout << endl;
	}
	fin.close();
	fout.close();
}
