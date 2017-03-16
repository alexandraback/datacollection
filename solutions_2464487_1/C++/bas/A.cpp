#include<iostream>
#include<vector>
#include<string>
#include<cmath>

#define eps 1e-16

using namespace std;

unsigned long long f(unsigned long long n, unsigned long long r){
//	cout<<r<<" "<<double(n*n*2+(r*2-1)*n)<<" ";
	return n*n*2+(r*2-1)*n;
}
int main(){
	unsigned long long r,t, T;
	unsigned long long n;
	cin>>T;
	for(int i=1; i<=T; i++){
	cin>>r>>t;
	n=1; long long lt=1, rt=1;
	while(f(rt, r)<t){lt=rt; rt*=2;  }
	if(f(rt, r)==t){
		n = rt;
	}else if(f(lt, r)==t){
		n=lt;
	} else if(f(lt, r)>t){
		n=0;
	} else
	while(true){
		unsigned long long c = (rt+lt)/2;
		if(f(c, r)<=t && f(c+1, r)>t){
			n=c; break;
		}else{
			if(f(c, r)>t)rt=c; else lt=c;

		}
	}

	cout<<"Case #"<<i<<": "<<n<<"\n";
	}
	
}
