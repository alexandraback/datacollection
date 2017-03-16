#include <bits/stdc++.h>

using namespace std;
#define int long long
int rev(int x){
	int res=0;
	while(x>0){
		res*=10;
		res+=x%10;
		x/=10;
	}
	return res;
}
int digit(int x){
	int res=0;
	while(x>0){
		res++;
		x/=10;
	}
	return res;
}
int pow10(int p){
	int res=1; 
	for(int i=0;i<p;i++){
		res*=10;
	}
	return res;
}
int to1001(int x){
	int z=digit(x);
	x-=pow10(digit(x)-1)+1;
//	cout<<x<<' ';
	stringstream st;
	string s,s2;
	st<<x;
	st>>s2;
	while(s2.size()<z){
		s2="0"+s2;
	}
	s=s2;
	for(int i=0;i<s2.size()/2;i++){
		s2[i]='0';
	}
	int res;
	st.clear();
	st<<s2;
	st>>res;
//	cout<<res<<' ';
	int newv=0;
	for(int i=0;i<s.size()/2;i++){
		res+=(s[i]-'0')*pow10(i);
		newv+=(s[i]-'0')*pow10(i);
	}
//	cout<<res<<endl;
	if(newv>=1)res++;
	return res;
}
#undef int
int main(){
	#define int long long
	int tc;cin>>tc;
	int i=0;
//	for(int j=1;j<=100000;j++){
	while(tc-->0){
//		if(j%100==0)cout<<"process: "<<j<<endl;
		i++;
		int n;cin>>n;
//		n=i;
		int ans=0;
		while(n>=11){
			if(n%10==0)n-=1,ans+=1;
//			cout<<to1001(n)<<endl;
			ans+=to1001(n);
			n=pow10(digit(n)-1)+1;
			n-=2,ans+=2;
		}
		ans+=n-1;
		cout<<"Case #"<<i<<": "<<ans+1<<endl;
	}
	return 0;
}
