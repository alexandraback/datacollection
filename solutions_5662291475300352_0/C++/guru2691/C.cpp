#include<bits/stdc++.h>

using namespace std;

pair<double,double> A[3];
double B[3];

int main()
{
	int T;
	cin>>T;
	/*
	
spd1 = 360/c[0];
t1 = (360-a[0])/(spd1);

spd2 = 360/c[1];
t2 = (360-a[1])/(spd2);
//cout<<t1<<" "<<t2<<" "<<spd1<<" "<<spd2<<" "<<endl;
if((t1+360/spd1 > t2) && (t1<=t2))
ans = 0;
if((t2+360/spd2 > t1) && (t1>=t2))
ans = 0;
	*/
	for(int idx=1;idx<=T;idx++)
	{
		int N;
		cin>>N;
		int cnt = 0;
		for(int i=0;i<N;i++)
		{
			double D,M;
			int H;
			cin>>D;
			cin>>H;
			cin>>M;
			for(int k=0;k<H;k++)
			{
				A[k+cnt].first = D;
				A[k+cnt].second = 360.0/(M+k);
			}
			cnt += H;
		}
		cout<<"Case #"<<idx<<": ";
		if(cnt == 1)
		cout<<0<<'\n';
		else
		{
			B[0] = (360.0-A[0].first)/A[0].second;
			B[1] = (360.0-A[1].first)/A[1].second;
			//cout<<B[0]<<' '<<B[1]<<'\n';
			if(B[0] >= B[1])
			{
				if(B[0] >= B[1]+360.0/A[1].second)
				cout<<1<<'\n';
				else
				cout<<0<<'\n';
			}
			else
			{
				if(B[1] >= B[0]+ 360.0/A[0].second)
				cout<<1<<'\n';
				else
				cout<<0<<'\n';
			}
		}
	}
}
