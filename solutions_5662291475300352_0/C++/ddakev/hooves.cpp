#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
long long t,n,nh;
double d,s;
pair<double, double> h[1001];
int main()
{
	freopen("C-small-1-attempt1.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%lld",&t);
	for(int o=1; o<=t; o++)
	{
		scanf("%lld",&n);
		int br=1;
		for(int i=1; i<=n; i++)
        {
            scanf("%lf%lld%lf",&d,&nh,&s);
            for(int j=br; j<=nh+br-1; j++)
            {
                h[j]=make_pair(d,s+(j-br));
            }
            br=br+nh;
        }
            if(h[1].first>=h[2].first&&h[2].second>=h[1].second)
            {
                if((360.0-h[1].first+360.0)/(360.0/h[1].second)<=(360.0-h[2].first)/(360.0/h[2].second))
                    printf("Case #%d: 1\n",o);
                else printf("Case #%d: 0\n",o);
            }
            else if(h[1].first<=h[2].first&&h[2].second<=h[1].second)
            {
                if((360.0-h[2].first+360.0)/(360.0/h[2].second)<=(360.0-h[1].first)/(360.0/h[1].second))
                    printf("Case #%d: 1\n",o);
                else printf("Case #%d: 0\n",o);
            }
            else if(h[1].first>=h[2].first&&h[2].second<=h[1].second)
            {
                if((360.0-h[2].first+360.0)/(360.0/h[2].second)<=(360.0-h[1].first)/(360.0/h[1].second))
                    printf("Case #%d: 1\n",o);
                else printf("Case #%d: 0\n",o);
            }
            else
            {
                if((360.0-h[1].first+360.0)/(360.0/h[1].second)<=(360.0-h[2].first)/(360.0/h[2].second))
                    printf("Case #%d: 1\n",o);
                else printf("Case #%d: 0\n",o);
            }
	}
	return 0;
}
