#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	ifstream fin("B-small-attempt4.in");
	ofstream fout("B-small-attempt4.out");
	int T,n;
	fin>>T;
	int c[1000][2];
	bool done[1000][2];
	for(int I=0;I<T;I++) {
		int ndone=0,p=0,e=0;
		fin>>n;
		for(int i=0;i<n;i++) { 
			fin>>c[i][0]>>c[i][1];
			if (c[i][0]>c[i][1]) cerr<<"AA";
			done[i][0]=done[i][1]=false;
		}
		while (ndone<n) {
			p++;
			int min2=-1,min1=-1,min0=-1,aux0=-1;
			for(int i=0;i<n;i++) { 
				if (!done[i][1] && c[i][1]<=e) {
					if (!done[i][0]) {
						min2=i; break; 
					} else {
						min1=i;
					}
				}
				if (!done[i][0] && c[i][0]<=e) { 
					if (aux0==-1 || c[i][1]>aux0) {
						min0=i;
						aux0=c[i][1];
					}
				}
			}
			if (min2!=-1) {
				e+=2; done[min2][0]=done[min2][1]=true;
				ndone++;
			} else if (min1!=-1) {
				e++; done[min1][1]=true;
				ndone++;
			} else if (min0!=-1) {
				e++; done[min0][0]=true;
			} else break;
		}
		if (ndone==n)
			fout<<"Case #"<<I+1<<": "<<p<<endl;
		else
			fout<<"Case #"<<I+1<<": Too Bad"<<endl;
	}
	
	
	
	fin.close();
	fout.close();
	return 0;
}

