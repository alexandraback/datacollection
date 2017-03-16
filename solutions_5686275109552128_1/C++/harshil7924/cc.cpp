
/***
	AUTHOR :
	Harshil Shah
	IIT INDORE
***/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
int main(){
	freopen("B-large.in","r",stdin);
	freopen("output1.txt","w",stdout);
	int t,D;
	cin>>t;
	int p[1011];
	int cnt=0;
	while(t--){
		cnt++;
		cin>>D;
		int maxpile=0;
		for(int i=0;i<D;i++){
			cin>>p[i];
			maxpile=max(maxpile,p[i]);
		}
		ll ans=100000;
		ll c=0;
		for(int sz=1;sz<=maxpile;sz++){
			c=0;
			for(int i=0;i<D;i++){
				c=c+p[i]/sz;
				if(p[i]%sz!=0){
					c++;
				}
				c--;
			}
			ans=min(ans,c+sz);
		}
		cout<<"Case #"<<cnt<<": "<<ans<<"\n";
	}
}
