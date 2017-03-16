#include<iostream>
#include<cstdio>

using namespace std;

int main() {

	int T;

	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);

	cin>>T;
	for(int t=1 ; t<=T ; t++) {
		int N, ans=0;

		cin>>N;

		if(N==1) {
			int D1,H1,M1;
			cin>>D1>>H1>>M1;

			ans=0;
		}
		else if(N==2) {
			int D1,H1,M1,D2,H2,M2;
			cin>>D1>>H1>>M1;
			cin>>D2>>H2>>M2;

			if(M1==M2) ans=0;
			
			if(D1<=180 && D2>180 && M2>M1) {
				if((360-D2)*M2>=M1*(360-D1)) ans=1;
				else ans=0;
			}
			else if(D1>180 && D2<=180 && M1>M2) {
				if((360-D1)*M1>=M2*(360-D2)) ans=1;
				else ans=0;
			}
			else {
				if(M1<M2) {
					if((360-D2)*M2>=M1*(360+360-D1)) ans=1;
					else ans=0;
				}
				else {
					if((360-D1)*M1>=M2*(360+360-D2)) ans=1;
					else ans=0;
				}
			}
		}

		cout<<"Case #"<<t<<": ";
		cout<<ans;
		cout<<"\n";
	}

	return 0;
}