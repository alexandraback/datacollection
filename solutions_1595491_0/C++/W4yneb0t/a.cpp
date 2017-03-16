#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
typedef long long ll;
int n,s,p;
int sc[103];
int main(){
	int t;
	cin>>t;
	int ss[2][2];
	int x,y;
	int r;
	for(int z=1;z<=t;z++){
		ss[0][0]=0;
		ss[0][1]=0;
		ss[1][0]=0;
		ss[1][1]=0;
		cin>>n>>s>>p;
		for(int i=0;i<n;i++){
			x=0;
			y=0;
			cin>>sc[i];
			if(sc[i]-p>=(p-1)*2)
				x=1;
			if(sc[i]-p>=(p-2)*2 && sc[i]>=2 && sc[i]<=28)
				y=1;
			ss[x][y]++;
		}
		r=0;
		if(ss[0][1]>=s)
			r=s+ss[1][0]+ss[1][1];
		else
			r=ss[0][1]+ss[1][1]+ss[1][0];
		cout<<"Case #"<<z<<": "<<r;
		cout<<endl;
	}
	return 0;
}
