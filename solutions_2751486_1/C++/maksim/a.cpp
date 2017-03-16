#include <cstdio>
#include <cmath>
#include <iostream>
#include <sstream>
#include <queue>
#include <map>
#include <vector>
#include <string>
#include <string.h>
#include <limits.h>
#define FOR(i,n) for(int i=0;i<(n);i++)
#define FORR(i,n) for(int i=(n)-1;i>=0;i--)
#define MAX 1000009
#define MOD 1000000
#define LL long long
#define PR pair<int,int>
#define MAP map<int,int>
#define VI vector<int>
#define PQUEUE priority_queue<PR >
#define FORM(i,n) for(auto i=n.begin();i!=n.end();i++)
using namespace std;



int L,N,T;
char a[MAX];
bool iscons(char c){
	return c!='a'&&c!='e'&&c!='i'&&c!='o'&&c!='u';
}
LL solve(){
	int i,j,pi=-1;
	LL r=0;
	for (int i = 0; i < a[i]!=0; i++)
	{
		if(iscons(a[i])){
			bool did=false;
			for(j=0;i+j<L && j<N && iscons(a[i+j]);j++);
			if(j==N){
				r+=(i-pi)*(L-(i+j)+1);
				pi=i;
			}else{
				
			}
		}
	}
	return r;
}

int main(){ 
	scanf("%d",&T);
	FOR(t,T){
		scanf("%c",a);
		scanf("%s",a);
		scanf("%d",&N);		
		L=strlen(a);
		LL r=solve();
		cout<<"Case #"<<(t+1)<<": "<<r<<endl;
	}
	
}
