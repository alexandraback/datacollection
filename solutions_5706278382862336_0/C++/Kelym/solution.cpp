#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	int __;
	cin>>__;
	for(int _=1;_<=__;++_){
		char a;
		long long n = 0, m =0, k = 0,t=0;
		cin>>a;
		while(a!='/'){
			n = n*10 + (a-'0');
			cin>>a;
		}
		cin>>m;

		k = m;
		while((k%2==0) && (n%k!=0)) k/=2,++t;
		if((n%k!=0)){printf("Case #%d: impossible\n",_);continue;}

		int p=0,q=0;
		n=n/k;
		while(n>1) n/=2,++p;
		k=p+40-t;
		k=40-k;

		printf("Case #%d: %d\n",_,k);
	}
	return 0;
}
