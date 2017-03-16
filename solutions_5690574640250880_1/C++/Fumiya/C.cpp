#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

vector<string> transpose(vector<string> vs){
	int n = vs.size(), m = vs[0].size();
	vector<string> res(m, string(n,'.'));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			res[j][i] = vs[i][j];
	return res;
}

vector<string> solve(int R, int C, int M){
	bool trans = false;
	if(R > C){
		swap(R, C);
		trans = true;
	}
	M = R*C-M;
	vector<string> res(R, string(C,'*'));
	if(M==1){
		res[0][0] = 'c';
		return trans ? transpose(res) : res;
	}
	if(R==1){
		res[0][0] = 'c';
		for(int i=1;i<M;i++) res[0][i] ='.';
		return trans ? transpose(res) : res;
	}
	if(R==2){
		if(M%2 == 1 || M==2) return vector<string>(1, "Impossible");
		for(int i=0;i<M/2;i++)
			res[0][i] = res[1][i] = '.';
		res[0][0] = 'c';
		return trans ? transpose(res) : res;
	}
	int base = 0;
	for(int r=0;r+2<R;r++){
		for(int i=2;i<=C;i++){
			int num = base+(r==0?i:C)+i;
			if(num == M){
				for(int j=0;j<r;j++) res[j] = string(C, '.');
				if(r==0) for(int j=0;j<i;j++) res[r][j] = '.';
				else     res[r] = string(C, '.');
				for(int j=0;j<i;j++) res[r+1][j] = '.';
				res[0][0] = 'c';
				return trans ? transpose(res) : res;
			}
			for(int k=2;k<=i;k++){
				num = base+(r==0?i:C)+i+k;
				if(num == M){
					for(int j=0;j<r;j++) res[j] = string(C, '.');
					if(r==0) for(int j=0;j<i;j++) res[r][j] = '.';
					else     res[r] = string(C, '.');
					for(int j=0;j<i;j++) res[r+1][j] = '.';
					for(int j=0;j<k;j++) res[r+2][j] = '.';
					res[0][0] = 'c';
					return trans ? transpose(res) : res;
				}
			}
		}
		base += C;
	}
	return vector<string>(1, "Impossible");
}

int main(){
	int T; cin >> T;
	int R, C, M;
	for(int test=1;test<=T;test++){
		cin >> R >> C >> M;
		printf("Case #%d:\n", test);
		vector<string> vs = solve(R, C, M);
		for(int i=0;i<vs.size();i++) cout << vs[i] << endl;
	}
}
