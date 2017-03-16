#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

#include<vector>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

#define SI(x) scanf("%d ",&x)
#define SL(x) scanf("%lld",&x)

typedef long long LL;
using namespace std;

int S[500];
int K[500];
double p[500];
double x = 0.0;
double eps = 1.0e-9;
int main()
{
    freopen("A-small-attempt2.in","r",stdin);
    freopen("A-small-output.txt","w",stdout);
   
    int T,tnum=1;
    SI(T);

    while(T-- >0)
    {
	int n;
	x = 0.0;
	SI(n);
	for(int i=0;i<n;i++) { SI(S[i]); x+=S[i];} 
	printf("Case #%d: ",tnum);
	double INF = 1000.0;
	for(int i=0;i<n;i++)
	{
		double lo = 0, hi = 1.0;
		for(int it=1;it<=1000;it++)
		{
			double mid = (lo+hi)/2.0;
			double needed = 0.0;
			for(int j=0;j<n;j++)
			{
				if(j==i) continue;
				double k =  ((S[i]-S[j])*1.0/x + mid);
				if(k<0.0) needed+=0;
				else needed+=k;

			}
			double what = 1.0-mid;
			if(needed<=what || (needed>what && needed-what<=eps)) lo = mid;
			else hi = mid;
		}
		printf("%.10lf ",lo*100);
	}
	printf("\n");
	tnum++;
    }


    fclose(stdout);
	return 0;
}
