#include<cstdio>
#include<iostream>
using namespace std;

int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int testcase,test;
	long long r,t,l,a,d,mid;
	scanf("%d",&testcase);
	for (test=1;test<=testcase;test++) {
		cin>>r>>t;
		a=2*r+1;
		d=4;
		l=1;r=1100000000;
		while (l<=r) {
			mid=(l+r)/2;
			if (mid<=t*2/(a+a+d*(mid-1))) l=mid+1;
			else r=mid-1;
		}
		cout<<"Case #"<<test<<": "<<l-1<<endl;
	}
}
