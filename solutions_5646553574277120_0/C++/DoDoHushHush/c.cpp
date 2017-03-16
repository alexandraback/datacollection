#include <iostream>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;
int ca[33];
int cc[11];
int aa[11];
int vv[33];
int uu[63];
int un;
		int c,d,v;
void bbb(int d,int v){
if(d>un){
vv[v]=1;
return;
}
bbb(d+1,v);
bbb(d+1,v+uu[d]);
}
int nana;
void aaa(int l,int all){
if(l>15){
int nn=0;
	for(int i=1;i<=v;i++)vv[i]=0;
	un=0;
	for(int i=1;i<=15;i++){
	if(cc[i]==1)uu[++un]=i;
	}
	for(int i=1;i<=v;i++){
	if(ca[i]==1&&cc[i]==0)uu[++un]=i;
	}
		bbb(1,0);
		bool ff=true;
	for(int i=1;i<=v;i++){
	if(vv[i]!=1){
	ff=false;
	break;
	}
	}
	if(ff){
		if(all<nana)nana=all;
	}
return;
}

cc[l]=0;
aaa(l+1,all);
cc[l]=1;
if(ca[l]==1)aaa(l+1,all);
else aaa(l+1,all+1);

}
int main() {

	int tTTT;
	cin>>tTTT;
	for(int tt=1;tt<=tTTT;tt++){

		cin>>c>>d>>v;
		for(int i=1;i<=15;i++)cc[i]=0;
		for(int i=1;i<=v;i++)ca[i]=0;
		for(int i=1;i<=d;i++){
	int dd;	
cin>>dd;if(dd<=v)ca[dd]=1;}
		nana=v;
		aaa(1,0);
		cout<<"Case #"<<tt<<": "<<nana<<endl;
		
	}
	return 0;
}

