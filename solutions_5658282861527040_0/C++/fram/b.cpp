#include <iostream>
using namespace std;

int a,b,k;
int ans;

void test(int index){
	cin >> a >> b >> k;
	ans = 0;
	for(int i=0; i<a; i++) for(int j=0; j<b; j++) if((i&j) < k) ans++;
	
	cout << "Case #" << index << ": " << ans << '\n';
}

int main(){
	int t; cin >> t;
	for(int i=1; i<=t; i++) test(i);
	return 0;
}
