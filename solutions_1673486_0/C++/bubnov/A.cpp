#include <iostream>
#include <string>
using namespace std;

const int max_count=5;

int t,t1;
double ans1,ans2,ans3;
double p[max_count],p1,p2;
long a,b,i,j;

int main()
{
#ifndef ONLINE_JUDGE
        freopen("A-small-attempt1.in","r",stdin);
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
		for(i=1;i<=a;i++)
		{
			p1=1;
			for(j=0;j<a-i;j++)
			{
				p1*=p[j];
			}

			ans2_temp=(i+i+b+1)*(p1) + (i+i+b+1+a+b+1)*(1-p1);
			//cout << ans2_temp << " ";
			if(ans2==-1 || ans2_temp<ans2){ans2=ans2_temp;}
		}

		cout << "Case #" << t1 << ": ";
		//cout << min(ans1,min(ans2,ans3)) << "\n";
		printf("%.6f\n", min(ans1,min(ans2,ans3)));
		//cout << ans1 << " " << ans2 << " " << ans3 << "\n";
	}
    return 0;
}
