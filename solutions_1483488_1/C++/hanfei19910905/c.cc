#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define re(i,n) for(int i=0;i<n;i++)
#define re1(i,n) for(int i=1;i<=n;i++)
#define re2(i,n) for(int i=0;i<=n;i++)
#define re3(i,n) for(int i=1;i<n;i++)
#define clr(a,n) memset(a,n,sizeof(a))
#define debug(n) cout<<#n<<"="<<n<<endl
int base[9];
int rot (int x,int b){
	return x/base[b]+x%base[b]*10;
}
int cal(int x){
	int ans;
	re(i,9) if(base[i]<=x) ans = i;
	return ans;
}
int main(){
	int A,B,t,k;
	base[0] = 1;
	for(int i= 1; i<9;i++) base[i] = base[i-1]*10;
	#ifdef debug1
	while(cin>>t) {
		int x= cal(t);
		cout<<base[x]<<" "<<rot(t,x)<<endl;
	}
	#endif
	cin >>t;
	re1(oo,t){
		int ans =0;
		cin >> A >> B;
		cout<<"Case #"<<oo<<": ";
		for(int i = A;i< B;i++){
			int b = cal(i);
			k = i;
//			cout<<i<<endl;
			while((k=rot(k,b))!=i){
//				cout<<k<<endl;
				if(k >i && k<=B) ans ++;
			}
		}
		cout<<ans<<endl;
	}
}

