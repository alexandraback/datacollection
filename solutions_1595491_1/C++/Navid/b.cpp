#include<iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int tn=0;tn<t;tn++) {
		int n,p,s;
		cin>>n>>s>>p;
		int ans = 0;
		int pos = 0;
		for(int i=0;i<n;i++) {
			int num;
			cin>>num;
			if(num>=p+2*max(p-1,0))
				ans++;
			else
				if(num==p+2*max(p-2,0) || num==p+max(p-1,0)+max(p-2,0))
					pos++;
		}
		ans+=min(pos,s);
		cout<<"Case #"<<tn+1<<": "<<ans<<endl;
	}

}

