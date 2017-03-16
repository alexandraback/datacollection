#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <functional>
#include <set>
#include <complex>

using namespace std;

int main()
{
	int t;
	cin>>t;
	
	for(int T=1;T<=t;T++){

		int res=0,count=0;
		unsigned long long p,q;
		char dummy;
		scanf("%lld%c%lld",&p,&dummy,&q);
//		cout<<p<<"/"<<q<<endl;

		while((p!=0 && p!=q) && count<=40){
			count++;
			if(2*p<q) p*=2;
			else{
				if(res==0) res=count;
				p*=2;
				p-=q;
			}
		}

		if(count==41) printf("Case #%d: impossible\n",T);
		else printf("Case #%d: %d\n",T,res);

	}


	return 0;
}
