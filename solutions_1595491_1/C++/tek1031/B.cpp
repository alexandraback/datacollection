#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n,s,p,N;
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>n>>s>>p;
		int ans=0;
		vector<int> t(n);
		for(int k=0;k<n;k++)
			cin>>t[k];

		sort(t.begin(),t.end(),greater<int>());

		for(int k=0;k<n;k++){
			if(t[k]>=3*p-2){ans++;}
			else{
				if(s>=1){
					if(t[k]>=max(p,3*p-4)){ans++;s--;}
				}
			}
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;;
	}
}