#include <fstream>
#include <iostream>
using namespace std;

ifstream f("C-small-1-attempt2.in"); ofstream g("C-small-1-attempt2.out");

int i, j, n, m, r, k, x, y, t;
int v[10000];
int rez[10];

int main(){
	f>>t;
	f>>r>>n>>m>>k;
	g<<"Case #1:\n";
	for (i=1; i<=r; i++){
		for (j=1; j<10; j++) rez[j]=0;
		for (j=1; j<=k; j++){
			f>>x; y=0;
			for (y=0; x%2==0; x/=2) y++;
			rez[2]=max(rez[2], y);
			for (y=0; x%3==0; x/=3) y++;
			rez[3]=max(rez[3], y);
			for (y=0; x%5==0; x/=5, y++);
			rez[5]=max(rez[5], y);
		}
		if (rez[2]+rez[3]+rez[4]+rez[5]!=n){
			rez[2]-=2;
			rez[4]++;
		}
		if (rez[2]+rez[3]+rez[4]+rez[5]!=n){
			rez[2]-=2;
			rez[4]++;
		}
		if (rez[2]+rez[3]+rez[4]+rez[5]!=n){
			rez[2]-=2;
			rez[4]++;
		}
		
		int totalOutput=0;
		for (j=1; j<=9; j++){
			for (int jj=1; jj<=rez[j]; jj++) {
				if (totalOutput++ <n) g<<j;
			}
		}
		g<<"\n";
	}
}
