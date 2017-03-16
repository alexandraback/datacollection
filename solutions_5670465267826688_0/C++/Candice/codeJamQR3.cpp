//============================================================================
// Name        : codeJamQR3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;
int t, l, x;
int a[5][5]={{0,0,0,0,0},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};
int d[10000];

int toint(char ch){
	switch(ch){
		case '1':
			return 1;
			break;
		case 'i':
			return 2;
			break;
		case 'j':
			return 3;
			break;
		case 'k':
			return 4;
		    break;
		default:
			return 0;
			break;
	}
	return 0;
}

int calcul(int c, int b){
	int p = c>0?c:-c;
	int q = b>0?b:-b;
	int u = c>0?1:-1;
	int v = b>0?1:-1;
	return (u*v*a[p][q]);
}
int main() {
	ifstream in("input");
	ofstream out("output");
	in>>t;
	string s;
	for(int p = 0; p < t; p++){
		in>>l>>x;
		in>>s;
		int pi,pj,pk,ki,kj,kk;
		d[0] = toint(s[0]);
		for(int j = 1; j<l; j++){
			d[j] = calcul(d[j-1],toint(s[j]));
		}
		bool fi,fj,fk;
		fi = false;
		int t = 1;
		ki = 0;
		for(int i =0; i<min(x,4); i++){
			for(int j = 0; j<l; j++){
				if (calcul(t,d[j]) ==2){
					fi = true;
					pi = j;
				}
				if (fi) break;
			}
			if (fi) break;
			t = calcul(t,d[l-1]);
			ki++;
		}
		if (!fi)
			out<<"Case #"<<p+1<<": NO"<<'\n';
		else{
			pj = pi;
			int now = 1;
			kj = ki;
			fj = false;
			while((!fj) && kj < min(x,ki+4)){
				pj++;
				if(pj == l){
					pj = 0;
					kj++;
				}
				now = calcul(now,toint(s[pj]));
				if (now == 3){
					fj = true;
				}
			}
			if (!fj || kj>=min(x,ki+4))
				out<<"Case #"<<p+1<<": NO"<<'\n';
			else{
				pk = pj;
				int now = 1;
				kk = kj;
				fk = false;
				while(!fk && kk < min(x,kj+4)){
					pk++;
					if(pk == l){
						pk = 0;
						kk++;
					}
					now = calcul(now,toint(s[pk]));
					if (now ==4){
						fk = true;
					}
				}
				if (!fk || kk>=min(x,kj+4))
						out<<"Case #"<<p+1<<": NO"<<'\n';
				else{
					int now = 1;
					int k = pk+1;
					while (k < l){
						now = calcul(now,toint(s[k]));
						k++;
					}
					int xx = kk+1;
					while (xx < x){
						now = calcul(now,d[l-1]);
						xx++;
					}
					if (now == 1){
						out<<"Case #"<<p+1<<": YES"<<'\n';
					}
					else
						out<<"Case #"<<p+1<<": NO"<<'\n';
				}
			}
		}
	}
	return 0;
}
