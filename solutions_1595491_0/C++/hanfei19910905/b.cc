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

int main(){
	int t,s,p,n;
	cin >> t;
	re1(oo,t){
		cout<<"Case #"<<oo<<": ";
		int ans = 0;
		cin >>n >>s  >>p;
		re(ooo,n){
			int a,mx,num;
			scanf("%d",&a);
			mx = a/3 + (a%3>0);
			num = a%3;
			if(num == 0) num = 3;
			if(mx >=p ) {
				ans ++;
			}
			else if(mx+1 == p && s && ((num==2) || (num == 3 && a))){
				s--; ans ++;
			}
		}
		cout<<ans<<endl;
	}
}

