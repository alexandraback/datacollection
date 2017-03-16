#include <bits/stdc++.h>
using namespace std;

#define MAXS 1010

int T, N;
char S[ MAXS ];

int main() {
	ios::sync_with_stdio(false);
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> T;
	for(int i=1;i<=T;i++) {
		in >> N >> S;
		int add=0, sum=0;
		for(int j=0;j<=N;j++) {
			int tmp = int(S[j] - '0');
			if(j > sum) add+=(j-sum), sum=j;
			sum += tmp;
		}
		out << "Case #"<<i<<": "<<add<<endl;
	}
	in.close();
	out.close();
	return 0;
}
