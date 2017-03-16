#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++){
		int r,c,w;
		cin>>r>>c>>w;

		int ha;
		if(c%w==0)ha=(c/w)+(w-1);
		else ha=(c/w)+w;
		cout<<"Case #"<<tt<<": "<<ha+(r-1)*(c/w)<<endl;

	}
	return 0;
}

