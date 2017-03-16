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
void solve(int curr,int n,ll fr,ll se){
	if(curr==n){
		
		if(abs(fr-se)<mn){
			mn = abs(fr-se);
			a1 = fr;
			a2 = se;
			
		}
		else if(abs(fr-se)==mn){
			if(fr<a1){
				a1 = fr ;
				a2 = se ;
				
			}else if(fr==a1){
				if(se<a2){
					a2 = se ;
					
				}
			}
		}
		return ;
	}
	if(fr==se){
		if(s1[curr]=='?' && s2[curr]=='?'){
			solve(curr+1,n,10*fr+1,10*se);
			solve(curr+1,n,10*fr,10*se+1);
			solve(curr+1,n,10*fr,10*se);
		}
		else if(s1[curr]=='?'){
			int num = s2[curr]-'0';
			solve(curr+1,n,10*fr+num,10*se+num);
			solve(curr+1,n,10*fr+(num+9)%10,10*se+num);
			solve(curr+1,n,10*fr+(num+1)%10,10*se+num);
		}else if(s2[curr]=='?'){
			int num = s1[curr]-'0';
			solve(curr+1,n,10*fr+num,10*se+num);
			solve(curr+1,n,10*fr+num,10*se+(num+1)%10);
			solve(curr+1,n,10*fr+num,10*se+(num+9)%10);
		}else{
			solve(curr+1,n,10*fr+s1[curr]-'0',10*se+s2[curr]-'0');
		}
	}
	else{
		if(fr>se){
			if(s1[curr]=='?' && s2[curr]=='?'){
				solve(curr+1,n,10*fr,10*se+9);
			}
			else if(s1[curr]=='?'){
				solve(curr+1,n,10*fr,10*se+s2[curr]-'0');
			}else if(s2[curr]=='?'){
				solve(curr+1,n,10*fr+s1[curr]-'0',10*se+9);
			}else{
				solve(curr+1,n,10*fr+s1[curr]-'0',10*se+s2[curr]-'0');
			}
		}else{
			if(s1[curr]=='?' && s2[curr]=='?'){
				solve(curr+1,n,10*fr+9,10*se);
			}
			else if(s1[curr]=='?'){
				solve(curr+1,n,10*fr+9,10*se+s2[curr]-'0');
			}else if(s2[curr]=='?'){
				solve(curr+1,n,10*fr+s1[curr]-'0',10*se);
			}else{
				solve(curr+1,n,10*fr+s1[curr]-'0',10*se+s2[curr]-'0');
			}
		}
	}
}

int main(){
	
	int t,i,j,k,n,z;
	si(t);
	for(i=1;i<=t;i++){
		char r1[20],r2[20];
		cin>>s1>>s2;
		mn=100000000000000000LL;
		solve(0,s1.length(),0,0);
		printf("Case #%d: ",i);
		//cout<<a1<<" "<<a2<<"\n";
		ll temp = a1 ;
		n=s1.length();
		for(k=0;k<n;k++){
			r1[k]='0';
			r2[k]='0';
		}
		int k = n-1;
		while(a1>0){
			r1[k]=a1%10+'0';
			k--;
			a1/=10;
		}
		k=n-1;
		while(a2>0){
			r2[k]=a2%10+'0';
			k--;
			a2/=10;
		}
		
		for(k=0;k<n;k++){
			cout<<r1[k];
		}
		cout<<" ";
		for(k=0;k<n;k++){
			cout<<r2[k];
		}
		printf("\n");
	}
	return 0;

}