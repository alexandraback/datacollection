#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <fstream>

using namespace std;

typedef long long ll;

int n;
int stu[1005];
bool rel[1005][1005];// 1 likes 2

bool visited[1005] = {false};
int cont[1005] = {1};

int search_loop(int head) {
	for(int i = 0; i < 1005; i++){
		visited[i] = false;
		cont[i] = 1;
	}
	int curr = head;
	while(!visited[stu[curr]]) {
		visited[curr] = true;
		cont[stu[curr]] = 1 + cont[curr];
		curr = stu[curr];
	}
	return cont[curr] - cont[stu[curr]] + 1;
}

int biggest_loop() {
	for(int i = 0; i < 1005; i++){
		visited[i] = false;
		cont[i] = 1;
	}
	int max_loop = 0;

	for(int i = 1; i <= n; i++) {
		if(!visited[i]) {
			max_loop = max(max_loop, search_loop(i));
		}
	}

	return max_loop;
}

int longest_chain(int head, int ignore) {
	int len = 0;
	for(int i = 1; i <= n; i++) {
		if(rel[i][head] && i != ignore) {
			len = max(len, longest_chain(i, ignore));
		}
	}
	return 1 + len;
}

int chains() {
	int total = 0;
	for(int i = 1; i <= n; i++) {//yes theyre each counted twice
		if(stu[stu[i]] == i) {
			total += longest_chain(i, stu[i]) + longest_chain(stu[i], i);
		}
	}
	return total/2;
}

int main() { 
	ofstream fout;
	fout.open ("ayylmao.txt");
	ifstream fin;
	fin.open ("C-large.in");

	int t; fin>>t;
	for(int i = 1; i <= t; i++) {
		fout<<"Case #"<<i<<": ";
		fin>>n;
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= n; k++) {
				rel[j][k] = false;
			}
		}
		for(int j = 1; j <= n; j++) {
			fin>>stu[j];
			rel[j][stu[j]] = true;
		}

		fout<<max(biggest_loop(), chains())<<endl;
		//fout<<biggest_loop()<<endl;
	}
	return 0;
}