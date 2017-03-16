#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<iomanip>
#define ll long long
//#define for(i,b,n) for(int (i)=(b);(i)<(n);(i)++)
#define endl "\n"
using namespace std;
int ans1=0, ans2=0, mn = 100000;

int sz(int i){
	if(i>=100)return 3;
	else if(i>=10)return 2;
	else return 1;
}

bool match(string &a, int i){
	if(sz(i)>a.size())return false;
	int d[4];
	if(a.size()==3){
	
	d[3] = i%10; i/=10; d[2] = i%10; i/=10; d[1] = i%10;}
	else if(a.size()==2){
	
		d[2] = i%10; i/=10; d[1] = i%10;
	}
	else{
	
		d[1] = i%10; 
	}
	//for(int i=1;i<=2;i++)cout<<d[i]<<" ";cout<<endl;
	for(int j=a.size()-1;j>=0;j--){
		
		if(a[j]!='?'){
			if(a[j]!=(d[j+1]+'0')){
				//cout<<" "<<j<<" ";
				return false;
			}
		}
	}
	return true;
}

void good(string &a, int i, string &b, int j){
	
	

	if(match(a,i) && match(b,j)){
		if(abs(i-j)<mn){
			ans1 = i; ans2 = j; mn = abs(i-j);
			
		}
	}
	return;
}

void func(string &a, string &b){
	for(int i = 0;i<=999; i++){
		for(int j = 0; j<=999; j++){
			good(a,i,b,j);
		}
	}
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ll t, answer = 0;
	//cout<<match("?2",2);
	cin>>t;
	for(ll j = 1; j <= t; j++){
		ans1 = 0; ans2= 0; mn = 10000000;
		string a,b;
		cin>>a>>b;
		func(a,b);
		int cnt1 = a.size() - sz(ans1);
		int cnt2 = a.size() - sz(ans2);
		
		cout<<"Case #"<<j<<": ";
		for(int i=1;i<=cnt1;i++)cout<<0;
		
		cout<<ans1<<" ";
		for(int i=1;i<=cnt2;i++)cout<<0;

		cout<<ans2<<endl;
	}
	
	return  0;
}