#include <bits/stdc++.h>
#define MAXM  2500
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie
using namespace std;

int cubeta[MAXM+2];

int T;
int N;
int act;

int main(){
	optimizar_io(0);
	cin>>T;
	for(int caso = 1;  caso <= T; caso++){
		cin>>N;
		for(int i =1 ; i <= MAXM ; i++)
			cubeta[i] = 0;
		for(int i =1 ; i < 2*N; i++){
			for(int i =1 ; i <= N; i++){
				cin>>act;
				cubeta[act]++;
			}
		}
		cout<<"Case #"<<caso<<":";
		for(int i =1 ; i <= MAXM; i++){
			if(cubeta[i]&1){				
				cout<<" "<<i;
			}
		}
		cout<<"\n";
	}
	return 0;
}