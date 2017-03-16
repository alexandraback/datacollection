#include <iostream>
#include <math.h>

using namespace std;

int T,D,num[1005];

int main() {
	cin>>T;
	for (int t=1; t<=T; t++) {
		cin>>D;
		int max=0;
		for (int i=0; i<D; i++)  {
			cin>>num[i];
			if (num[i]>max) max=num[i];
		}
		int ans=max;
		for (int rmax=1; rmax<=max; rmax++) {
			int count=0;
			for (int i=0; i<D; i++) {
				if (num[i]>rmax) {
					//cout<<ceil(1.0*num[i]/rmax)<<endl;
					count+=ceil(1.0*num[i]/rmax)-1;
				}
			}
			//cout<<rmax<<": "<<count<<'+'<<rmax<<endl;
			count+=rmax;
			if (count<ans) ans=count;
		}
		cout<<"Case #"<<t<<": "<<ans<<endl;

	}
	return 0;
}