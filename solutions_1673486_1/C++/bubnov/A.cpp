#include <iostream>
#include <string>
using namespace std;

const int max_count=100005;

int t,t1;
double ans1,ans2,ans3;
double p[max_count],p1,p2;
long a,b,i,j;

int main()
{
#ifndef ONLINE_JUDGE
        freopen("A-large.in","r",stdin);
		//freopen("input.txt","r",stdin);	

        freopen("output.txt","w",stdout);
#endif
	cin >> t;
	//cout.precision(6);
	for(t1=1;t1<=t;t1++)
	{
		cin >> a >> b;
		b-=a;
		p1=1;
		for(i=0;i<a;i++)
		{
			cin >> p[i];
			p1*=p[i];
		}
		
		ans1=(b+1)*p1 + (b+1+a+b+1)*(1-p1);
		ans3=a+b+2;

		ans2=-1;
		double ans2_temp;
		p1=1;

/*		for(i=1;i<=a;i++)
		{
			p1=1;
			for(j=0;j<a-i;j++)
			{
				p1*=p[j];
			}

			ans2_temp=(i+i+b+1)*(p1) + (i+i+b+1+a+b+1)*(1-p1);
			//cout << ans2_temp << " ";
			if(ans2==-1 || ans2_temp<ans2){ans2=ans2_temp;}
		}*/
		p1=1;
		for(j=-1;j<a;j++)
		{
			i=a-j-1;
			ans2_temp=(i+i+b+1)*(p1) + (i+i+b+1+a+b+1)*(1-p1);
			if(ans2==-1 || ans2_temp<ans2){ans2=ans2_temp;}

			if(j+1<a){p1*=p[j+1];}
		}

		cout << "Case #" << t1 << ": ";
		printf("%.6f\n", min(ans1,min(ans2,ans3)));
	}
    return 0;
}
