#include"iostream"
#include"cstdio"
#include"vector"
#include"math.h"
#include"algorithm"
#include"string.h"
#include"sstream"
#include"stack"
#include"queue"
#include"map"
#define maX(a, b) ((a) >= (b) ? (a) : (b))
#define miN(a, b) ((a) <= (b) ? (a) : (b))
#define ABS(a) ((a) < (0) ? (a)*(-1) : (a))
#define pb(x) push_back(x)
#define pii pair<int,int>
#define ll long long
using namespace std;
int main()
{
	
	ll i,a,b,t,tt;
	cin>>t;
	for(tt=1;tt<=t;tt++){
		printf("Case #%lld: ",tt);
		cin>>a>>b;
		vector<double> p(a);
		double pr1=1.;
		double pr2,ans,res;
		for(i=0;i<a;i++){
			cin>>p[i];
			pr1=pr1*p[i];
		}
		ll len1,len2;
		len1=(b-a+1);
		len2=(2*b-a+2);
		pr2=1.-pr1;
		ans=len1*pr1+len2*pr2;
		//cout<<ans<<endl;
		for(i=1;i<=a;i++){
			len1=len1+2;
			len2=len2+2;
			pr1=pr1/p[a-i];
			pr2=1.-pr1;
			res=len1*pr1+len2*pr2;
			if(res<ans)
				ans=res;
			//cout<<res<<endl;
		}
		res=2.+b;
		//cout<<res<<endl;
		if(res<ans)ans=res;
		printf("%.8lf\n",ans);
	}
	return 0;
}
