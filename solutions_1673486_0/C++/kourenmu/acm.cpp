#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

const int MAX = 100;
double a[MAX];
double p[MAX];

int main(){
	freopen("test.txt", "r", stdin);
	freopen("result.txt", "w", stdout);

	int T, A, B, D, M;
	double result, tmp_pro;
	cin>>T;
	cout.setf(ios::fixed);
	cout.precision(6);

	for(int i = 1; i <= T; i++){
		cin>>A>>B;
		D = B + 1 - A;

		result = 0;
		tmp_pro = 0;
		for(int i = 0; i < A; i++){
			cin>>a[i];
			if(i > 0)
				p[i] = a[i] * p[i - 1];
			else
				p[i] = a[i];
		}

		//tui 0 ge
		result = p[A - 1] * D + (1 - p[A - 1]) * (D + B + 1);
		//tui 1 ge dao A ge
		for(int i = 1; i <= A; i++){
			int t = A - i - 1;
			int r = i + i + D;
			tmp_pro = p[t] * (r) + (1 - p[t]) * (r + B + 1);
			if(result > tmp_pro)
				result = tmp_pro;
		}
		if(result > B + 2)
			result = B + 2;

		cout<<"Case #"<<i<<": "<<result<<endl;
	}

	return 0;
}
