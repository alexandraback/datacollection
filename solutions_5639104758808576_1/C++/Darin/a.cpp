#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
	freopen("A-large.in","r",stdin);
	freopen("A-large.txt","w",stdout);
	int tests;
	cin >> tests;
	for (int test=1; test<=tests; test++){
		int ans = 0;
		int tot = 0;
		int mv = 0;
		cin >> mv;
		string ss;
		cin >> ss;
		for (int i=0; i<=mv; i++){
			if (i-tot > ans){
				ans = i - tot;
			}
			tot = tot + (int)(ss[i] - '0');
		}
		cout << "Case #" << test << ": " << ans << endl;
	}

}