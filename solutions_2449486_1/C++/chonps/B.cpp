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
ifstream fin ("B-large.in");
ofstream fout ("B-large.out");
int a[103][103],r[103],c[103];
int main(){
	int i,j,k,m,n,T,Ti;
	bool ans;
	fin >> T;
	for (Ti=1;Ti<=T;++Ti){
		fin >> n >> m;
		memset(r,0,sizeof(r));
		memset(c,0,sizeof(c));
		for (i=1;i<=n;++i)
			for (j=1;j<=m;++j){
				fin >> a[i][j];
				r[i]=max(r[i],a[i][j]);
				c[j]=max(c[j],a[i][j]);
			}
		for (ans=1,i=1;i<=n && ans;++i)
			for (j=1;j<=m && ans;++j)
				if (r[i]!=a[i][j] && c[j]!=a[i][j]) ans=0;
		fout << "Case #" << Ti << ": " << (ans?"YES":"NO") << endl;
	}
	fin.close();
	fout.close();
	return 0;
}
