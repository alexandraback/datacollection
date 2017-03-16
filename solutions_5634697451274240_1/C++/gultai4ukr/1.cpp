#include <bits/stdc++.h>
 
#define LLI long long int
#define LD long double
#define PB push_back
#define MP make_pair
#define FORi(i, a, b) for(int i = a; i < b ; ++i)
#define FORd(i, a, b) for(int i = a; i > b ; --i)
 
using namespace std;
 
const int mod = 1000000000;

int main(){
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	int t, ans, ind;
	string s;
	fin >> t;
	FORi(i,0,t){
		fin >> s;
		ans = 0;
		ind = s.size() - 1;
		if (s[ind]=='-')
			ans=1;
		FORd(i,ind-1,-1)
			if (s[i]!=s[ind]){
				ans++;
				ind = i;
			}
		fout << "Case #" << i+1 << ": " << ans << endl;
	}
	fin.close();
	fout.close();
}
