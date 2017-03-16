#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;





int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	cin>>T;
	for (int _t = 0; _t < T; _t++){
		int n,m,k;
		cin>>n>>m>>k;
		int n1= n, m1 = m;
		n = min(n1,m1);
		m = max(n1,m1);
		if (n == 1 || n == 2) {
			cout<<"Case #"<<_t+1<<": "<<k<<endl;
			continue;
		}
		if (n==3) {
			if (m==3) {
				if (k >=5) cout<<"Case #"<<_t+1<<": "<<k-1<<endl;
				else cout<<"Case #"<<_t+1<<": "<<k<<endl;
				continue;
			}
			if (m==4) {
				if (k >= 5 &&  k < 8) cout<<"Case #"<<_t+1<<": "<<k-1<<endl;
				else if (k >= 8 ) cout<<"Case #"<<_t+1<<": "<<k-2<<endl;
				else cout<<"Case #"<<_t+1<<": "<<k<<endl;
				continue;
			}
			if (m==5) {
				if (k >= 5 &&  k < 8) cout<<"Case #"<<_t+1<<": "<<k-1<<endl;
				else if (k >= 8 &&  k < 11) cout<<"Case #"<<_t+1<<": "<<k-2<<endl;
				else if (k >=11 ) cout<<"Case #"<<_t+1<<": "<<k-3<<endl;
				else cout<<"Case #"<<_t+1<<": "<<k<<endl;
				continue;
			}
			if (m==6){
				if (k >= 5 &&  k < 8) cout<<"Case #"<<_t+1<<": "<<k-1<<endl;
				else if (k >= 8 &&  k < 11) cout<<"Case #"<<_t+1<<": "<<k-2<<endl;
				else if (k >=11 && k < 14) cout<<"Case #"<<_t+1<<": "<<k-3<<endl;
				else if (k >=14) cout<<"Case #"<<_t+1<<": "<<k-4<<endl;
				else cout<<"Case #"<<_t+1<<": "<<k<<endl;
				continue;
			}
		}
		if (n == 4) {
			if (m==4) {
				if (k >= 5 &&  k < 8) cout<<"Case #"<<_t+1<<": "<<k-1<<endl;
				else if (k >= 8 &&  k < 10) cout<<"Case #"<<_t+1<<": "<<k-2<<endl;
				else if (k == 11 || k==10) cout<<"Case #"<<_t+1<<": "<<8<<endl;
				else if (k >=12) cout<<"Case #"<<_t+1<<": "<<k-4<<endl;
				else cout<<"Case #"<<_t+1<<": "<<k<<endl;
				continue;
			}
			if (m==5) {
				if (k >= 5 &&  k < 8) cout<<"Case #"<<_t+1<<": "<<k-1<<endl;
				else if (k >= 8 &&  k < 11) cout<<"Case #"<<_t+1<<": "<<k-2<<endl;
				else if (k == 11) cout<<"Case #"<<_t+1<<": "<<8<<endl;
				else if (k == 12 || k == 13) cout<<"Case #"<<_t+1<<": "<<k-4<<endl;
				else if (k>=14 && k <16) cout<<"Case #"<<_t+1<<": "<<10<<endl;
				else if (k>=16) cout<<"Case #"<<_t+1<<": "<<k-6<<endl;
				else cout<<"Case #"<<_t+1<<": "<<k<<endl;
				continue;
			}
		}
	}
    return 0;
}