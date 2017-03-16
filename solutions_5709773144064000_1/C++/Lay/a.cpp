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

using namespace std;

int main()
{
	int T;
	cin>>T;

	for(int i=1;i<=T;i++){
		double c,f,x,res;
		cin>>c>>f>>x;
		int n=(int)ceil(-2/f-1+x/c);

		if(n<0) res=x/2;
		else{
			double d=0.0;
			for(int j=0;j<n;j++) d+=1/(2+j*f);
			res=c*d+x/(2+n*f);
		}

		printf("Case #%d: %.7f\n",i,res);

	}

	return 0;
}
