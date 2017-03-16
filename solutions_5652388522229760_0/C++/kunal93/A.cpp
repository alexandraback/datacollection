#include<bits/stdc++.h>
using namespace std;

vector<bool> seen;

int c;

void check(long long x){
	while(x){
		int d=x%10;
		x/=10;
		if(seen[d]==false){
			seen[d]=true;
			c++;
		}
	}
}

void eval(){
	int n;
	cin>>n;
	if(n==0)
		{
			cout<<"INSOMNIA\n";
			return;
		}
	seen.clear();
	seen.resize(10, false);
	c=0;
	long long v = 0;
	for(int i=1;c<10;i++){
		v+=n;
		check(v);
	}
	cout<<v<<endl;
}

int main(){
	int t;
	cin>>t;
	for(int te=1;te<=t;te++){
		cout<<"Case #"<<te<<": ";
		eval();
	}
}
