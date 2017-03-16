#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int ic=1;ic<=t;++ic)
	{
		int k,c,s;
		cin>>k>>c>>s; //s=k
		cout<<"Case #"<<ic<<":";
		for(int i=1;i<=s;++i) cout<<" "<<i;
		endl(cout);
	}
	return 0;
}
