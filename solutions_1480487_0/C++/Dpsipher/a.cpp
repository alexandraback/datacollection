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
	int test,t,i,n;
	cin>>test;
	
	for(t=1;t<=test;t++)
	{
		printf("Case #%d: ",t); 
		cin>>n;
		vector<double> s(n);
		double res,S=0;
		double ans;
		for(i=0;i<n;i++){
			cin>>s[i];
			S+=s[i];
		}
		//cout<<S<<endl;
		for(i=0;i<n;i++)
		{
			res=(((2.*S-s[i]*(double)n)*100.))/(double(n)*S);
			res=maX(res,0.);
			printf("%.7lf ",res);
		}
		printf("\n");
	}
	return 0;
}
