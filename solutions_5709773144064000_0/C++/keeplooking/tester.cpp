#include<bits/stdc++.h>
#define sc(n) scanf("%d",&n)
#define pn(n) printf("%d\n",n)
#define slc(n) scanf("%lld",&n)
#define pln(n) printf("%lld\n",n)
#define ps(n) printf("%d ",n) //
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int t,ty = 1;
	long double temp,c,f,x,ans,n;
	cin>>t;
	while(t--){
		cin>>c>>f>>x;
		printf("Case #%d: ",ty++);
		n=2;
		temp=x,ans=0;
		while(temp>0){
			if((temp-c)/n>temp/(n+f)){
				ans+=c/n;
				n+=f;
			}
			else{
				ans+=temp/n;
				break;
			}
		}
		cout<<setprecision(7)<<fixed;
		cout<<ans<<endl;
	}
}
