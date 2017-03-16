#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream fin("E:\\B-small-attempt5.in");
  // ifstream fin("E:\\temp.txt");
  ofstream fout("E:\\B-small.out");
  int T;
  int P[1000];
  int inc[1001];
  fin >> T;
  for (int i = 1; i <= T; i++) {
	  for (int j = 0; j <= 1000; j++) {
		  inc[j] = j;
	  }
	  int D;
	  fin >> D;
	  int max = 0;
	  for (int j = 0; j < D; j++) {
		  fin >> P[j];
		  if (P[j] > max) {
			  max = P[j];
		  }
	  }
	  for (int j = 0; j < D; j++) {
		  for (int k = 1; k <= max; k++) {
			  if (P[j] % k == 0) {
				  inc[k] = inc[k] + P[j] / k;
			  }
			  else {
				  inc[k] = inc[k] + P[j] / k + 1;
			  }
		  }
	  }
	  int min = INT_MAX;
	  for (int j = 1; j <= max; j++) {
		  if (inc[j] < min) {
			  min = inc[j];
		  }
	  }
	  min = min - D;
	  fout << "Case #" << i << ": " << min << endl;
  }
  return 0;
}