#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <list>
using namespace std;

unsigned int maximum_num = 0;

void probaj(list<unsigned int> M, int A, int br_op=0) {
	if(br_op>maximum_num && maximum_num!=0) return;
		
	while(!M.empty() && A>M.front() ) {
		A += M.front();
		M.pop_front();
	}
	
	if(M.empty() ) {
		if(maximum_num==0 || br_op<maximum_num)
			maximum_num = br_op;
		return;
	}
	
	if(A-1>0) {
		M.push_front(A-1);
		probaj(M, A, br_op+1);
		M.pop_front();
	}
	M.pop_back();
	probaj(M, A, br_op+1);
	
}

void Test(int T) {
	unsigned int A, N, z;
	list<unsigned int> M;
	
	cin >> A >> N;
	for(int i=0; i<N; i++) {
		cin >> z;
		M.push_back(z);
	}
	M.sort();
	
	int nA=A;
	while(!M.empty() && nA>M.front() ) {
		nA+=M.front();
		M.pop_front();
	}
	maximum_num =0;
	
	probaj(M, nA);
	
	cout << "Case #" << T << ": " << maximum_num << endl;
}

int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	unsigned int T;
	cin >> T;
	for(int i=1; i<=T; i++)
		Test(i);
	return 0;
}
