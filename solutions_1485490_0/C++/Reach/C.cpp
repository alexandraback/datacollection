
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<long long> VEC;

long long func(VEC a, VEC A, VEC b, VEC B){
	if(a.empty() || b.empty()) return 0;

	int n = a.size()-1;
	int m = b.size()-1;
	if(A[n] == B[m]){
		if(a[n] < b[m]){
			long long tem = a[n];
			b[m] -= a[n];
			a.pop_back();
			A.pop_back();
			return tem + func(a, A, b, B);
		}
		else if(a[n] > b[m]){
			long long tem = b[m];
			a[n] -= b[m];
			b.pop_back();
			B.pop_back();
			return tem + func(a, A, b, B);
		}
		else{
			long long tem = a[n];
			a.pop_back();
			A.pop_back();
			b.pop_back();
			B.pop_back();
			return tem + func(a, A, b, B);
		}
	}
	else{
		VEC ta = a, tA = A;
		ta.pop_back();
		tA.pop_back();
		long long re1 = func(ta, tA, b, B);
		b.pop_back();
		B.pop_back();
		long long re2 = func(a, A, b, B);
		return re1>re2? re1:re2;
	}
}

int main(){
	freopen("C.in", "r", stdin);
	freopen("Cout.txt", "w", stdout);

	int t, tcase;
	cin>>t;
	VEC a, A, b, B;
	for (tcase=1; tcase<=t; tcase++){
		a.clear();
		A.clear();
		b.clear();
		B.clear();
		int n, m;	
		cin>>n>>m;
		long long tem1, tem2;
		for(int i = 1; i <= n; i++){
			cin>>tem1>>tem2;
			a.push_back(tem1);
			A.push_back(tem2);
		}
		for(int i = 1; i <= m; i++){
			cin>>tem1>>tem2;
			b.push_back(tem1);
			B.push_back(tem2); 
		}



		cout<<"Case #"<<tcase<<": "<<func(a, A, b, B)<<endl;
	}

	return 0;
}