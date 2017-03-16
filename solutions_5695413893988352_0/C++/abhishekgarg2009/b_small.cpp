#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;
char a[20];
char b[20];
vector<int>v,v2;
int l;
void func1(int i) {
	if(i==l) {
		int num=0;
		for(int j=0;j<l;j++){
			num=num*10+(a[j]-'0');
		}
		v.push_back(num);
		return;
	}
	if(a[i]=='?') {
		for(int j=0;j<10;j++) {
			a[i]='0'+j;
			func1(i+1);
		}
		a[i]='?';
	} else {
		func1(i+1);
	}
}
void func2(int i) {
	if(i==l) {
		int num=0;
		for(int j=0;j<l;j++){
			num=num*10+(b[j]-'0');
		}
		v2.push_back(num);
		return;
	}
	if(b[i]=='?') {
		for(int j=0;j<10;j++) {
			b[i]='0'+j;
			func2(i+1);
		}
		b[i]='?';
	} else {
		func2(i+1);
	}
}
int myAbs(int x) {
	if(x<0) {
		x = x*(-1);
	}
	return x;
}
int main() {
	int t,ans1,ans2,ans;
	scanf("%d",&t);
	for(int i=1;i<=t;i++) {
		scanf("%s",a);
		scanf("%s",b);
		l = strlen(a);
		func1(0);
		func2(0);
		sort(v.begin(),v.end());
		sort(v2.begin(),v2.end());
		ans1=0;
		ans2=0;
		ans=myAbs(v2[0]-v[0]);
		for(int j=0;j<v.size();j++) {
			for(int k=0;k<v2.size();k++) {
				if(myAbs(v2[k]-v[j])<ans) {
					ans=myAbs(v2[k]-v[j]);
					ans1=j;
					ans2=k;
				}
			}
		}
		printf("Case #%d: ",i);
		for(int j=l-1;j>=0;j--) {
			a[j] = v[ans1]%10+'0';
			v[ans1]/=10;
			b[j] = v2[ans2]%10+'0';
			v2[ans2]/=10;
		}
		v.clear();
		v2.clear();
		printf("%s %s\n",a,b);
	}
	return 0;
}