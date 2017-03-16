#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=100;
int n,S,P,a[MAXN+10];
int f[MAXN+10][MAXN+10];
int main() {
	int cases;
	scanf("%d",&cases);
	for (int c=1;c<=cases;c++) {
		scanf("%d%d%d",&n,&S,&P);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		memset(f,0,sizeof(f));
		for (int i=1;i<=n;i++) {
			memcpy(f[i],f[i-1],sizeof(f[i-1]));
			if (a[i]%3==1) {
				int inc=a[i]/3+1>=P;
				for (int j=0;j<=S;j++)
					f[i][j]=max(f[i][j],f[i-1][j]+inc);
			}
			else if (a[i]%3==0) {
				int inc=a[i]/3>=P;
				for (int j=0;j<=S;j++)
					f[i][j]=max(f[i][j],f[i-1][j]+inc);
				if (a[i]==0) continue;
				inc=a[i]/3+1>=P;
				for (int j=1;j<=S;j++)
					f[i][j]=max(f[i][j],f[i-1][j-1]+inc);
			}
			else {
				int inc=a[i]/3+1>=P;
				for (int j=0;j<=S;j++)
					f[i][j]=max(f[i][j],f[i-1][j]+inc);
				inc=a[i]/3+2>=P;
				for (int j=1;j<=S;j++)
					f[i][j]=max(f[i][j],f[i-1][j-1]+inc);
			}
		}
		cout<<"Case #"<<c<<": "<<f[n][S]<<endl;
	}
	return 0;
}
