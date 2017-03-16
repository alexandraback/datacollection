#include <bits/stdc++.h>
using namespace std;

int tt,b;
long long m;

char ans[50][50];

int main(){
    ios_base::sync_with_stdio(false);
    cin >> tt;
    for(int ii=1;ii<=tt;ii++){
	cin >> b >> m;
	if(m > (1LL << (b-2))){
	    cout << "Case #"<< ii << ": IMPOSSIBLE\n";
	    continue;
	}
	cout << "Case #"<< ii << ": POSSIBLE\n";
	for(int i=0;i<b;i++) ans[0][i] = '1';
	ans[0][0] = '0';
	for(int i=1;i<b;i++) {
	    for(int j=0;j<=i;j++) ans[i][j] = '0';
	    for(int j=i+1;j<b;j++) ans[i][j] = '1';
	}
	m--;
	for(int i=1;i<55;i++){
	    if((1LL<<(i-1)) & m) continue;
	    ans[i][b-1] = '0';
	}
	for(int i=0;i<b;i++){
	    for(int j=0;j<b;j++){
		cout << ans[i][j];
	    }
	    cout << endl;
	}
	
    }
    return 0;
}
