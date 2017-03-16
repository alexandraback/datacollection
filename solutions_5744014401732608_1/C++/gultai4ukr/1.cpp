#include <bits/stdc++.h>

#define wait system("pause") 
#define LLI long long int
#define LD long double
#define PB push_back
#define MP make_pair
#define FORi(i, a, b) for(int i = a; i < b ; ++i)
#define FORd(i, a, b) for(int i = a; i > b ; --i)
 
using namespace std;

ifstream fin("in.txt");
ofstream fout("out.txt");
	 
const LLI mod = 1e9+7;

int main(){
	int t,b,index,tmp;
	LLI m,p;
	bool a[50][50];
	fin >> t;
	FORi(q,0,t){
		fout << "Case #" << q+1 << ": ";
		//...solution starts...
		
		fin >> b >> m;
		
		if (m>(1ll<<(b-2))){
			fout << "IMPOSSIBLE" << endl;
			continue;
		}
		
		FORi(i,0,b)
			FORi(j,0,b)
				a[i][j] = 0;
				
		p = 1;
		index = b - 1;
		a[0][index] = 1;
		while (p+p<=m){
			p += p;
			index--;
			a[0][index] = 1;
			FORd(i,b-1,index)
				a[index][i] = 1;
		}
		
		m -= p;
		p>>=1;
		if (m)
			a[0][--index] = 1;
		tmp = index + 1;
		while (m){
			if (m>=p){
				a[index][tmp] = 1;
				m -= p;
			}
			p>>=1;
			tmp++;
		}
		
		fout << "POSSIBLE" << endl;
		FORi(i,0,b){
			FORi(j,0,b)
				fout << a[i][j];
			fout << endl;
		}
		
		//...solution ends...
	}
	fin.close();
	fout.close();
}
