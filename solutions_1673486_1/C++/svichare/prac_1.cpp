#include<algorithm>
#include<fstream>
#include<iostream>
#include<sstream>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include <iomanip>

using namespace std;

double proc(int A, int B, string s)
{
	istringstream iss(s);
	double pr[100000];

	for (int i = 0 ; i < A ; i++) {
		double temp;
		iss >> temp;
		pr[i] = temp;
	}
	double min = 9999999;

	for (int i = 0 ; i <= A ; i++) {
		double val = 0, cur = 1, wr = 1;
		for (int j = 0 ; j < (A - i) ; j++) {
			cur *= pr[j];
		}
		wr = (double)1.0 - cur;
		double val1 = (cur *(B-A+1 + (2*i)));
		double val2 = (wr * (B + (B-A) + 2 + (2*i)));
		val =  val1 + val2 ;
		if (val < min) {
			min = val;
		}
	}
	if (min > (B + 2)) {
		min = (B + 2);
	}

	return min;
}

int main(int argc, const char *argv[])
{
	int tc = 0;
	ifstream is;
	if(argc == 1)
		is.open("input.txt");
	else
		is.open(argv[1]);

	string s;
	getline(is,s); 
	istringstream iss(s);
	iss >> tc;

	for(int i = 1; i <= tc; i++)
	{
		int A, B;
		printf("Case #%d: ",i);
		getline(is,s); 
		istringstream iss(s);
		iss >> A >> B;
		getline(is,s);
		cout << fixed;
		cout << setprecision(7) << proc(A, B, s) << endl;
	}
	is.close();
	return 0;
}