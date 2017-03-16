#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int tn=0;tn<t;tn++) {
		int a,n;
		cin>>a>>n;
		vector<int> motes;
		for(int i=0;i<n;i++) {
			int temp;
			cin>>temp;
			motes.push_back(temp);
		}
		sort(motes.begin(),motes.end());
		int ans = n;
		int temp = 0;
		if(a>1) {
			for(int i=0;i<n;i++) {
				if(a<=motes[i]) {
					ans = min(ans,temp+n-i);
					while(a<=motes[i]) {
						a+=a-1;
						temp++;
					}
				}
				a+=motes[i];
			}
			ans = min(ans,temp);
		}
		cout<<"Case #"<<tn+1<<": "<<ans<<endl;
	}
}

