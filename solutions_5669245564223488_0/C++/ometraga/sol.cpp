#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

ifstream in;
ofstream out;
bool flag[10];
string tr[10];
int N;

bool validPath(string s) {
	bool c[26];
	memset(c, 0, sizeof(c));
	for(int i=0; i<s.length(); i++) {
		if(c[s[i]-'a'] == 0) c[s[i]-'a'] = 1;
		else if(s[i] != s[i-1]) return 0;
	}
	return 1;
}

int calc(int last, int tra, string path) {
	if(tra == N) return 1;
	long long sum=0, max=0;
	bool found=0;
	for(int i=0; i<N; i++) if(flag[i] == 1) if(validPath(path+tr[i])) {
		flag[i] = 0;
		string s = path + tr[i];
		sum += (calc(i, tra+1, s) % 1000000007);
		flag[i] = 1;
	}	
	return (sum) % 1000000007;
}

int main() {
	in.open("B-small-attempt1.in");
	out.open("out.txt");
	int T;
	in >> T;
	for(int t=1; t<=T; t++) {
		in >> N;
		for(int i=0; i<N; i++) in >> tr[i];
		out << "Case #" << t << ": ";
		long long sum=0;
		memset(flag, 1, sizeof(flag));
		
		
		for(int i=0; i<N; i++) {
			flag[i]=0;
			sum = (sum + calc(i,1, tr[i])) % 1000000007;
			flag[i]=1;
		}
		
		out << sum << endl;
	}
}
