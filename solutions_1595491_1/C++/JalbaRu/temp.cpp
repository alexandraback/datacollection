#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	freopen("B-large.in","r",stdin);
	//freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	cin>>T;
	for(int t=0;t<T;t++){
		int n,s,p;
		cin>>n>>s>>p;
		vector<int> a(n);
		for(int i=0;i<n;i++) cin>>a[i];
		int g=0,m=0;
		for(int i=0;i<n;i++)
			if(a[i]/3>=p || (a[i]/3+1==p && a[i]%3>0)) g++;
			else{
				int h=a[i]/3;
				if(a[i]%3==2) if(h+2>=p) m++;
				if(a[i]%3==0 && a[i]>0) if(h+1>=p) m++;
			}
		int ans=g+min(s,m);
		printf("Case #%d: %d\n",t+1,ans);
	}
}