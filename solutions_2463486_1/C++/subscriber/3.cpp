#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

int l;
string s,q;

string sq(){
	string u="";
	for (int i=0;i<q.size()*2-1;i++)u+='0';
	for (int i=0;i<q.size();i++)for (int j=0;j<q.size();j++)u[i+j]+=(q[i]-'0')*(q[j]-'0');
	return u;
}

int rec(int g,int o){
	if (o>9)return 0;
	if (g==l/2){
		cout <<  sq() <<   endl;
		return 1;
	}
	int r=0;
	for (int i=0;i<=2;i++){
		q[g]=q[l-1-g]='0'+i;
		r+=rec(g+1,o+i*i*2);
	}
	q[g]=q[l-1-g]='0';
	return r;
}

int gen(){
	int ans=0;
	cout <<  1 <<   endl;
	cout <<  4 <<   endl;
	cout <<  9 <<   endl;
	for (l=2;l+l-1<=101;l++)for (int fi=1;fi<=2;fi++){
		q="";
		for (int i=0;i<l;i++)q+='0';
		q[0]=q[l-1]=fi+'0';
		if (l%2==0){
			ans+=rec(1,fi*fi*2);
		}else for (int d=0;d<=3;d++){
			q[l/2]=d+'0';
			ans+=rec(1,fi*fi*2+d*d);
               	}
	}
}

int main(){
	freopen("1.in","r",stdin);	
	freopen("1.out","w",stdout);	
	gen();
	return 0;
}
