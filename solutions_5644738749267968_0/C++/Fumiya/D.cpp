#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int solveA(vector<double> A, vector<double> B){
	int n = A.size();
	int res = 0;
	sort(A.rbegin(), A.rend());
	sort(B.begin(), B.end());
	for(int i=0;i<n;i++){
		vector<double> a, b;
		int add = 0, idxA = A.size()-1;
		for(int j=0;j<A.size();j++){
			while(idxA >= 0 && A[idxA] < B[j]) idxA--;
			if(idxA < 0) break;
			add++;
			idxA--;
		}
		res = max(res, add);
		if(A.back() > B.back()) break;
		A.pop_back();
		B.pop_back();
	}
	return res;
}

int solveB(vector<double> A, vector<double> B){
	int n = A.size();
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int res = -1;
	int score = 0;
	int idx = 0;
	for(int i=0;i<n;i++){
		while(idx < n && A[i] > B[idx]) idx++;
		if(idx == n) return n-i;
		idx++;
	}
	return (idx==n ? 0 : -1);
}

int main(){
	int T; cin >> T;
	for(int test=1;test<=T;test++){
		int N; cin >> N;
		vector<double> A(N), B(N);
		for(int i=0;i<N;i++) cin >> A[i];
		for(int i=0;i<N;i++) cin >> B[i];
		printf("Case #%d: %d %d\n", test, solveA(A, B), solveB(A, B));
	}
}
