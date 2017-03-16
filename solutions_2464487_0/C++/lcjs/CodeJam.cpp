#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>

using namespace std;

int main(int argc, char** argv){

	int T;
	scanf(" %d",&T);
	int r;
	int t;

	double td;
	double rd;
	int ans;

	for(int i=1;i<=T;i++)
	{
		scanf(" %d %d",&r, &t);
		td=(double)t;
		rd=(double)r;
		ans=0;
		while(2*ans*ans + ans*(2*r -1) <=t) ans++;
		printf("Case #%d: %d\n", i, ans-1);
	}


	return 0;
}
