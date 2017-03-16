#include <string>
#include <fstream>
//#include <iostream>
#include <algorithm>
using namespace std;

ifstream cin("B-small-attempt1.in");
ofstream cout("output.txt");

inline bool check(int N, int* p, string* trains){
	string s = "";
	for (int i = 0; i < N; i++)
		s += trains[p[i]];
	int finished[256] = { 0 };
	for (int i = 0; i < s.size() - 1; i++){
		if (finished[s[i]])
			return false;
		if (s[i] != s[i + 1])
			finished[s[i]] = 1;
	}
	return !finished[s[s.size() - 1]];
}

int main(){
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++){
		int N, ways = 0;
		cin >> N;
		string trains[10];
		int p[10];
		for (int i = 0; i < N; i++){
			p[i] = i;
			cin >> trains[i];
		}
		if (check(N, p, trains)) ways++;
		while (next_permutation(p, p + N)){
			if (check(N, p, trains)) ways++;
		}
		cout << "Case #" << t << ": " << ways << endl;
	}
	return 0;
}