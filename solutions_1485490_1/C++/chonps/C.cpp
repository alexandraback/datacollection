#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
ifstream fin ("C-large.in");
ofstream fout ("C-large.out");
long A[103],B[103],lasta[103],lastb[103],ena[103],enb[103];
long long a[103],b[103],f[103][103];
long long as,bs,mIn;
int main(){
	long i,j,k,m,n,T,t,u,v;
	fin >> T;
	for (t=1;t<=T;++t){
		fin >> n >> m;
		memset(ena,0,412);
		memset(enb,0,412);
		memset(f,0,84872);
		for (i=1;i<=n;++i){
			fin >> a[i] >> A[i];
			if (A[i]==A[i-1]){
				a[i-1]+=a[i];
				--i;
				--n;
			}
			else{
				lasta[i]=ena[A[i]];
				ena[A[i]]=i;
			}
		}
		for (i=1;i<=m;++i){
			fin >> b[i] >> B[i];
			if (B[i]==B[i-1]){
				b[i-1]+=b[i];
				--i;
				--m;
			}
			else{
				lastb[i]=enb[B[i]];
				enb[B[i]]=i;
			}
		}
		for (i=1;i<=n;++i)
			for (j=1;j<=m;++j){
				if (A[i]!=B[j]) f[i][j]=f[i-1][j]>f[i][j-1]?f[i-1][j]:f[i][j-1];
				else{
					as=a[i];
					bs=b[j];
					u=i;
					v=j;
					while (u>0 && v>0){
						mIn=as<bs?as:bs;
						f[i][j]=f[i][j]>f[u-1][v-1]+mIn?f[i][j]:f[u-1][v-1]+mIn;
						if (as<bs){
							u=lasta[u];
							as+=a[u];
						}
						else{
							v=lastb[v];
							bs+=b[v];
						}
					}
				}
			}
		fout << "Case #" << t << ": " << f[n][m] << endl;
	}
	fin.close();
	fout.close();
	return 0;
}
