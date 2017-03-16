#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;
string a[20];
string b[20];
int n,max1;
void func(int mask,int pos) {
	if(pos==n) {
		int temp=0,temp2;
		while(mask) {
			if(mask%2==1) {
				temp++;
			}
			mask=mask/2;
		}
		max1= max(max1,temp);
		return;
	}
	int x=0,y=0,z=mask;
	for(int i=0;i<n;i++) {
		if(i!=pos && z%2==0) {
			if(a[i].compare(a[pos])==0) {
				x=1;
			}
			if(b[i].compare(b[pos])==0) {
				y=1;
			}
		}
		if(x==1 && y==1) {
			int temp = mask | (1<<pos);
			func(temp,pos+1);
			break;
		}
		z = z/2;
	}
	func(mask,pos+1);
}
int main() {
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++) {
		scanf("%d",&n);
		for(int j=0;j<n;j++) {
			cin>>a[j];
			cin>>b[j];
		}
		max1=0;
		func(0,0);
		printf("Case #%d: %d\n",i,max1);
	}
	return 0;
}