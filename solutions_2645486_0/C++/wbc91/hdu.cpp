#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdio>
using namespace std;
int comp(const void*a, const void*b){
	return *(int*)b-*(int*)a;
}
void main(){
	ifstream cin("B-small-attempt0.in");
	ofstream cout("2013gcj_RA_B.out");
	int T,E,R,N;
	int v[20];
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> E >> R >> N;
		for(int j = 0; j < N; j++){
			cin >> v[j];
		}
		qsort(v,N,sizeof(int),comp);
		int sum = 0;
		int remainer = E;
		for(int j = 0; j < N; j++){
			sum += remainer*v[j];
			remainer = R>E?E:R;
		}
		cout << "Case #" << i+1 << ": "<<sum <<endl;
	}
	system("pause");
}