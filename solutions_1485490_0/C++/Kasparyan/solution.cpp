#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <stack>
#include <map>
#pragma comment(linker, "/STACK:165777216")
using namespace std;
struct pnt{
	long long cnt;
	int tp;
};
pnt a[113];
pnt aa[113];
pnt b[113];
pnt bb[113];
int n, m;
long long mx=0;
int cc[20];
int top=0;
long long calc(int ind, int l,int r){
	long long ans=0,t;
		for(int i=l; i<=r; i++){
			if(aa[cc[ind]].tp==bb[i].tp){
				t=min(aa[cc[ind]].cnt,bb[i].cnt);
				aa[cc[ind]].cnt-=t;
				bb[i].cnt-=t;
				ans+=t;
			}
		}
		return ans;
}
void updateaa(){
	for(int i=0; i<n; i++){
		aa[i]=a[i];
	}
	for(int i=0; i<m; i++){
		bb[i]=b[i];
	}
}
void slv(){
	long long ans=0,t;
	if(top==1){
		ans=calc(0,0,m-1);
		mx=max(mx,ans);
	}
	ans=0;
	if(top==2){
		for(int i=0; i<m-1; i++){
			ans=calc(0,0,i)+calc(1,i,m-1);
			mx=max(mx,ans);
			updateaa();
		}
	}
	ans=0;
	if(top==3){
		for(int i=0; i<m; i++){
			for(int j=i+1; j<m-1; j++){
				ans=calc(0,0,i)+calc(1,i,j)+calc(2,j,m-1);
				mx=max(mx,ans);
				updateaa();
			}
		}
	}
}
int main(){
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	int t;
	cin>>t;
	for(int i=0; i<t; i++){
		cin>>n>>m;
		for(int j=0; j<n; j++){
			cin>>a[j].cnt>>a[j].tp;
		}
		for(int j=0; j<m; j++){
			cin>>b[j].cnt>>b[j].tp;
		}
		mx=0;
		for(int j=1; j<(1<<n); j++){
			int tt=j;
			int c=0;
			top=0;
			while(tt){
				if(tt%2){
					cc[top]=c;
					top++;
				}
				tt/=2;
				c++;
			}
			updateaa();
			slv();
		}

		cout<<"Case #"<<i+1<<": "<<mx<<endl;
	}
	return 0;
}