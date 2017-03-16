#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
#include <string>

using namespace std;
typedef pair <int, int> ii;
typedef vector <int> vii;
#define TRvii(c,it) for (vii::iterator it =(c).begin(); it!=(c).end(); it++)
#define pi 3.14159265359

// cout << "Case #" << z << ": " <<    << endl;

int main () {
	FILE* ifile = freopen("A-small-attempt0 (1).in", "r", stdin);
	FILE* ofile = freopen ("ofile.txt", "w", stdout);
	int t;
	cin >> t;
	for (int z=1; z<=t; z++){
		string s;
		cin >> s;
		int max = 0;
		int maxindex=0;
		char A[1002];
		for (int i=0; i<s.length(); i++){
			A[i] = s[i];
			if (int(s[i])-64 >= max){
				max = int(s[i])-64;
				maxindex = i;
			}	
		}
	int pivot = int(A[0])-64;
	char left[1001];
	int sizeleft =0;	
	char right[1001];
	int sizeright =0;
	for (int i=1; i<=maxindex; i++){
		if (int(A[i])-64 >= pivot){
			left[sizeleft] = A[i];
			pivot=int(A[i])-64;
			sizeleft++;
		}
		else {
			right[sizeright]= A[i];
			sizeright++;
		}
	}
	for (int i=maxindex+1; i<s.length(); i++){
		right[sizeright] = A[i];
		sizeright++;
	}
	char reversed [1002];
	for (int i=0; i<sizeleft; i++){
		reversed[sizeleft-1-i] = left[i];
	}
	reversed[sizeleft] = A[0];
	sizeleft++;
	for (int i=0; i<sizeright; i++){
		reversed[sizeleft] = right[i];
		sizeleft++;
	}
	cout << "Case #" << z << ": ";
	for (int i=0; i<sizeleft; i++){
		cout << reversed[i];
	}
	cout << endl;
	}
	
	return 0;
}
