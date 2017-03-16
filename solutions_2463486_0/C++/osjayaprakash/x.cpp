#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
vector<ll> lis;

bool isPalindrome(ll n){
	int d[20] = {0};
	int nd=0;
	while(n!=0){
		d[nd] = n % 10;
		nd++;
		n = n / 10;
	}
	for(int i=0,j=nd-1;i<j;i++,j--){
		if(d[i]!=d[j]) 
			return false;
	}
	return true;
}

void preProcess(){
	ll n=0;
	for(int i=1;i<=10000005;i++){
		n = i;
		n = n*n;
		if(isPalindrome(n) && isPalindrome(i))
			lis.push_back(n);
	}
}


int sol(){
	int s,e;
	cin >> s >> e;
	int sz=lis.size();
	int s1=0,s2=0;
	for(;s1<sz;s1++)
		if(lis[s1]>=s)
			break;
	s2=s1;
	for(;s2<sz;s2++)
		if(lis[s2]>e)
			break;
	return s2-s1;
}

int main(){
	preProcess();
	int t=0;
//	for(int i=0;i<lis.size();i++)
//		cout << lis[i]<<endl;
	cin >> t;
	for(int i=1;i<=t;i++){
		cout << "Case #"<<i<< ": " << sol()<< endl;
	}		
}
