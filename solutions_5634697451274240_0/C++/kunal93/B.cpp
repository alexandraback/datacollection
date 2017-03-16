#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int l;

void flip(int x){
	for(int i=0;i<=x/2;i++)
		{
			swap(a[i],a[x-i]);
			a[i]= -1 * a[i];
			a[x-i]= -1 * a[x-i];
		}
	if(x%2==0){
		a[x/2]*=-1;
	}
}

void eval(){
	string s;
	cin>>s;
	int c=0;
	l = s.size();
	a.clear();
	a.resize(l, -1);
	for(int i=0;i<l;i++){
		if(s[i]=='+') a[i]=1;
	}
	for(int i=0;i<l-1;i++){
		if(a[i]!=a[i+1]){
			flip(i);
			c++;
		}
	}
	if(a[l-1]==-1)
		c++;
	cout<<c<<endl;
}
int main()
{
	int t;
	cin>>t;
	for(int te=1;te<=t;te++){
		cout<<"Case #"<<te<<": ";
		eval();
	}
}
