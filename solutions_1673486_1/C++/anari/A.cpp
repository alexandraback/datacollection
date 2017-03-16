#include <iostream>
using namespace std;
int n,m;
double p[1000000];
int main(){
	cout<<fixed;
	cout.precision(9);
	int tnum, tcou=0;
	cin>>tnum;
	while (tnum--){
		cin>>n>>m;
		for (int i=0;i<n;++i)
			cin>>p[i];
		double ans=1+(m+1);
		double P=1;
		for (int j=0;j<=n;++j){
			double fc=(m-j)+(n-j)+1;
			double pc=(m+1)*(1-P);
			ans=min(ans,fc+pc);
			P=P*p[j];
		}
		cout<<"Case #"<<++tcou<<": "<<ans<<endl;
	}
	return 0;
}
