#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>


using namespace boost::multiprecision;
using namespace std;

ofstream fout("out.txt");
ifstream fin("in.txt");

vector<cpp_int> ten({1,10,100,1000,10000,100000,1000000 });
int L = 4;

bool aBetter(vector<cpp_int> &a, vector<cpp_int> &b) {
	if (a[2 * L + 2] > b[2 * L + 2])
		return false;
	if (a[2 * L + 2] < b[2 * L + 2])
		return true;

	if (a[2 * L] > b[2 * L])
		return false;
	if (a[2 * L] < b[2 * L])
		return true;

	if (a[2 * L +1] > b[2 * L+1])
		return false;
	if (a[2 * L+1] < b[2 * L+1])
		return true;

	return true;
}

void eval(vector<cpp_int> &a) {
	a[2 * L] = 0;
	for (int j = 0; j<L; j++)
		a[2 * L] += ten[L - 1 - j] * a[j];

	a[2 * L + 1] = 0;
	for (int j = L; j<2 * L; j++)
		a[2 * L + 1] += ten[2 * L - 1 - j] * a[j];

	cpp_int diff = abs(a[2 * L + 1] - a[2 * L]);
	a[2 * L + 2] = diff;
}

vector<cpp_int> f(vector<cpp_int> a) {
	//vector<int> b = &a[4];
	for (int i = 0; i < 2*L; i++) {
		if (i == L)
			cout << "\t";
		cout << a[i] << " ";
	}
	cout << endl;

	//find first unknown (or first difference)
	int i = 0;
	string status;
	while (i<L) {
		if (a[i] == -1 || a[L + i] == -1) {			
			status = "UNK";
			break;
		}
		else if (a[i] != a[L + i]) {
			status = "DIF";
			break;
		}
		else
			i++;
	}
	if (i == L) {
		status = "SAME";
	}

	cout << i << " " << status << endl;

	if (status == "SAME") {
		eval(a);
		return a;
	}

	if (status == "DIF") {
		//left greater therefore reduce left, increase right
		if (a[i] > a[L + i]) {
			for (int j = 0; j < L; j++) 
				if (a[j] == -1)
					a[j] = 0;
			for (int j = L; j < 2*L; j++)
				if (a[j] == -1)
					a[j] = 9;
		}
		else if (a[i] < a[L + i]){
			for (int j = 0; j < L; j++)
				if (a[j] == -1)
					a[j] = 9;
			for (int j = L; j < 2 * L; j++)
				if (a[j] == -1)
					a[j] = 0;
		}
		else {
			cout << "ERROR 12" << endl;
			exit(0);
		}
		//return
		eval(a);		
		return a;
	}

	//both -1 then 0,0 0,1 1,0
	if (a[i] == -1 && a[L+i] == -1) {
		vector<cpp_int> copy(a);

		copy[i] = 0; copy[L + i] = 0;
		vector<cpp_int> x1 = f(copy);

		copy[i] = 0; copy[L + i] = 1;
		vector<cpp_int> x2 = f(copy);

		copy[i] = 1; copy[L + i] = 0;
		vector<cpp_int> x3 = f(copy);

		if (aBetter(x1, x2) && aBetter(x1, x3))
			return x1;
		if (aBetter(x2, x3))
			return x2;
		else
			return x3;
	}
	else if(a[i]==-1){
		vector<cpp_int> copy(a);
		copy[i] = a[L + i]-1;
			if (copy[i] == -1) copy[i] = 0;
		vector<cpp_int> x1=f(copy);
		copy[i] = a[L + i];
		vector<cpp_int> x2 = f(copy);
		copy[i] = a[L + i]+1;
			if (copy[i] == 10) copy[i] = 9;
		vector<cpp_int> x3 = f(copy);
		
		if (aBetter(x1, x2) && aBetter(x1, x3))
			return x1;
		if (aBetter(x2, x3))
			return x2;
		else
			return x3;
	}
	else if (a[L+i] == -1) {
		vector<cpp_int> copy(a);
		copy[L+i] = a[i] - 1;
			if (copy[L+i] == -1) copy[L+i] = 0;
		vector<cpp_int> x1 = f(copy);
		copy[L+i] = a[i];
		vector<cpp_int> x2 = f(copy);
		copy[L+i] = a[i] + 1;
			if (copy[L + i] == 10) copy[L + i] = 9;
		vector<cpp_int> x3 = f(copy);

		if (aBetter(x1, x2) && aBetter(x1, x3))
			return x1;
		if (aBetter(x2, x3))
			return x2;
		else
			return x3;
	}
	else {
		cout << "ERROR15" << endl;
		exit(15);
	}

}

int T;
int main() {
	fin >> T;
	
	for (int t = 1; t <= T; t++) {
		vector < cpp_int> a;
		string i1, i2;
		fin >> i1;
		fin >> i2;

		L = i1.length();
		for (int i = 0; i < L;i++) {
			if (i1[i] == '?')
				a.push_back(-1);
			else
				a.push_back(i1[i] - '0');
		}

		for (int i = L; i < 2*L; i++) {
			if (i2[i-L] == '?')
				a.push_back(-1);
			else
				a.push_back(i2[i-L] - '0');
		}

		a.push_back(-99);
		a.push_back(-99);
		a.push_back(-99);

		//vector<cpp_int> a({ -1,1,2,3, -1,-1,9,-1 ,-99,-99,-99});
		//vector<cpp_int> a({ 1,1 ,-99,-99,-99 });
		//L = 1;

		vector<cpp_int> ans = f(a);

		for (int i = 0; i < 2 * L; i++) {
			if (i == L)
				cout << "\t";
			cout << ans[i] << " ";
		}
		cout << endl;

		cout << ans[2 * L] << " " << ans[2 * L + 1] << " diff:" << ans[2 * L + 2] << endl;

		string o1 = "00000000000000000000" + (string)ans[2 * L];
		o1 = o1.substr(o1.size() - L);
		string o2 = "00000000000000000000" + (string)ans[2 * L+1];
		o2 = o2.substr(o2.size() - L);

		fout << "Case #" << t << ": " << o1 << " " << o2 << endl;
	}
	
	
}