#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>

using namespace std;

int main(int argc, char** argv){

	int T;
	scanf(" %d",&T);
	long long r;
	long long t;

	long long ans;
	long long inc;

	for(int i=1;i<=T;i++)
	{
		scanf(" %I64d %I64d",&r, &t);
		ans=1;

		while(2*ans*ans + ans*(2*r -1) <= t){ans*=10;}
		ans = ans/10;
		inc = ans;

		while(inc!=0)
		{
			while(2*(ans+inc)*(ans+inc) + (ans+inc)*(2*r -1) <=t) ans+=inc;
			inc = inc/10;
		}



		printf("Case #%d: %I64d\n", i, ans);
	}


	return 0;
}