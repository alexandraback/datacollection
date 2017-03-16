#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

long long i,j,k,l,m,n,t;
double gagaia;
unsigned long long init,r;

unsigned long long min(unsigned long long a, unsigned long long b){
	if (a>b) return b; else return a;
}

int main(){
	freopen("output.txt","w",stdout);
	cin>>t;
	for (i=1;i<=t;i++){
		cin>>r>>init;
		long long ans = 0;
		unsigned long long big = 1000000000LL;
		big *= 1000000000LL;
		big *= 2LL;
		big += 5;
		unsigned long long left = 0, right = min(big/(2LL*r),1000000000);
		//cout<<left<<' '<<right<<endl;
		while(left<=right){
			unsigned long long middle = (left + right ) /2;
			if (middle*(2*r+2*middle-1)<=init) {
				left = middle + 1; ans = middle;
			} else
			{
				right = middle - 1;		
			}
		}
		cout<<"Case #"<<i<<": "<<ans<<"\n";
	}
	return 0;
}
