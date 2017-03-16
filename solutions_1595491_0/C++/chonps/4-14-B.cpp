#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<fstream>
using namespace std;
ifstream fin ("B-small-attempt0.in");
ofstream fout ("B-small-attempt0.out");
int main(){
	long i,j,k,m,n,p,s,sum;
	fin >> m;
	for (j=1;j<=m;++j){
		fin >> n >> s >> p;
		sum=0;
		for (i=1;i<=n;++i){
			fin >> k;
			switch (k%3){
				case 0 :
					if (k/3>=p) ++sum;
					else if (k/3==p-1 && s && k/3>0){
						++sum;
						--s;
					}
					break;
				case 1 :
					if (k/3>=p-1) ++sum;
					break;
				case 2 :
					if (k/3>=p-1) ++sum;
					else if (k/3==p-2 && s){
						++sum;
						--s;
					}
					break;
			}
		}
		fout << "Case #" << j << ": " << sum << endl;
	}
	return 0;
}

