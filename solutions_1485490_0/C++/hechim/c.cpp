#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

ifstream fin("in");
ofstream fout("out");

const int MAXN = 101;
const int MAXM = 101;
long long a[MAXN], b[MAXM];
int A[MAXN], B[MAXM];
int N,M;

long long mem[MAXN][MAXM][MAXN][MAXM];

void init() {
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			for(int i0=0; i0<N; i0++)
				for(int j0=0; j0<M; j0++)
					mem[i][j][i0][j0] = -1;
}

long long min(long long x, long long y) {
	return (x<y)?x:y;
}
long long max(long long x, long long y) {
	return (x>y)?x:y;
}

long long boxToys(int i, int j, int i0, int j0) {
/*	cout << i << " " << j << " " << i0 << " " << j0 << endl;
	if(i==0 && j==2)
		cout << "there" << endl;*/
	if(i>=N || j>=M)
		return 0;
	
	if(mem[i][j][i0][j0]==-1) {
		long long ans = 0;

		int leftover = A[i0];
//		cout << "\t" << leftover << endl;
		if(A[i]==B[j]) {
			long long nboxes=0, ntoys=0;
			if(A[i]==leftover)
				for(int k=i0; k<i; k++)
					if(A[k]==leftover)
						nboxes += a[k];
			if(B[j]==leftover)
				for(int k=j0; k<j; k++)
					if(B[k]==leftover)
						ntoys += b[k];

			long long prev = min(nboxes,ntoys);
			nboxes -= prev; ntoys -= prev;

//			long long ai = a[i]+nboxes;
//			long long bj = b[j]+ntoys;
			long long ai = a[i]-ntoys;
			long long bj = b[j]-nboxes;
			long long boxedtoys = min(ai,bj);
			if(ai==bj)
				ans = boxToys(i+1,j+1,i+1,j+1);
			else if(ai>bj)
				ans = boxToys(i,j+1,i0,j0);
			else
				ans = boxToys(i+1,j,i0,j0);
			ans += boxedtoys;
		}
		else {
			long long throwboxes, throwtoys;
			if(A[i]==leftover)
				throwboxes = boxToys(i+1,j,i+1,j);
			else
				throwboxes = boxToys(i+1,j,i0,j0);
				
//			for(int k=i+1; k<N; k++)
//				throwboxes = max(throwboxes, boxToys(k,j));
			if(B[j]==leftover)
				throwtoys = boxToys(i,j+1,i,j+1);
			else
				throwtoys = boxToys(i,j+1,i0,j0);
//			for(int k=j+1; k<M; k++)
//				throwtoys = max(throwtoys, boxToys(i,k));
			ans = max(throwboxes,throwtoys);
		}
		mem[i][j][i0][j0] = ans;
	}
	return mem[i][j][i0][j0];
}

int main() {
	int T; fin>>T;
	for(int t=1; t<=T; t++) {
		fin>>N>>M;
		for(int i=0; i<N; i++) {
			fin>>a[i]>>A[i];
			if(i>0 && A[i]==A[i-1]) {
				a[i-1] += a[i];
				i--; N--;
			}
		}
		for(int i=0; i<M; i++) {
			fin>>b[i]>>B[i];
			if(i>0 && B[i]==B[i-1]) {
				b[i-1] += b[i];
				i--; M--;
			}
		}
		init();

		fout << "Case #" << t << ": " << boxToys(0,0,0,0) << endl;
/*		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++)
				cout << mem[i][j][0][0] << " ";
			cout << endl;
		}*/
	}

	return 0;
}

