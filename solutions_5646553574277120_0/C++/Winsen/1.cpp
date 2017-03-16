#include<cstdio>
#include<cstring> 
#include<algorithm>
#include<fstream>
using namespace std;
int n,m,T;
int a[100],f[4000];
int dp(){
	memset(f,0,sizeof(f));
	f[0]=1;
	for(int i=1;i<=n;++i)
		for(int j=m;j>=a[i];--j)
			f[j]|=f[j-a[i]];
	for(int i=1;i<=m;++i)
		if(!f[i])
			return i;
	return m+1;
}
int main(){
	ifstream fin("C-small-attempt0.in");
	ofstream fout("output.txt");
	fin >> T;	
	for(int tt=1;tt<=T;++tt){
		int x,t;
		fin >> x >> n >> m;
		t=n;
		for(int i=1;i<=n;++i) fin >> a[i];
		while(1){
			x=dp();
			//fout << x;
			if(x>m)break;
			a[++n]=x;
		}
		fout << "Case #" << tt << ": " << n-t << endl;
	}
	return 0;
}
