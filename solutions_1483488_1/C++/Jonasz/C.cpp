#include<iostream>
#include<algorithm>
#include<sstream>
using namespace std;

int comp_p(int x){
	int res = 1;
	do{
		res*=10;
		x/=10;
	}while(x);
	return res/10;
}

int rot(int x, int p){
	return (x%10)*p + (x/10);
}

int solve(){
	int a,b,res=0;
	cin >> a >> b;
	for(int n=a; n<=b; n++){
		int m = n;
		int p = comp_p(m);
		do {
			m = rot(m, p);
			if(n<m && m<=b) res++;
		} while (m!=n);
	}
	return res;
}

int main(){
	int t; cin >> t;
	for(int i=1; i<=t; i++){
		cout << "Case #" << i << ": " << solve() << endl;
	}
	return 0;
}
