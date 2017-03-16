//============================================================================
// Name        : codejamtest2.cpp
// Author      : festony
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <deque>
#include <set>
#include <algorithm>
using namespace std;

typedef unsigned long long LL;

LL get_min(LL a, LL b) {
	return (a > b) ? b : a;
}

LL get_max(LL a, LL b) {
	return (a > b) ? a : b;
}

//LL calc_result(vector<LL> a, vector<LL> A, vector<LL> b, vector<LL> B, int strat) {
//	int one_bit = 1 << (a.size() - 1);
//	//cout << one_bit;
//	int b_pointer = 0;
//	LL r = 0;
//	for(int i=0; i<(int)a.size(); i++) {
//		if((strat & one_bit) == 0) {	// abandon this batch in A
//			one_bit = one_bit >> 1;
//			continue;
//		} else {
//			while(B[b_pointer] != A[i] && b_pointer < (int)b.size()) {
//				b_pointer ++;
//			}
//			if(b_pointer >= (int)b.size()) {
//				break;
//			}
//			r += get_min(a[i], b[b_pointer]);
//			//b_pointer ++;
//
//			one_bit = one_bit >> 1;
//		}
//	}
//
//	return r;
//}
//
//LL calc_max_result(vector<LL> a, vector<LL> A, vector<LL> b, vector<LL> B) {
//	int max_case = (int)(pow(2, a.size()));
//	LL mr = 0;
//	LL r;
//	for(int i=0; i<max_case; i++) {
//		r = calc_result(a, A, b, B, i);
//		cout << "  " << r << endl;
//		if(r > mr) {
//			mr = r;
//		}
//	}
//
//	return mr;
//}

int depth = 0;

LL calc_result(LL * a, LL * A, LL * b, LL * B, int N, int M, int depth) {
	LL r_a = 0; // keep A;
	LL r_b = 0; // keep B;
	LL r1 = 0;
	LL r2 = 0;
	LL r3 = 0;
	LL r = 0;

	if (M == 0 || N == 0) {
		r = 0;
	} else {
		LL * a1;
		LL * A1;
		LL * b1;
		LL * B1;
		a1 = new LL [N];
		A1 = new LL [N];
		b1 = new LL [M];
		B1 = new LL [M];
		memcpy(a1, a, sizeof(LL) * N);
		memcpy(A1, A, sizeof(LL) * N);
		memcpy(b1, b, sizeof(LL) * M);
		memcpy(B1, B, sizeof(LL) * M);
//
//		for (int i = 0; i < N; i++) {
//			in >> a[i] >> A[i];
//		}
//		for (int i = 0; i < M; i++) {
//			in >> b[i] >> B[i];
//		}
//
//		cout << calc_result(a, A, b, B, N, M, 1) << endl;


		if (A1[0] == B1[0]) {
			if (a1[0] > b1[0]) {
				r1 = b1[0];
				a1[0] -= b1[0];
				r1 += calc_result(a1, A1, b1 + 1, B1 + 1, N, M - 1, depth + 1);
				r = r1;
			} else if (a1[0] < b1[0]) {
				r2 = a1[0];
				b1[0] -= a1[0];
				r2 += calc_result(a1 + 1, A1 + 1, b1, B1, N - 1, M, depth + 1);
				r = r2;
			} else {
				r3 = a1[0];
				r3 += calc_result(a1 + 1, A1 + 1, b1 + 1, B1 + 1, N - 1, M - 1,
						depth + 1);
				r = r3;
			}
		} else {
			LL * a2;
			LL * A2;
			LL * b2;
			LL * B2;
			a2 = new LL [N];
			A2 = new LL [N];
			b2 = new LL [M];
			B2 = new LL [M];
			memcpy(a2, a, sizeof(LL) * N);
			memcpy(A2, A, sizeof(LL) * N);
			memcpy(b2, b, sizeof(LL) * M);
			memcpy(B2, B, sizeof(LL) * M);

			r_a = calc_result(a1, A1, b1 + 1, B1 + 1, N, M - 1, depth + 1);
			r_b = calc_result(a2 + 1, A2 + 1, b2, B2, N - 1, M, depth + 1);
			r = get_max(r_a, r_b);
			delete [] B2;
			delete [] b2;
			delete [] A2;
			delete [] a2;
		}

		delete [] B1;
		delete [] b1;
		delete [] A1;
		delete [] a1;
	}

//	for (int i = 0; i < depth; i++) {
//		cout << " ";
//	}
//	cout << "A: ";
//	for (int i = 0; i < N; i++) {
//		cout << a[i] << " " << A[i] << " ";
//	}
//	for (int i = 0; i < depth; i++) {
//		cout << " ";
//	}
//	cout << "B: ";
//	for (int i = 0; i < M; i++) {
//		cout << b[i] << " " << B[i] << " ";
//	}
//	for (int i = 0; i < depth; i++) {
//		cout << " ";
//	}
//	cout << "R: ";
//	cout << r << endl;

	return r;
}

static string process(int case_num, fstream & in) {
	clock_t t1=clock();
	char buf[10240];
	string temp_str = "";
	string result = "";

	int N, M;
	in >> N >> M;

	LL r = 0;

//	vector<LL>a;
//	vector<LL>A;
//	vector<LL>b;
//	vector<LL>B;
//
//	for(int i=0; i<N; i++) {
//		LL temp1, temp2;
//		in >> temp1 >> temp2;
//		a.push_back(temp1);
//		A.push_back(temp2);
//	}
//	for(int i=0; i<M; i++) {
//		LL temp1, temp2;
//		in >> temp1 >> temp2;
//		b.push_back(temp1);
//		B.push_back(temp2);
//	}

//	int max_case = (int)(pow(2, a.size()));
//	vector<int> cases;
//	for(int i=0; i<max_case; i++) {
//		cases.push_back(i);
//	}
//	vector<LL> results;
//	cout << calc_result(a, A, b, B, 7) << endl;

	stringstream ss (stringstream::in | stringstream::out);

	LL * a;
	LL * A;
	LL * b;
	LL * B;
	a = new LL [N];
	A = new LL [N];
	b = new LL [M];
	B = new LL [M];

	for (int i = 0; i < N; i++) {
		in >> a[i] >> A[i];
	}
	for (int i = 0; i < M; i++) {
		in >> b[i] >> B[i];
	}

	r = calc_result(a, A, b, B, N, M, 1);

	delete [] B;
	delete [] b;
	delete [] A;
	delete [] a;

	ss << r;
	temp_str = ss.str();



	sprintf(buf, "Case #%d: %s\n", case_num + 1, temp_str.c_str());
	clock_t t2=clock();
	cout<<"Iteration " << case_num + 1 << " took " << t2-t1 << " mini seconds" << endl;
	result.append(buf);
	return result;
}

int main() {
	int caseNum = 0;
	fstream in("F:\\Users\\festony\\Downloads\\codejam\\2012_1c\\C-small-attempt2.in");
	fstream out("F:\\Users\\festony\\Downloads\\codejam\\2012_1c\\testout2.txt", ios_base::out | ios_base::trunc);

	in >> caseNum;
	in.ignore(256, '\n');
	char buf[10240];

	string result = "";

	for(int i=0; i<caseNum; i++) {
		result.append(process(i, in));
	}
	cout << result;
	out << result;
	in.close();
	out.close();

}


