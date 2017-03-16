#include<iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int tn=0;tn<t;tn++) {
		long long r,t;
		cin>>r>>t;
		long long mini = 1;
		long long maxi = min(t/r,707106800LL)+1;
		while(maxi>mini+1) {
			long long mid = (maxi+mini)/2;
			if( mid+2*(mid*r+mid*(mid-1)) <= t )
				mini = mid;
			else
				maxi = mid;
		}
		cout<<"Case #"<<tn+1<<": "<<mini<<endl;
	}

}

