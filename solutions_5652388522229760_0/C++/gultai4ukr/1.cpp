#include <bits/stdc++.h>
 
#define LLI long long int
#define LD long double
#define PB push_back
#define MP make_pair
#define FORi(i, a, b) for(int i = a; i < b ; ++i)
#define FORd(i, a, b) for(int i = a; i > b ; --i)
 
using namespace std;
 
const int mod = 1000000000;
vector<bool> v(10);

bool check(int cnt){
	while(cnt){
		v[cnt%10] = 1;
		cnt /= 10;
	}
	FORi(i,0,10)
		if (!v[i])
			return 0;
	return 1;
}

int main(){
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	int t, n, cnt;
	fin >> t;
	FORi(i,0,t){
		fin >> n;
		fout << "Case #" << i+1 << ": ";
		if (!n){
			fout << "INSOMNIA" << endl;
			continue;
		}
		FORi(i,0,10)
			v[i] = 0;
		cnt = n;
		while(!check(cnt)){
			cnt += n;
		}
		fout << cnt << endl;
	}
	fin.close();
	fout.close();
}
