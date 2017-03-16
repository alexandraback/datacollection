#include<iostream>
#include<algorithm>
using namespace std;
const double eps=1e-8;
bool cmp(double a,double b)
{
	return a+eps<b;
}
void solve()
{
	int n,i,j,pw=0,pdw=0;
	double na[2000],ken[2000];
	cin>>n;
	for(i=0;i<n;i++)
		cin>>na[i];
	for(i=0;i<n;i++)
		cin>>ken[i];
	sort(na,na+n,cmp);
	sort(ken,ken+n,cmp);
	i=j=0;
	while(i<n && j<n)
	{
		while(na[i]+eps>ken[j] && j<n)
			j++;
		if(j>=n)break;
		i++;
		j++;
		pw--;
	}
	pw+=n;
	i=j=0;
	while(i<n && j<n)
	{
		while(na[i]<ken[j]+eps && i<n)
			i++;
		if(i>=n)break;
		i++;
		j++;
		pdw++;
	}
	cout<<pdw<<" "<<pw<<endl;
}
int main()
{
	int t,i;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cout<<"Case #"<<i<<": ";
		solve();
	}
}
