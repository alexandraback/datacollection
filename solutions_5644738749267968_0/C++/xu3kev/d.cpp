#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int TT;
	cin>>TT;
	int ans1;
	int ans2;
	int n;
	double a[2000];
	double b[2000];
	int p;
	for(int T=1;T<=TT;++T){
		cin>>n;
		for(int i=0;i<n;++i){
			cin>>a[i];
		}
		for(int i=0;i<n;++i){
			cin>>b[i];
		}
		sort(a,a+n);
		sort(b,b+n);
		p=n-1;
		ans1=0;
		for(int i=n-1;i>=0;--i){
			while(p>=0&&b[p]>=a[i]){
				--p;
			}
			if(p>=0&&b[p]<a[i]){
				++ans1;
				--p;
			}
		}
		p=0;
		ans2=0;
		for(int i=0;i<n;++i){
			while(p<n&&b[p]<=a[i]){
				++p;
			}
			if(p<n&&b[p]>a[i]){
				++ans2;
				++p;
			}
		}
		
		ans2=n-ans2;
		
		
		printf("Case #%d: %d %d\n",T,ans1,ans2);
	}
	return 0;
}
