#include <iostream>
using namespace std;

void main(){
	//*
	freopen("A-small.in","r",stdin);
	freopen("A-small.out","w",stdout);
	//*/

	cout.setf(ios::fixed);
	cout.precision(6);

	int T;
	cin>>T;
	//cin.ignore();

	int s[500];
	double ans[500];
	
	for(int tc=1;tc<=T;tc++){
		int n = 0, x = 0;
		cin>>n;
		int mx = 0;
		for(int i=0;i<n;i++){
			cin>>s[i];
			if(s[i] > mx) mx = s[i];
			x+=s[i];
			ans[i] = 0;
		}

		int sum = x;
		while(x > 0){
			for(int i=0;i<n;i++){
				if(s[i] < mx){
					x -= mx-s[i];
					ans[i] += mx-s[i];
					s[i] += mx-s[i];
				}
			}
			mx++;
		}
	
		cout<<"Case #"<<tc<<": ";
		for(int i=0;i<n;i++){
			cout<<(ans[i]*100)/sum;
			if(i<n-1) cout<<' ';
		}
		cout<<endl;
	}
}
/*
4
2 20 10
2 10 0
4 25 25 25 25
3 24 30 21

*/