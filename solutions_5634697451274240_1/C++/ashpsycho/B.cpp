#include <bits/stdc++.h>
#include <stdio.h>
#define T pair<int,int>
#define x first
#define y second
using namespace std;
int main(){
	long long t,te,i,j,k,m,ans;
	cin>>t;
	string n;
	for(te=0;te<t;te++){
		cin>>n;
		for(i=ans=0;i<n.size();){
			for(j=i+1;j<n.size() && n[j]==n[i];j++);
			ans++;
			i=j;
		}
		if(n[n.size()-1]=='+')ans--;
		cout<<"Case #"<<(te+1)<<": "<<ans<<"\n";
	//	printf("Case #%d: %.9Lf\n",te+1,ans);

	}
	return 0;
}