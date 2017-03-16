#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		int A,B;
		cin>>A>>B;
		B-=A;
		vector<double> P(A);
		for(int i=0;i<A;i++)
			cin>>P[i];

		vector<double> ok(A+1);
		ok[0]=1.0;
		for(int i=0;i<A;i++){
			ok[i+1]=ok[i]*P[i];
		}

		double ans=A+B+2.0;
//		cout<<ans<<endl;

		for(int i=1;i<ok.size();i++){
//			cout<<ok[i]<<" "<<(1-ok[i])<<endl;
//			cout<<i<<": "<<(A-i)*2+B+1<<" "<<((A-i)*2+B+1+A+B+1)<<endl;
//			cout<<ok[i]*((A-i)*2+B+1.0)+(1.0-ok[i])*((A-i)*2+B+1+A+B+1.0)<<endl;
			ans=min(ans,ok[i]*((A-i)*2+B+1.0)+(1.0-ok[i])*((A-i)*2+B+1+A+B+1.0));
//			cout<<ans<<endl;
		}
		cout<<"Case #"<<t<<": ";
		printf("%.6f\n" , ans);
	}
	return 0;
}