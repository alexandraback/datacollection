#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ifstream fin("A-large.in");
//ifstream fin("input.in");
ofstream fout("output.txt");

int main(){
	int t, i, j;
	//ios_base::sync_with_stdio(0);
	fin >> t;
	int r,c,w,ans,ans2;

	for (j=1; j<=t; j++){
		fin >> r >> c >> w;
		// for r>1 check phase for not found rows, then last found
		ans = (c/w);
		ans = (r-1)*ans;
	
		ans2 = (c/w);
		ans2 += w-1;
		if (c%w != 0)
			ans2++;

		fout << "Case #" << j << ": " << ans+ans2 << endl;
	}
	return 0;
}