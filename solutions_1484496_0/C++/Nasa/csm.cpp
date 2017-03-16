#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int pos[2000010],last[2000010];

int main(){
	int mx,t,u,n,i,j,k,a[201],b[201],s,ss;
	cin>>t;
	for (u=0; u<t; u++){
		cin>>n;
		for (i=0; i<n; i++) cin>>a[i];
		sort(a,a+n);
		for (s=i=0; i<n; i++) s+=a[i];
		for (j=0; j<=s; j++) pos[j]=0;
		pos[0]=1;
		s=0; 
		cout<<"Case #"<<(u+1)<<":"<<endl;
		for (i=0; i<n; i++){
			for (j=0; j<=s; j++){
				if (pos[j]){
					if (pos[a[i]+j]){
						cout<<a[i];
						k=j;
						while(k){
							cout<<" "<<last[k];
							k-=last[k];
						}
						cout<<endl;
						k=a[i]+j;
						cout<<last[k];
						k-=last[k];
						while(k){
							cout<<" "<<last[k];
							k-=last[k];
						}
						cout<<endl;
						break;
					}
				}
			}				
			if (j<=s) break;
			for (j=s; j>=0; j--){
				if (pos[j]){
					pos[a[i]+j]=1;
					last[a[i]+j]=a[i];
				}
			}
			s+=a[i];
		}
		if (i==n) cout<<"Impossible\n"<<endl;
	}
	return 0;
}
