#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
typedef long long LL;
int main(){
	freopen("A-large.in","r",stdin);
	freopen("A.out","w", stdout);
	int T;
	int cas = 0;
	for (cin>>T;T--;){
		LL t, s;
		cin>>s>>t;
		LL l = 0, r = (LL)100000*(LL)100000;
		while (l+1<r){
			LL mid = (l+r)/2;
			if (2*mid + 2*s-1 <= (t/mid)){
				l = mid;
			}else{
				r = mid;
			}
		}
		LL n = l;
		cas++;
		cout<<"Case #"<<cas<<": "<<n<<endl;
	}
	return 0;

}
