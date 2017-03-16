#include <bits/stdc++.h>
 
#define LLI long long int
#define LD long double
#define PB push_back
#define MP make_pair
#define FORi(i, a, b) for(int i = a; i < b ; ++i)
#define FORd(i, a, b) for(int i = a; i > b ; --i)
 
using namespace std;

ifstream fin("in.txt");
ofstream fout("out.txt");
	 
const int mod = 1000000000;

vector<LLI> v(9);

LLI check_base(int mask, int base){
	LLI n = 0, p = 1;
	while (mask){
		n += p*(mask%2);
		mask /= 2;
		p *= base;
	}
	p = min(int(sqrt(n) + 1), 100);
	FORi(i,2,p)
		if (n%i==0)
			return i;
	return 0;		
}

bool check(int mask){
	LLI tmp;
	FORi(i,0,9){
		tmp = check_base(mask,i+2);
		if (tmp)
			v[i] = tmp;
		else
			return 0;
	}
	string s;
	while(mask){
		s += mask%2 + '0';
		mask /= 2;
	}
	FORd(i,s.size()-1,-1)
		fout << s[i];
	fout << " ";
	FORi(i,0,9)
		fout << " " << v[i];
	fout << endl;
	return 1;
}

int main(){
	int t,n,j;
	LLI mask;
	fin >> t;
	FORi(i,0,t){
		fin >> n >> j;
		fout << "Case #" << i+1 << ":" << endl;
		mask=(1<<(n-1))+1; 
		while (mask<(1ll<<n) && j){
			j -= check(mask);
			mask += 2;
		}
	}
	fin.close();
	fout.close();
}
