#include <bits/stdc++.h>
 
#define LLI long long int
#define LD long double
#define PB push_back
#define MP make_pair
#define FORi(i, a, b) for(int i = a; i < b ; ++i)
#define FORd(i, a, b) for(int i = a; i > b ; --i)
 
using namespace std;

ifstream fin("in.txt");
ofstream fout("out.txt");
	 
const LLI mod = 1e16;

int main(){
	int t,k,c,s;
	LLI k_c;
	fin >> t;
	FORi(i,0,t){
		fin >> k >> c >> s;
		fout << "Case #" << i+1 << ":";
		k_c = 1;
		FORi(i,0,c)
			k_c *= k;
		FORi(i,0,s)
			fout << " " << k_c/k*i + 1;
		fout << endl;
	}
	fin.close();
	fout.close();
}
