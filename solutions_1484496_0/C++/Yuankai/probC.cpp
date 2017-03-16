#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define max 10000000

typedef struct{
	int sum;
	int mark;
}MT;

int T;
int num[100];
MT M[max];
int n;
int w[30];
int len;

struct less_by_weight
{
  bool operator()(const MT& lhs, const MT& rhs) const
  {
    return lhs.sum < rhs.sum;
  }
};


void init(){
	int i;
	w[0] = 1;
	for (i = 1; i < 21; i++) w[i] = w[i - 1] * 2;
}

void printSet(int s){
	int i;
	for (i = 0; i < n; i++){
		if ((w[i] & s) != 0) cout << num[i] << " ";
	}
	//cout << s;
	cout << endl;
}

void doit(){
	len = 0;
	int i, j;
	for (i = 0; i < n; i++){
		int prevLen = len;
		M[len].sum = num[i];
		M[len].mark = w[i];
		len ++;
		for (j = 0; j < prevLen; j++) {
			M[len].sum = M[j].sum + num[i];
			M[len].mark = M[j].mark + w[i];
			len ++;
		}
	}
	//cout << M[51].sum << " " << M[51].mark << endl;
	std::sort( M, M + len, less_by_weight() ); 
	for (i = 0; i < len - 1; i ++ ){
		if (M[i].sum != M[i + 1].sum) continue;
		int tmp = M[i].mark & M[i+1].mark;
		if (tmp != 0) continue;
		printSet(M[i].mark);
		printSet(M[i + 1].mark);
		return;
	}
	cout << "Impossible" << endl;
}

void readInput(const char* filename){
	ifstream fin(filename);
	fin >> T;
	int i, j;
	for (i = 0; i < T; i++){
		fin >> n;
		for (j = 0; j < n; j++) {
			fin >> num[j];
		}

		cout << "Case #" << i + 1 << ": " << endl;
		doit();
	}
	fin.close();
}

int main(){
	init();
	readInput("./C-small-attempt0.in");
	return 0;
}
