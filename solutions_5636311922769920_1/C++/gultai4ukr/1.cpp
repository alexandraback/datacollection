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
	LLI ind;
	fin >> t;
	FORi(i,0,t){
		fin >> k >> c >> s;
		fout << "Case #" << i+1 << ":";
		if (s<k/c+bool(k%c)){
			fout << " IMPOSSIBLE" << endl;
			continue;
		}
		for (int i=0; i<k; i+=c){
			ind = 1;
			FORi(j,i+1,i+c+1){
				ind = (ind-1)*k + (j>k?k:j);
				//cout << ind << " " << j << endl;
			}
			fout << " " << ind;
		}
		fout << endl;
	}
	fin.close();
	fout.close();
}
