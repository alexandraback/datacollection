#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

int m, s, p;
int g[100][2];

void getg(int d, int *a){
	int r=d/3;
	if(d==0){
		if(0 >= p)
			a[0]=1;
	}
	else if(d==1){
		if(1 >=p )
			a[0]=1;
	}
	else{
	if(d-r*3==0){
		if(r>= p)
			a[0]=1;
		if(r+1 >=p)
			a[1]=1;
	}
	else if(d-r*3==1){
		if(r+1 >=p)
			a[0]=a[1]=1;
	}
	else{
		if(r+1 >=p)
			a[0]=1;
		if(r+2 >=p)
			a[1]=1;
	}
	}
}

int cmp(const void *a, const void *b){
	int* c = (int *)b;
	int* d = (int *)a;
	c++;
	d++;
	return (*c - *d);
}

int main(){
	ifstream ins;
	ofstream outs;
	ins.open("B-small-attempt0.in");
	outs.open("out");
	int n;
	int d;
	int count;
	ins >> n;
	int mark[100];
	for(int i=0; i<n; i++){
		ins >> m >> s >> p;		
		for(int j=0; j<m ; j++){
			ins >> d; 
			g[j][0]=g[j][1]=0;
			mark[j]=0;
			getg(d, g[j]);
		}
		qsort(g, m, sizeof(int)*2, cmp);
		count =0; 
		for(int j=0; j<m; j++){
			if(s){
				if(g[j][0] < g[j][1]){
					mark[j]=1;
					s--;
				}
			}
		}
		if(s!=0){
			for(int j=0; j<m; j++){
				if(s && mark[j]==0){
					mark[j]=1;	
					s--;
				}
			}
		}
		for(int j=0; j<m ;j++){
			if(mark[j])
				count += g[j][1];
			else
				count += g[j][0];
		}
		outs << "Case #" << i+1 << ": ";
		outs << count << endl;
	}
	return 0;
}
