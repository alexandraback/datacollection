#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int a[20];
int num(int k){
	int ret=0;
	for(int i=k; i>=1; i--)
		ret=ret*10+a[i];
	for(int i=a[0]; i>k; i--)
		ret=ret*10+a[i];
	return ret;
}
int main(){
	freopen("C-large.in","r", stdin);
	freopen("c-large-out.txt","w", stdout);
	int T; cin>>T;
	for(int cas=1; cas<=T; cas++){
		int A, B; cin>>A>>B;
		int ans=0;
		for(int n=A; n<B; n++){
			a[0]=0;
			for(int t=n; t>0; t/=10)
				a[++a[0]]=t%10;
			map<int, int> mp;
			for(int j=1; j<=a[0]; j++){
				int k=num(j);
				if(k>n && k<=B) mp[k]++;
			}
			ans+=mp.size();
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}