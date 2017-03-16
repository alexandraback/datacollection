//#include <bits/stdc++.h>
// author - Sameer Makker 
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
//#include<set>
#define ll long long 
#define pii pair<int,int>
#define f first
#define s second 
#define si(a) scanf("%d",&a)
#define sil(a) scanf("%lld",&a)
#define pi(a) printf("%d ",a)
#define pil(a) printf("%lld",a)
#define MOD 1000000007
using namespace std ;
vector<pii> v ;

ll a1,a2,mn=4000000000000000000LL; 
string s1,s2;
string A[1000],B[1000];
int f ;
void solve(map<string,int> p1,map<string,int> p2,int i,int ans,int n){
	if(i==n){
		f = max(f,ans);
		return ;
	}
	solve(p1,p2,i+1,ans,n);
	if(p1[A[i]]>=2&&p2[B[i]]>=2){
		p1[A[i]]--;p2[B[i]]--;
		solve(p1,p2,i+1,ans+1,n);
	}
}
int main(){
	
	int t,i,j,k,n,z;
	si(t);
	string a,b;
	for(i=1;i<=t;i++){
		si(n);
		f = 0;
		map<string,int> p1,p2;
		for(j=0;j<n;j++){
			cin>>a;
			cin>>b;
			A[i]=a;
			B[i]=b;
			p1[a]++;
			p2[b]++;
		}
		solve(p1,p2,0,0,n);
		printf("Case #%d: %d\n",i,f);
	}
	return 0;

}