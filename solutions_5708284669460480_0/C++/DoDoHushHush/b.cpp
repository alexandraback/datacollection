#include <iostream>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;

int x[1234];
char m[1111];
char t[1111];

char a[8800000][11];

int p[11];
		int k,l,s;
int na;
int bbb(int f){
int ann=0;
	for(int i=1;i<=s-l+1;i++){
		bool fl=true;
		for(int j=0;j<l;j++){
			if(a[f][i+j]!=t[j]){
			fl=false;
			break;
			}
		}
		if(fl)ann++;
	}
	return ann;
}
void aaa(int d,int pp){
	if(d>s){
	na++;
		for(int i=1;i<=s;i++){
		a[na][i]=m[p[i]];
		}
		return;
	}
	for(int i=0;i<k;i++){
		p[d]=i;
		aaa(d+1,pp+1);
	}
}
int mm[8800000];
int main() {

	int tTTT;
	cin>>tTTT;
	for(int tt=1;tt<=tTTT;tt++){
	//cout<<tt<<" "<<
		cin>>k>>l>>s;
		cin>>m;
		cin>>t;
		na=0;
		for(int i=1;i<=s;i++)p[i]=0;
		aaa(1,1);
		int max=0;

		long long all=0;
		for(int i=1;i<=na;i++){
			int nn=bbb(i);
			//cout<<nn<<endl;
			all=all+nn;
			if(nn>max)max=nn;
		}
		double ex=double(all)/double(na);		
		double nana=(double(max)-ex);
		if((nana == (int)nana))
		{
		cout<<"Case #"<<tt<<": "<<nana;
		cout<<".0";
		cout<<endl;}
		else printf("Case #%d: %lf\n", tt,nana);
		
	}
	return 0;
}

