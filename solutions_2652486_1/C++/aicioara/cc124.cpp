#include <fstream>
#include <iostream>
using namespace std;

ifstream f("C-small-2-attempt1.in"); ofstream g("C-small-2-attempt1.out");

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
			for (y=0; x%7==0; x/=7, y++);
			rez[7]=max(rez[7], y);
		}
		
		while (rez[2]+rez[3]+rez[4]+rez[5]+rez[6]+rez[7]+rez[8]>n){
			if (rez[4]>0 && rez[2]>0) {
				rez[8]++;
				rez[2]--; 
				rez[4]--;
			}
			else if (rez[3]>0 && rez[2]>0){
				rez[6]++;
				rez[2]--;
				rez[3]--;
			}
			else if (rez[2]>0){
				rez [4]++;
				rez[2]--;
				rez[2]--;
			}
			else break;
		}
		
		while (rez[2]+rez[3]+rez[4]+rez[5]+rez[6]+rez[7]+rez[8]<n) rez[2]++;
		
		int asds = 0;
		for (j=1; j<=9; j++){
			for (int jj=1; jj<=rez[j]; jj++) {
				if (asds++<n) g<<j;
			}
		}
		g<<"\n";
	}
}
