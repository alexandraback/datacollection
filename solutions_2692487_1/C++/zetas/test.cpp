#include<iostream>
#include<fstream>
#include <algorithm>
#include<vector>
using namespace std;
ifstream fin("A-large.in");
ofstream fout("A-large.out");

int T=1;
int ia[200];
int counter = 0;
int num[200];
int n = 1;

int main()
{
	fin >> T;
	for(int i = 1; i <= T; i++){
		counter = 0;
		int A, N;
		fin >> A >> N;
		n = N;
		for(int j = 0; j < N; j++){
			fin >> ia[j];
		}
		if(1 != A){
		sort(ia, ia+N);
		for(int k = 0; k < N-1; k++){
			while(A <= ia[k]){
				A = 2*A-1;
				counter++;
			}
			A += ia[k];
			num[k] = counter + N - 1 - k;
			if(n > num[k]) n = num[k];
		}
		if(A <= ia[N-1]){ counter++;}
		if(counter > n) counter = n;
		}
		else { counter = N; }
		fout << "Case #" << i <<": " << counter;
		if(i < T) fout << endl;
	}
	return 1;
}