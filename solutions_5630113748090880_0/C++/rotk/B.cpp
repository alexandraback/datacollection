#include <bits/stdc++.h>
#define MAXN 1000000
#define long long ll
using namespace std;
int th;

void openFile(){
	switch(th){
		case 0:
			freopen("inp","r",stdin);
  			freopen("out","w",stdout);
  			break;
		case 1: 
			freopen("B-small-attempt0.in","r",stdin);
  			freopen("B-small-attempt0.ou","w",stdout);
  			break;
  		case 2:
  			freopen("B-large.in","r",stdin);
  			freopen("B-large.ou","w",stdout);
  			break;
	}
  	
}
void mainWork(){
	int test;
	int n,t;
	int a[2511];
	cin>>test;
	for(int qq=1;qq<=test;qq++){
		cout<<"Case #"<<qq<<": ";
		cin>>n;
		///init
		for(int i=0;i<2510;i++)a[i]=0;
		int maxa=0;
		///
		for(int i=1;i<=2*n-1;i++){
			for(int j=1;j<=n;j++){
				cin>>t;
				maxa=max(maxa,t);
				a[t]++;
			}
		}
		for(int i=0;i<=maxa;i++)
		if(a[i]%2==1) cout<<i<<" ";
		cout<<endl;
	}
}
int main(){
	cin>>th;
	openFile();
	mainWork();
	return 0;
}
