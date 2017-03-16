// #include <bits/stdc++.h>
#include "iostream"
#include "cstdio"
#include "algorithm"
#include "math.h"
#include "queue"
#include "map"
#include "set"
#include "stack"
#include "fstream"
#include "cstring"
#include "string"
#define L(x) (x<<1+1)
#define R(x) (x<<1+2)
#define REP(a,b) for(int a=0;a<b;a++)
#define REP1(a,b) for(int a=1;a<=b;a++)
#define RREP(a,b) for(int a=b-1;a>=0;a--)
#define RREP1(a,b) for(int a=b;a>0;a--)
#define ITR(a,b) for(;a!=b;a++)
using namespace std;
#define P 1000000007LL
#define MAXN 100
#define E7 10000000LL
typedef long long ll;

int m[5][5]={
	0,0,0,0,0,
	0,1,2,3,4,
	0,2,-1,4,-3,
	0,3,-4,-1,2,
	0,4,3,-2,-1};

int mul(int a,int b){
	if(a<0)return -mul(-a,b);
	if(b<0)return -mul(a,-b);
	return m[a][b];
}
int cti(char c){
	switch(c){
		case 'i':return 2;
		case 'j':return 3;
		case 'k':return 4;
	}
}

int exp(int val, int ex){
	// cout<<val<<' '<<ex<<endl;
	if(!ex)return 1;
	int e=mul(val,val);
	if(ex%2)return mul(val,exp(e,ex/2));
	return exp(e,ex/2);
}

bool check(string s,int l,int x){
	int val=1;
	int pos=0;
	bool fi=false;

	int count=0;
	while(true){
		val=mul(val,cti(s[pos++]));
		if(pos>=s.length()){
			count++;
			pos=0;
			if(count>=4)return false;
			if(--x<=0)return false;
		}
		if(!fi && val==cti('i')){
			count=-1;
			val=1;
			fi=true;
			continue;
		}
		if(fi && val==cti('j')){
			return true;
		}
	}
}

int main(){
	int T;
	cin>>T;
	REP(cs, T){
		int x,l;
		cin>>l>>x;
		string s;
		cin>>s;
		int val=1;
		REP(i,l)val=mul(val,cti(s[i]));
		string ans="NO";
		val=exp(val,x);
		if(val==-1 && check(s,l,x))ans="YES";
		cout<<"Case #"<<(cs+1)<<": "<<ans<<endl;
	}
	return 0;
}
