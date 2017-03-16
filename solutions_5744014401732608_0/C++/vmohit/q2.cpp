#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define vll vector<long long>

int main(){
	int Te;
	char ch;
	cin>>Te;
	vll pows(60);
	pows[0]=1;
	for(int i=1;i<60;i++){
		pows[i]=2*pows[i-1];
	}
	for(int te=1;te<=Te;te++){
		int B;
		cin>>B;
		ll M;
		cin>>M;
		cout<<"Case #"<<te<<": ";
		if(M>pows[B-2]){
			cout<<"IMPOSSIBLE\n";
		}
		else{
			cout<<"POSSIBLE\n";
			if(M==pows[B-2]){
				for(int i=1;i<=B;i++){
					for(int j=1;j<=B;j++){
						if(i<j)cout<<1<<" ";
						else{
							cout<<0<<" ";
						}
					}
					cout<<endl;
				}
			}
			else{
				vector<int> ans(B+1,0);
				ll f=1;
				int i=1;
				while(f<=M){
					if((f^M)<M){
						ans[i+1]=1;
					}
					i++;
					f=f*2;
				}
				for(int i=1;i<=B;i++){
					for(int j=1;j<=B-1;j++){
						if(i<j)cout<<1<<" ";
						else{
							cout<<0<<" ";
						}
					}
					cout<<ans[i];
					cout<<endl;
				}
			}
		}
	}

	return 0;
}