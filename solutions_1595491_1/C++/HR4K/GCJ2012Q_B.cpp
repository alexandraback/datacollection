#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

vector< vector< int > > lambda[31];

void partTable(){
	vector<int> a(3), b(3);
	for(int i=0; i<=30; i++){
		if(i <= 1){
			a[0] = i;
			a[1] = a[2] = 0;
			lambda[i].push_back(a);
		}else if(i%3 == 0){
			if(i>=30){
				a[0] = a[1] = a[2] = i/3;
				lambda[i].push_back(a);
				lambda[i-1].push_back(a);
				lambda[i-1][0][2]--;
				continue;
			}
			a[0] = a[1] = a[2] = i/3;
			b[0] = i/3+1;
			b[1] = i/3;
			b[2] = i/3-1;
			lambda[i-1].push_back(a);
			lambda[i-1][0][2]--;
			lambda[i].push_back(a);
			lambda[i+1].push_back(a);
			lambda[i+1][0][0]++;
			
			lambda[i-1].push_back(b);
			lambda[i-1][1][1]--;
			lambda[i].push_back(b);
			lambda[i+1].push_back(b);
			lambda[i+1][1][1]++;
		}
	}
	/*
	ofstream cout("table.txt");
	for (int i = 0; i < 31; i++) {
		cout << i << ':';
		for (int j = 0; j < lambda[i].size(); j++) {
			cout << " (" << lambda[i][j][0] << ',' << lambda[i][j][1] << ','
					<< lambda[i][j][2] << ')';
		}
		cout << endl;
	}
	*/
}

int maxResult(int n, bool s){
	if(n<=1){
		return n;
	}
	int res=-1;
	if(n>=29)s=false;
	for(int i=0; i<3; i++){
		res = max(res, lambda[n][s?1:0][i]);
	}
	return res;
}

int main() {
	partTable();
	int T;
	cin >> T;
	for(int i=0; i<T; i++){
		int N, S, P;
		cin>>N>>S>>P;
		vector< int > t(N);
		for(int j=0; j<N; j++) cin>>t[j];
		sort(t.begin(), t.end());
		
		int cnt=0;
		for(int j=0; j<N; j++){
			int bf, af;
			bf = maxResult(t[j],false);
			if(bf>=P){
				cnt++;
				continue;
			}
			af = maxResult(t[j],true);
			if(S>0 && bf<P && af>=P){
				S--;
				cnt++;
			}
		}
		
		printf("Case #%d: %d\n", i+1, cnt);
	}
	return 0;
}
