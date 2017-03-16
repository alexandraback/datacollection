#include <fstream>
#include <iostream>
#include <set>
#include <string.h>
#include <algorithm>
using namespace std;


int main(){
	int t;
	ifstream in("C-small-attempt1.in");
	ofstream out("fashion.out"); 
	in >> t;
	for (int tt = 0; tt < t;tt++){
		int jean,p,s,kl;
		in >> jean >> p >> s >> kl;
		int jp[100],js[100],sp[100];
		for (int i = 0; i < 100;i++){
			jp[i] = 0;
			js[i] = 0;
			sp[i] = 0;
		}
		int day = 0;
		out << "Case #" << tt+1 << ": ";
		string res = "";
		for (int k = 0;k < s;k++)
			for (int j = 0; j < p; j++)
				for (int i = 0; i < jean;i++){
					if (jp[i*10+j] < kl && js[i*10+k] <kl && sp[j*10+k] < kl){
						day++;
						jp[i*10+j] ++;
						js[i*10+k] ++;
						sp[j*10+k] ++;
						res = res + char(i+48) + char(j+48) + char(k+48)+ ' ';
						//cout << i << ' ' << j << ' ' << k << ' ' << day << endl; 
						//cout << res << endl;
					}
				}
		out << day << endl;
		cout << res << endl;
		for (int i = 0 ;i < res.length();i++){
			if (res[i] == ' ') out << endl; else out << (int(res[i])-48)+1 << ' ';
		}		
	}
	in.close();
	out.close();
}
