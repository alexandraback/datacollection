#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
using namespace std;
long long int gcd(long long int a,long long int b){
	if(b==0)return a;
	if(b>a)return gcd(b,a);
	return gcd(b,a%b);
}
int main(){
	long long int t,te,a,b,i,j,k,ans;
	ifstream f1;
	ofstream f2;
	f1.open("input.txt");
	f2.open("output.txt");
	f1>>t;
	for(te=0;te<t;te++){
		char c;
		f1>>a>>c>>b;
		i=gcd(a,b);
		a/=i;
		b/=i;
		ans=-2;
		if(a==b)ans=0;
		for(i=b;i>1&&i%2==0;i/=2);
		if(i>1)ans =-1;
		else if(ans==-2){
			ans=1;
			while((a*2)<b){
				b/=2;
				ans++;
			}
		}
		if(ans!=-1){
			cout<<"Case #"<<te+1<<": "<<ans<<"\n";
			f2<<"Case #"<<te+1<<": "<<ans<<"\n";
		}
		else{
			cout<<"Case #"<<te+1<<": impossible\n";
			f2<<"Case #"<<te+1<<": impossible\n";
		}
	}
	return 0;
}
