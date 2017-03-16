#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
using namespace std;

int s[1000];
int T,N;

int main(){
	cin>>T;
	cout.precision(6);
	cout.setf(ios::fixed);
	for(int ca=1; ca<=T; ca++){
		cout<<"Case #"<<ca<<":";
		cin>>N;
		vector<int> t;
		t.clear();
		int a[1000];
		for(int i=0; i<N; i++){
			cin>>s[i];
			t.push_back(s[i]);
		}
		sort(t.begin(), t.end());
		a[0] = t[0];
		for(int i=1; i<N; i++)
			a[i] = a[i-1] + t[i];	
		int i = N-1;
		double avg = 0;
		while(1){
			avg = a[i]+a[N-1];
			avg /= i+1;
			if(avg >= t[i])
				break;
			while(i>=0 && t[i] > avg)
				i--;	
			assert(i>=0);
		}
		for(int i=0; i<N; i++){
			double x = (avg-s[i])/a[N-1];
			if(x < 0)
				x = 0;
			x *= 100;
			cout<<" "<<x;
		}	
		cout<<endl;
	}
	return 0;
}
