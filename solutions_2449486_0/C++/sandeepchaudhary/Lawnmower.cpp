#include<iostream>
#include<fstream>
using namespace std;

#define MAX 100
ofstream out;

bool check(int arr[][MAX], int i, int j, int M, int N) {
	int ans = 0;

	for(int k = 0; k < N; ++k){
		if(arr[i][k] > arr[i][j]) {
			ans++;
			break;
		}
	}

	for(int k = 0; k < M; ++k){
		if(arr[k][j] > arr[i][j]) {
			ans++;
			break;
		}
	}
	if(ans == 2) return true;
	else return false;
}
void solve(int arr[][MAX], int M, int N) {
	for(int i = 0; i < M; ++i) {
		for(int j = 0; j < N; ++j) {
			if(check(arr, i, j, M, N)){
				out<<"NO"<<endl;
				return;
			}
		}
	}
	out<<"YES"<<endl;
	return;
}

int main() {
	ifstream in;

	in.open("B-small-attempt0.in");
	out.open("output.txt");
	int T, M, N;
	int arr[MAX][MAX];

	in>>T;

	for(int k = 0; k < T; ++k) {
		in>>M>>N;
		out<<"Case #"<<k+1<<": ";

		for(int i = 0; i < M; ++i)
			for(int j = 0; j < N; ++j)
				in>>arr[i][j];
		solve(arr, M, N);

	}

	in.close();
	out.close();
	return 0;
}
