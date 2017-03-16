#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int i,T,j;
char Str[1005];

int main() {
	cin >> T;
	for(i=1;i<=T;++i) {
		cin >> Str;
		int Len=strlen(Str);
		string Ans="";
		Ans+=Str[0];
		for(j=1;j<Len;++j) {
			string tmp="";
			if(Str[j]>=Ans[0]) {
				tmp=Str[j]+Ans;
				Ans=tmp;
			}
			else Ans+=Str[j];
		}
		cout << "Case #" << i << ": " << Ans << endl;
	}
	return 0;
}
