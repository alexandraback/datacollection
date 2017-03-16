#include <vector>
#include <queue>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
bool mat[50][50];
void p(long long int b, long long int m);
long long int maximo(int b);

int main(){
	ifstream fin("B-small-attempt2.in");
	ofstream fout("testrespuesta.txt");
	for(int i=2; i<7; i++){
		cout<<maximo(i)<<"\n";
	}
	long int t;
	fin>>t;
	int b;
	for(long int j=0; j<t; j++){
	fin>>b;
	//bool mat[b][b];
	for(int i=0; i<b; i++){
			for(int y=0; y<b; y++){
				mat[y][i]=0;
			}
	}
	int m;
	fin>>m;
	if(m>maximo(b)){
		fout<<"Case #"<<j+1<<": IMPOSSIBLE\n";
	}else{
		fout<<"Case #"<<j+1<<": POSSIBLE\n";	
		p(b,m);
	for(int a=0; a<b; a++){
		for(int c=0; c<b; c++){
		fout<<mat[a][c];
		}		
		fout<<"\n";
	}
	}
	}
}

void p(long long int b, long long int m){
		mat[0][b-1]=1;
		m--;
		if(m>0){
			mat[1][b-1]=1;
			mat[0][1]=1;
			m--;
		}
		long int y=3;
		while(m>0){
			long long int maximun=maximo(y);
			if(maximun>m){
				//HECHO
				mat[y-1][b-1]=1;
				p(y,m);
				m-=m;
			}else{
				mat[y-1][b-1]=1;
				p(y,maximun);
				m-=maximun;
			}
			y++;
		}
}

long long int maximo(int b){
	if(b==2) return 1;
	if(b==3) return 2;
	long long int suma=2;
	for(int y=3; y<b; y++){
		suma+=maximo(y);
	}
	return suma;
}








// int('a');
// string.at(i);
/*

long long int myPow(long long int x, long long int p)
{
  if (p == 0) return 1;
  if (p == 1) return x;

  long long int tmp = myPow(x, p/2);
  if (p%2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}
*/
