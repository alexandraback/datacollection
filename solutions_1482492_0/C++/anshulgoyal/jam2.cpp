#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
#define LIM 119
double tim[LIM], pos[LIM], acc[LIM];
int main()
{
	int t, n, a;
	cin>>t;
	double d, ans;
	for(int tc=1; tc<=t; tc++)
	{
		cin>>d>>n>>a;
		for(int i=0; i<n; i++)
		cin>>tim[i]>>pos[i];
		printf("Case #%d:\n",tc);
		for(int i=0; i<a; i++)
		{
			cin>>acc[i];
			if(n==1)
			ans = sqrt((2*d/acc[i]));
			else
			{
				double tmp = (acc[i]*tim[1]*tim[1])/2;
				if(tmp<=d)
				ans = sqrt((2*d/acc[i]));
				else
				{
					ans = sqrt((2*pos[0]/acc[i]));
					double vel = ans*acc[i];
					double dis = pos[0];
					double v = (pos[1]-pos[0])/(tim[1]-tim[0]);
					double tmp = (2*v + sqrt(4*v*v+8*pos[0]*acc[i]))/(2*acc[i]);
					int flag=0;
					if(d<((acc[i]*tmp*tmp)/2))
					{
						tmp = (2*v - sqrt(4*v*v+8*pos[0]*acc[i]))/(2*acc[i]);
						if(d<((acc[i]*tmp*tmp)/2))
						{
							ans = d/v;
							flag = 1;
						}
					}
					else if(flag==0)
					{
			//		printf("%lf %lf %lf %lf %lf\n",tmp,v,pos[1],pos[0],(pos[1]-pos[0]));
			//		printf("%lf Yo\n",(d-((acc[i]*tmp*tmp)/2)));
					ans = (tmp+(d-((acc[i]*tmp*tmp)/2))/v);
					}
		//			cout<<pos[0]+v*tmp<<"---\t";
/*		//			cout<<(acc[i]*tmp*tmp)/2<<"---\t";
					ans = tmp;
					while(pos[0]+v*tmp<=d)
					{
						tmp += (2*v/acc[i]);
						tmp += ans;
						if(pos[0]+v*tmp>=d)
						{
							ans += (d-(pos[0]+v*ans))/v;
							tmp = ans+1;
						}
						else
						{
							ans += tmp;
							tmp = ans;
						}
					}*/
				}
			}
			printf("%lf\n",ans);
		}
	}
	return 0;
}
