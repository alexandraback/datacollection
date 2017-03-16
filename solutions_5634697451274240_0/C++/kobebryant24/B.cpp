#include <bits/stdc++.h>
using namespace std;

#define forall(i,a,b)               for(int i=a;i<b;++i)

int main(){
	int t;cin >> t;
	forall(test,0,t){
		cout << "Case #" << test+1 << ": ";
		string a;cin >> a;
		int changes=0,n=a.size();
		forall(i,1,n){
			if(a[i]!=a[i-1]) ++changes;
		}
		if(a[n-1]=='+') cout << changes << endl;
		else cout << changes+1 << endl;
	}
}