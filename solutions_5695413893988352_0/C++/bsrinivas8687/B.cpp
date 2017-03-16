#include<bits/stdc++.h>
using namespace std;

#define in(Kavya) scanf("%lld",&Kavya);

typedef long long int ll;

ll TC,T,i;
char X[20],Y[20];

int main() {
	in(TC);
	for(T=1;T<=TC;++T) {
		memset(X,0,sizeof X);
		memset(Y,0,sizeof Y);
		scanf("%s %s",X,Y);
		ll Len=strlen(X);
		bool NumberOccured=false;
		for(i=0;i<Len;++i) {
			if(X[i]!='?' && Y[i]!='?') {
				NumberOccured=true;
				continue;
			}
			else if(!NumberOccured) {
				if(X[i]=='?' && Y[i]=='?') {
					X[i]='0';
					Y[i]='0';
				}
				else if(X[i]=='?' && Y[i]!='?') { NumberOccured=true; X[i]=Y[i]; }
				else if(X[i]!='?' && Y[i]=='?') { NumberOccured=true; Y[i]=X[i]; }
			}
			else {
				NumberOccured=true;
				if(X[i]=='?' && Y[i]!='?') X[i]=Y[i];
				else if(X[i]!='?' && Y[i]=='?') Y[i]=X[i];
				else if(X[i-1]<Y[i-1]) {
					X[i]='9';
					Y[i]='0';
				}
				else if(X[i-1]>Y[i-1]) {
					X[i]='0';
					Y[i]='9';
				}
				else X[i]=Y[i]='0';
			}
		}
		printf("Case #%lld: ",T);
		printf("%s %s\n",X,Y);
	}
	return 0;
}
