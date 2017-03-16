#include<iostream>
#include<fstream>
using namespace std;

int m;
int n;
int map[1000][1000];
int mark[1000];
int todo[1000000];

int bfsre(int s){
	int d;
	for(int i=0; i<1000; i++)
		mark[i] =0;
	for(int i=0; i<3000; i++)
		todo[i] = -1;
	int idx = 1;
	int i=0;
	todo[0] = s;
	for(; i<idx; ){
		d =todo[i++];	
		for(int j=0; j<n; j++){
			if(map[d][j]==0)
				continue;
			todo[idx++] = j;
			mark[j]++;
			if(mark[j]>=2)
				return 1;
		}
	}
	return 0;
}

int main(){
	int q, p;
	ifstream ins ("ins");
	ofstream outs ("outs");
	ins >> m;
	for(int z=1; z<= m; z++){
		for(int i=0; i<1000; i++)
			for(int j=0; j<1000; j++)
				map[i][j] =0;
		ins >> n;
		for(int i=0; i<n; i++){
			ins >> p;
			for(int j=0; j<p ;j++){
				ins >> q;
				q--;
				map[i][q] = 1;
			}
		}
		int i;
		for(i=0; i<n; i++){
			if(bfsre(i))
				break;
		}
		outs << "Case #" << z << ": ";
		if(i==n)
			outs << "No" << endl;
		else
			outs << "Yes" << endl;
	}
	return 0;
}
