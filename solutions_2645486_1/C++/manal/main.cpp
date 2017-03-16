#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

int main()
{
	int test,temp,e,r,n;
	int answer[11][5],v[10];
	cin>>test;
	answer[0][0]=0;
	answer[0][1]=0;
	answer[0][2]=0;
	answer[0][3]=0;
	answer[0][4]=0;
	for (int i = 0; i < test; i++)
	{
		cin>>e>>r>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>v[j-1];
			for(int k=0;k<=e-r;k++)
			{
				answer[j][k]=0;
				int l=0;
				if(k>r)
					l=k-r;
				for(;l<=e-r;l++)
				{
					if(answer[j-1][l]+v[j-1]*(l+r-k)>answer[j][k])
						answer[j][k]=answer[j-1][l]+v[j-1]*(l+r-k);
				}
			}
		}

		cout<<"Case #"<<i+1<<": "<<answer[n][0]<<endl;
	}
	return 0;
}