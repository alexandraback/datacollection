/*
by george_cheng
*/
#include<iostream>
using namespace std;
long long max(long long x,long long y){
	if (x>y)return x;
	return y;
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int z;
	cin>>z;
	for (int i=0;i<z;++i){
	long long r,t;
	cin>>r>>t;
	cout<<"Case #"<<i+1<<": ";
	long long pos=long long(((1-2*r)+sqrt(double(double(2*r-1)*double(2*r-1)+8*double(t)))))/4;
	long long ans=0;
	for (long long j=max(pos-10,0);j<pos+10;++j){
		if (((2*r+1)*j+2*(j-1)*j<=t) && ((2*r+1)*(j+1)+2*(j+1)*j>t)){
			ans=j;
			break;
		}
	}
	cout<<ans<<endl;

		
	}
}