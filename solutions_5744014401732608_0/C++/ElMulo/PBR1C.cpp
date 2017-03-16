#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<long long> vll;

#define forn(i,n) for(int i=0;i<(int)n;i++)

long long power(int base, int exponente){
	if (exponente==0) return 1;
	return (long long)base*power(base,exponente-1);
}

ifstream fin("B-small-attempt1.in");
ofstream fout("B-small-attempt1.out");

int main(){
	int T,B;
	long long M;

	fin >> T;
	forn(t,T){
		fin >> B >> M;
		if(M>power(2,B-2)){
			fout << "Case #" << t+1 << ": IMPOSSIBLE" << endl;
			continue;
		}

		fout << "Case #" << t+1 << ": POSSIBLE" << endl;
		bool oneon;
		if(M==power(2,B-2)) oneon=true;
		forn(i,B){
			forn(j,B-1){
				fout << (j>i);
			}
			if(i==0 && oneon==true){
				fout << 1 << endl;
				M--;
				continue;
			} else if(i==0 && oneon==false){
				fout << 0 << endl;
				continue;
			}

			if(M%2==0){
				fout << 0;
			}else{
				fout << 1;
				M--;
			}
			M/=2;
			fout << endl;
		}
	}

	return 0;
}
