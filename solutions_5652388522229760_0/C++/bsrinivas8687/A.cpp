#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int i,T,j,N,k,Len;

int main() {
	cin >> T;
	for(i=1;i<=T;++i) {
		bool Numbers[10]={0};
		cin >> N;
		if(N==0) {
			cout << "Case #" << i << ": INSOMNIA" << endl;
		}
		else {
			int j=1,tmpN=N;
			while(j) {
				char Str[100]={0};
				sprintf(Str,"%d",tmpN);
				Len=strlen(Str);
				for(k=0;k<Len;++k) Numbers[Str[k]-'0']=true;
				for(k=0;k<10;++k) if(!Numbers[k]) break;
				if(k==10) break;
				++j;
				tmpN=N*j;
			}
			cout << "Case #" << i << ": " << tmpN << endl;
		}
	}
	return 0;
}
