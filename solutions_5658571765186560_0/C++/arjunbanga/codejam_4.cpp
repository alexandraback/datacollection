#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("inp.in","r",stdin);

        freopen("outp.out","w",stdout);
	int t;
	cin>>t;
	for(int ca = 1; ca <= t; ca++) {
		int x, r, c;
		cin>>x>>r>>c;
		int temp;
		if(r > c) {
			temp = r;
			r = c;
			c = temp;
		}
		if(x == 1) {
			cout<<"Case #"<<ca<<": "<<"GABRIEL"<<endl;
		}else if( x == 2) {
			if((r*c)%2 == 1) {
				cout<<"Case #"<<ca<<": "<<"RICHARD"<<endl;
			}else {
				cout<<"Case #"<<ca<<": "<<"GABRIEL"<<endl;
			}
		}else if(x == 3) {
				if(c == 3 && r != 1) {
				cout<<"Case #"<<ca<<": "<<"GABRIEL"<<endl;
				}else if(c == 4 && r == 3) {
				cout<<"Case #"<<ca<<": "<<"GABRIEL"<<endl;
				}else {
					cout<<"Case #"<<ca<<": "<<"RICHARD"<<endl;
				}
		}else if(x == 4) {
				 if(c == 4 && (r == 3 || r == 4)) {
					cout<<"Case #"<<ca<<": "<<"GABRIEL"<<endl;
				}else {
					cout<<"Case #"<<ca<<": "<<"RICHARD"<<endl;
				}
		}
	}
	return 0;
}
		
