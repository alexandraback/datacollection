#include<iostream>
#include<cstdio>
using namespace std;


int n,m,k;


int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int T;cin>>T;
	int tt=0;
	while(T--)
	{
		cout<<"Case #"<<++tt<<": ";
		
		
		cin>>n>>m>>k;
		int Min=0x7ffffff;
		for(int i=0;i<=n-2;i++)
			for(int j=0;j<=m-2;j++){
				if ((i+2)*(j+2)-4>=k) Min=min(Min,i*2+j*2);
			}
		if(Min!=0x7ffffff)cout<<Min;else cout<<(n-2)*2+(m-2)*2+(n*m-k);
		cout<<endl;
	}
	return 0;
}