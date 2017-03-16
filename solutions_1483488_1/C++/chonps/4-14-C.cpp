#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
ifstream fin ("C-large.in");
ofstream fout ("C-large.out");
long p[2000003];
int main(){
	long i,j,k,m,n,A,B,u,sum;
	fin >> m;
	for (j=1;j<=m;++j){
		fin >> A >> B;
		memset(p,0,8000012);
		sum=0;
		for (i=A;i<B;++i){
				for (k=1;k<=i;k*=10);
				u=i;
				for (k/=10,n=k;k>1;k/=10){
					u=(u%n)*10+u/n;
					if (u>i && u<=B && p[u]!=i){
						p[u]=i;
						++sum;
					}
				}
			}
		fout << "Case #" << j << ": " << sum << endl;
	}
	fin.close();
	fout.close();
	return 0;
}

