#pragma comment(linker, "/STACK:36777216")
#include <bits/stdc++.h>
using namespace std;
//----------------------------
#define fori(i, n) for (int i = 0; i < (int)(n); i++)
//FILE *in = fopen("input.txt", "r");
//FILE *in = fopen("A.in", "r");
ifstream in;
FILE *out = fopen("output.txt", "w");
//----------------------------
void solve() {
	string str, res = "";
	//fscanf(in, "%s", &str);
	in>>str;
	res += str[0];
	for (int i = 1; i < str.size(); i++) {
		if (str[i] >= res[0]) {
			res = str[i] + res;
		}
		else {
			res = res + str[i];
		}
	}
	res += '\n';
	fprintf(out, res.c_str());
}
//----------------------------
int main()
{
	in.open("A-large.in");
	int tn;
  	//fscanf(in, "%d", &tn);
  	in>>tn;
  	fori(t, tn) {
	  	fprintf(out, "Case #%d: ", t + 1);
    	solve();
  	}
  	in.close();
    fclose(out);
  	return 0;
}
