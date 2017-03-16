#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<utility>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#define ii long long int
#define pi 2*acos(0.0)
#define eps 1e-7
#define mem(x,y) memset(x,y,sizeof(x))
#define all(x) x.begin(), x.end()
#define pb push_back

using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int x,t;
	
	scanf("%d",&t);
	
	for (x=1; x<=t; ++x)
	{
		double s,his= 0,myt,A[3000][2];
		int n,a,i;
		scanf("%lf %d %d",&s,&n,&a);
		
		for (i=0; i<n; ++i)
		{
			scanf("%lf%lf",&A[i][0],&A[i][1]);
		}
		
		for (i=0; i<n; ++i)
		{
			if (A[i][1]<s || fabs(A[i][1]-s)<eps) his+= A[i][0];
			if (fabs(A[i][1]-s)<eps) break;
			else if (A[i][1]>s)
			{
				if (!i) {his=0; break;}
				double need= s-A[i-1][1];
				his+= (A[i][0]-A[i-1][0])*need/(A[i][1]-A[i-1][1]);
				break;
			}
		}
		
		printf("Case #%d:\n",x);
		for (int j=1; j<=a; ++j)
		{
			double x;
			long double myt2;
			//myt= 0;his= 0;pv= 0;
			scanf("%lf",&x);
			
			myt2= 2.0*s/(long double)x;
			myt2= sqrtl(myt2);
			
			myt= myt2;
			//printf(">> %.8lf\n",myt);
			myt= max(myt,his);
			printf("%.8lf\n",myt);
			
			/*
			for (i=0; i<n; ++i)
			{
				if (A[i][1]<s || fabs(A[i][1]-s)<eps)
				{
					if (!i) {t1=0;}
					else
					{
						t1= pv*(A[i][0]-A[i-1][0])+0.5*x*(A[i][0]-A[i-1][0])*(A[i][0]-A[i-1][0]);
					}
					if (t1+mys>A[i][1])
					{
						double ap= 2*( (A[i][1]-mys)-pv*(A[i][0]-A[i-1][0]) )/(A[i][0]-A[i-1][0])/(A[i][0]-A[i-1][0]);
						myv= sqrt(pv*pv+2*ap*(A[i][1]-mys));
						mys= A[i][1];
					}
					else
					{
						mys+= t1;
						myv= sqrt(pv*pv+2*x*t1);
					}
					myt= A[i][0];
					if (fabs(A[i][1]-s)<eps) break;
				}
				else if (A[i][1]>s)
				{
					if (!i) {his=0;}
					else
					{
						double need= s-A[i-1][1];
						his= (A[i][0]-A[i-1][0])*need/(A[i][1]-A[i-1][1]);
					}
					
					t1= pv*his+0.5*x*his*his;
					if (t1+mys>s) mys= s;
					else mys+= t1;
					myt+= his;
				}
				pv= myv;
			}
			
			if (mys<s)
			{
				double need= s-mys;
				myv= sqrt(pv*pv+2*x*need);
				t1= (myv-pv)/x;
				myt+= t1;
			}
			cout<<myt<<endl;
			*/
		}
	}
	
	return 0;	
}
