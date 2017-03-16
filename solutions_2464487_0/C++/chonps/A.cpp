#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<string>
using namespace std;
ifstream fin ("A-small-attempt0.in");
ofstream fout ("A-small-attempt0.out");
long double q,r,s;
long long R,S,i,Q;
int main(){
	int T,TI;
	fin >> T;
	for (TI=1;TI<=T;++TI){
		fin >> R >> S;
		r=R*1.0;
		s=S*1.0;
		q=sqrt((2.0*r-1.0)*(2.0*r-1.0)+8.0*s);
		q-=2.0*r-1.0;
		q/=4.0;
		Q=(long long)(q);
		for (i=max(1LL,Q-10LL);i<=Q+10LL;++i){
			q=2.0*(i*1.0)*(i*1.0)+(2.0*r-1.0)*(i*1.0);
			if (q>s) break;
		}
		fout << "Case #" << TI << ": " << (i-1LL) << endl;
	}
	return 0;
}
