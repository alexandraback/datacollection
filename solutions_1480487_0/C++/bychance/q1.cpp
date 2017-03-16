#include<iostream>
#include<string>
#include<map>
#include<cmath>
using namespace std;

double S[300];
bool t[300];
int main ()
{
	//freopen("in.txt", "r", stdin);
	freopen("A-small-attempt3 (1).in", "r", stdin);
	freopen("A-small_out.txt", "w", stdout);
	int T;
	scanf("%d",&T);
	for (int _t=1; _t<=T; _t++) 
	{
		memset(t, 0, sizeof(t));
		printf("Case #%d:",_t);
		int n;
		scanf("%d",&n);
		double sum=0,temp,ans;
		for (int i=0;i<n; i++) {
			scanf("%lf",&S[i]);
			sum+=S[i];
		}
		int x=0;
		double s=0;
		temp = sum*2.00/(double)n;
		bool end = true;
		while (end) 
		{
			end=false;
			for (int i=0;i<n; i++) 
			{
				if(temp-S[i]<0 && t[i]!=1)
				{
					end=true;
					x+=1;
					t[i]=1;
				}
			}
			temp=sum*2.00;
			for(int i=0;i<n;i++)
				if(t[i])
					temp-=S[i];
			temp/=(n-x);
		}
		for (int i=0;i<n; i++) 
		{
			if(!t[i])
			{
				S[i]=temp-S[i];
				ans=S[i]/sum*100.00;
			}
			else
				ans=0;
			s+=ans;
			printf(" %.6lf",ans);


		}
		cout<<endl;
	}

	return 0;
}
