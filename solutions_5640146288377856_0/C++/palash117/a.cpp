#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream fin("a.in");
	ofstream fout("a.out");
	int t,cas,r,c,w,ans;
	fin>>t;
	cas=0;
	while(t--){
		cas++;
		fin>>r>>c>>w;
		ans=0;
		ans+=w;
		c-=w;
		if(c%w==0){
			ans=ans+c/w;
		}
		else ans=ans+c/w + 1;
		cout<<ans<<"\n";
		fout<<"Case #"<<cas<<": "<<ans<<"\n";
	}
}
