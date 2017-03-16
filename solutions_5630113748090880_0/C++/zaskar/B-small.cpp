#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> result;

void getmins(vector<vector<int>> &h, int p, int n, int &m1, int &m2) {
	m1=-1;m2=-1;
	for(size_t i=0;i<h.size();i++) { 
		if (h[i][n]==0) continue;
		if (m1==-1||h[i][p]<h[m1][p]) {
			m2=m1; m1=i;
		} else if (m2==-1 || h[i][p]<h[m2][p]) {
			m2=i;
		}
	}
	if (m2!=-1 && h[m1][p]!=h[m2][p]) m2=-1;
}

bool try_col(vector<vector<int>> &m, vector<int> col, int p, int n) {
	for(size_t i=0;i<p;i++)
		if (m[i][p]!=-1 && m[i][p]!=col[i]) return false; else m[i][p]=col[i];
	for(size_t i=p;i<n;i++)
		m[i][p] = col[i];
	return true;
}
bool try_row(vector<vector<int>> &m, vector<int> row, int p, int n) {
	for(size_t i=0;i<p;i++)
		if (m[p][i]!=-1 && m[p][i]!=row[i]) return false; else m[p][i]=row[i];
	
	for(size_t i=p;i<n;i++)
		m[p][i] = row[i];
	return true;
}

bool solve(vector<vector<int>> &h, vector<vector<int>> &m, int p, int n){
	if (p==n) return true;
	int m1=-1,m2=-1;
	getmins(h,p,n,m1,m2);
	auto mbak = m;
	if ((m1==-1||try_col(m,h[m1],p,n)) && (m2==-1||try_row(m,h[m2],p,n))) {
		if (m1!=-1) h[m1][n]=0;
		if (m2!=-1) h[m2][n]=0;
		if (solve(h,m,p+1,n)) {
			if (m1==-1) { result.resize(n); for(int k=0;k<n;k++) result[k] = m[k][p]; }
			if (m2==-1) { result.resize(n); for(int k=0;k<n;k++) result[k] = m[p][k]; }
			return true;
		}
		if (m1!=-1) h[m1][n]=1;
		if (m2!=-1) h[m2][n]=1;
	}
	m=mbak;
	if ((m2==-1||try_col(m,h[m2],p,n)) && (m1==-1||try_row(m,h[m1],p,n))) {
		if (m1!=-1) h[m1][n]=0;
		if (m2!=-1) h[m2][n]=0;
		if (solve(h,m,p+1,n)) {
			if (m2==-1) { result.resize(n); for(int k=0;k<n;k++) result[k] = m[k][p]; }
			if (m1==-1) { result.resize(n); for(int k=0;k<n;k++) result[k] = m[p][k]; }
			return true;
		}
		if (m1!=-1) h[m1][n]=1;
		if (m2!=-1) h[m2][n]=1;
	}
	m=mbak;
	return false;
}

int main(int argc, char *argv[]) {
//	string fname = "B-sample";
	string fname = "B-small-attempt0";
//	string fname = "B-large";
	ifstream fin(fname+".in");
	ofstream fout(fname+".out");
	int T;
	fin>>T;
	for(int I=0;I<T;I++) {
		int r,n;
		fin>>n;
		vector<vector<int>> h(2*n-1,vector<int>(n+1,0)); 
		vector<vector<int>> m(n,vector<int>(n,-1));
		for(int i=0;i<2*n-1;i++) { 
			for(int j=0;j<n;j++) { 
				fin>>h[i][j];
			}
			h[i][n]=1;
		}
		
		solve(h,m,0,n);
		
		fout<<"Case #"<<I+1<<":";
		for(int x:result) fout <<" "<<x;
		fout<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

