#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010
int T, D, P[MAXN], tempo, massimo;

int main() {
	ios::sync_with_stdio(false);
	ifstream in("input.txt");
	ofstream out("output.txt");
	in>>T;
	for(int i=1;i<=T;i++) {
	   in >> D;
	   massimo=0;
	   for(int j=0;j<D;j++)  in >> P[j], massimo=max(massimo,P[j]);
	   tempo=massimo;
	   for(int j=1;j<=massimo;j++) {
		   int sum=0;
		   for(int k=0;k<D;k++) if(P[k] > j) sum += ((P[k]-1) /j);
		   tempo=min(tempo, sum+j);
	   }
	   out<<"Case #"<<i<<": "<<tempo<<endl;
    }
    in.close();
    out.close();
	return 0;
}
