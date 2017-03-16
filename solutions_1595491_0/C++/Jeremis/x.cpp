#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
using namespace std;




int main() {

	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	
	int n;
	cin >> n;
	for (int z=0;z<n;z++) {
		int N,S,p,clr=0,sur=0,can=0,x;
		cin >> N >> S >> p;
		for (int i=0;i<N;i++) {
			cin >> x;
			int b = x/3;
			if (x==0) {
				if (p<=0) ++clr;
			} else if (x==1) {
				if (p<=1) ++clr;
			} else if (x>29) {
				++clr;
			} else if (x%3==2) {
				if (b+1>=p) can++; else 
				if (b+2>=p) sur++;
			} else if (x%3==1) {
				if (b+1>=p) can++;
			} else {
				if (b>=p) can++;  else
				if (b+1>=p) sur++;
			}
		}
		//if (n-clr<S) cout << "ERR" << endl; else
			cout << "Case #" << z+1 << ": " << clr + can + min(S,sur) << endl;
	}
}