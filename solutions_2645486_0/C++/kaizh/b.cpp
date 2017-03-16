#include <iostream>
using namespace std;

int ans;
int E,R,N;
int v[11];

void gao(int deg,int sum,int e)
{
	if(ans<sum)ans=sum;
	if(deg>=N)return;

	for(int i=0;i<=e;i++)
	{
		int ee=e-i+R;
		if(ee>E)ee=E;
		gao(deg+1,sum+i*v[deg],ee);
	}
}

int main()
{
	int T;
	cin>>T;
	for(int tt=1;tt<=T;tt++)
	{
		ans=0;
		cin>>E>>R>>N;
		for(int i=0;i<N;i++)
			cin>>v[i];
		gao(0,0,E);
		cout<<"Case #"<<tt<<": "<<ans<<endl;;
	}
	return 0;
}
