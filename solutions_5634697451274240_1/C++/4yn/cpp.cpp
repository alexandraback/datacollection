#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main(){
	int tc; cin >> tc;
	for(int t=1;t<=tc;t++){
		cout << "Case #" << t << ": ";
		string a,b; cin >> a;
		b += a[0];
		for(int i=1;i<a.size();i++){
			if(a[i]!=b.back()) b += a[i];
		}
		cout << b.size() + ((b.back()=='+')? -1 : 0) << endl;
	}
}