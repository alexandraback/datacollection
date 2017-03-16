#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int i,T,j,Len,Count;
char S[105];
bool PlusOccured,MinusOccured;

int main() {
	cin >> T;
	for(i=1;i<=T;++i) {
		Count=0;
		memset(S,0,sizeof S);
		cin >> S;
		Len=strlen(S);
		PlusOccured=false;
		MinusOccured=false;
		if(S[0]=='+') PlusOccured=true;
		else MinusOccured=true;
		j=1;
		while(j<Len) {
			for(;j<Len;++j) {
				if(S[j]=='+' && PlusOccured) continue;
				else if(S[j]=='-' && MinusOccured) continue;
				else break;
			}
			if(PlusOccured) {
				PlusOccured=false;
				MinusOccured=true;
			}
			else {
				PlusOccured=true;
				MinusOccured=false;
			}
			++Count;
		}
		if(S[Len-1]=='+') --Count;
		if(Len==1 && S[Len-1]=='+') Count=0;
		if(Len==1 && S[Len-1]=='-') Count=1;
		cout << "Case #" << i << ": " << Count << endl;
	}
	return 0;
}
