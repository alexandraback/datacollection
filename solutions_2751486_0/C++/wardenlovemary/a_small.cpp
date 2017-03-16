#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n,k;
string s;

bool vowel(char ch){
	if(ch=='a')return true;
	if(ch=='e')return true;
	if(ch=='i')return true;
	if(ch=='o')return true;
	if(ch=='u')return true;
	return false;
}

bool check(string s, int k){
	int v[555],len=s.length(),res=0;
	v[0]=!vowel(s[0]);
	res=v[0];
	for(int i=1;i<len;i++){
		if(vowel(s[i]))v[i]=0;
		else v[i]=v[i-1]+1;
		res=max(res,v[i]);
	}
	return (res>=k);
}

int main(){
	//freopen("a-small.in","r",stdin);
	//freopen("a-small.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s>>k;
		int len=s.length(),ans=0;
		for(int x=0;x<len;x++)
			for(int y=x;y<len;y++)
				if(check(s.substr(x,y-x+1),k))
					ans++;
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
	
	return 0;
}