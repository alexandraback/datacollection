#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;
typedef long long LL;
bool ispar(LL a){
	LL b = 0;
	LL ta = a;
	while (ta){
		b = b*10+(ta%10);
		ta/=10;
	}
	return b == a;
}
LL s[40];
int maxn = 40;
int main(){

	ifstream fin("C.data");
	for (int i = 0; i<maxn; i++) fin>>s[i];
	freopen("C-large-1.in","r",stdin);
	freopen("C.out","w",stdout);
	int T;
	cin>>T;
	for (int cas = 1; cas<=T; cas++){
		LL A, B;
		cin>>A>>B;
		int cnt = 0;
		for (int i = 0; i<maxn; i++)
			if (s[i]*s[i] >= A && s[i]*s[i] <= B){
				cnt++;
			}
		cout<<"Case #"<<cas<<": "<<cnt<<endl;
	}
	return 0;
}
