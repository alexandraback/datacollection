#include <iostream>
#include <fstream>

using namespace std;


int main(){
	ifstream fin("b.txt");
	ofstream fout("b_bf_out.txt");
	int t;
	fin >> t;
	for (int aa=0; aa<t; aa++){
		string s1,s2;
		int ans1 = 1000;
		int ans2 = 1000;
		int mindiff = 1000;
		fin >> s1 >> s2;
		int len = s1.length();
		if (s1.length()==1){
			s1 = "00" + s1;
		}
		else if (s1.length()==2){
			s1 = "0" + s1;
		}
		if (s2.length()==1){
			s2 = "00" + s2;
		}
		else if (s2.length()==2){
			s2 = "0" + s2;
		}
		for (int i=0; i<=999; i++){
			for (int j=0; j<=999; j++){
				int a3 = i % 10;
				int a2 = (i / 10) % 10;
				int a1 = (i / 100) % 10;
				int b3 = j % 10;
				int b2 = (j / 10) % 10;
				int b1 = (j / 100) % 10;
				if (s1[0]!='?' && s1[0]-'0'!=a1) continue;
				if (s1[1]!='?' && s1[1]-'0'!=a2) continue;
				if (s1[2]!='?' && s1[2]-'0'!=a3) continue;
				if (s2[0]!='?' && s2[0]-'0'!=b1) continue;
				if (s2[1]!='?' && s2[1]-'0'!=b2) continue;
				if (s2[2]!='?' && s2[2]-'0'!=b3) continue;
				int diff = 0;
				if (i >= j){
					diff = i - j;
				}
				else{
					diff = j - i;
				}
				if (diff < mindiff){
					mindiff = diff;
					ans1 = i;
					ans2 = j;
				}
				else if (diff == mindiff){
					if (i < ans1){
						ans1 = i;
						ans2 = j;
					}
					else if (i == ans1){
						if (j < ans2){
							ans1 = i;
							ans2 = j;
						}
					}
				}
			}
		}
		fout << "Case #" << aa+1 << ": ";
		int act = 0;
		if (ans1 < 10){
			act = 1;
		}
		else if (ans1 < 100){
			act = 2;
		}
		else if (ans1 < 1000){
			act = 3;
		}
		for (int i=0; i<len-act; i++){
			fout << "0";
		}
		fout << ans1 << " ";
		if (ans2 < 10){
			act = 1;
		}
		else if (ans2 < 100){
			act = 2;
		}
		else if (ans2 < 1000){
			act = 3;
		}
		for (int i=0; i<len-act; i++){
			fout << "0";
		}
		fout << ans2 << endl;
	}
	fin.close();
	fout.close();
}
