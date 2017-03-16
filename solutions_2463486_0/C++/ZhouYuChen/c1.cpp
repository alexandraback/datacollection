#include<iostream>
#include<algorithm>
using namespace std;
typedef long long Lint;
Lint x[100];
size_t c=0;
bool palindrome(Lint x){
	int l=0;
	static int a[20];
	for(;x;x/=10)a[l++]=x%10;
	for(int j=--l-1>>1;~j;--j)
	if(a[j]!=a[l-j])return 0;
	return 1;
}
Lint solve(){
	Lint A,B,a,b;
	cin >> A >> B;
	if(A>B)return 0;
	return upper_bound(x,x+c,B)-lower_bound(x,x+c,A);
}
int main(){
	for(int i=1;i<=10000000;++i)
		if(palindrome(i)&&palindrome((Lint)i*i))
			x[c++]=(Lint)i*i;
	int Tc=1,T;
	for(cin>>T;Tc<=T;++Tc)
		cout <<"Case #"<<Tc<<": "<<solve()<<endl;
}
