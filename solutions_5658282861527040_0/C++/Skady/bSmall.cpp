#include <bits/stdc++.h>
using namespace std;
#define msg(x) cout<<#x<<" = "<<x<<endl;
int main() {
    ios_base::sync_with_stdio(0);
    int T, a, b, k;
   	cin>>T;
   	for(int caso=1 ; caso<=T ; caso++) {
   		cin>>a>>b>>k;
   		int ans = 0;
   		for(int ba=0 ; ba<a ; ba++) {
   			for(int bb=0 ; bb<b ; bb++) {
   				if( (ba & bb) < k ) {
   					//cout<<ba<<" "<<bb<<endl;
   					ans++;
   				}
   			}
   		}
   		cout<<"Case #"<<caso<<": "<<ans<<endl;
   	}
    return 0;
}