#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAXD=676060+10;
const int MAXH=4*100+10,INF=2*100;
int tsts,N,n,d,w,e,s,dd,dp,ds,maxd;
int height[MAXH];
struct attack
{
	int x,y;
	int s;
} tmp;
vector <attack> A[MAXD],Pro;
void process()
{
	for(int i=0;i<Pro.size();i++)
		for(int j=Pro[i].x;j<Pro[i].y;j++)
			height[j]=max(Pro[i].s,height[j]);
}
int main()
{
	cin >> tsts;
	for(int tt=1;tt<=tsts;tt++)
	{
		cin >> N;
		int ans=0;
		memset(height,0,sizeof height);
		for(int i=0;i<N;i++)
		{
			cin >> d >> n >> w >> e >> s >> dd >> dp >> ds;
			tmp.x=w+INF;
			tmp.y=e+INF;
			tmp.s=s;
			for(int j=0;j<n;j++)
			{
				maxd=max(maxd,d);
				A[d].push_back(tmp);
				d+=dd;
				tmp.x+=dp;
				tmp.y+=dp;
				tmp.s+=ds;
			}
		}
		for(int i=0;i<=maxd;i++)
		{
			for(int j=0;j<A[i].size();j++)
				for(int q=A[i][j].x;q<A[i][j].y;q++)
				{
					if(height[q]<A[i][j].s)
					{
						ans++;
						Pro.push_back(A[i][j]);
						break;
					}
				}
			process();
			Pro.clear();
			A[i].clear();
		}
		cout << "Case #" << tt << ": " << ans << endl;
	}
	return 0;
}
