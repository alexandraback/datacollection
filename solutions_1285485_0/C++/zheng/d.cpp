#include <iostream>
using namespace std;

char line[31];
int ax[1000000], ay[1000000], cnt, d;

inline int dis(int x1, int y1, int x2, int y2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

inline bool isIn(int x, int y)
{
	for(int i=0; i<cnt; ++i)
	{
		//if(x==0 && ax[i]==0)
		//	return true;
		if(ax[i]*y==x*ay[i])
			return true;
	}
	return false;
}

int cal(int a2, int b2, int c2, int d2, bool b)
{
	int ans=0;
	cnt=0;
	int x=0, y=0, xx=0, yy=0, xxx=0, yyy=0;
	bool s1=true;
	while(true)
	{
		//cout<<xx<<" "<<yy<<endl;
		if(dis(xx, yy, x, y)>d)
			break;
		if(b&& yy!=y && !isIn(xx, yy))
		{
			++ans;
			ax[cnt]=xx;
			ay[cnt++]=yy;
		}
		bool s2=false;
		xxx=xx+c2;
		yyy=yy;
		while(true)
		{
			if(dis(xxx, yyy, x, y)>d)
				break;
			if(yyy==y)
			{
				if(b && !isIn(xxx, yyy))
				{
					++ans;
					ax[cnt]=xxx;
					ay[cnt++]=yyy;
				}
			}
			else if(!isIn(xxx, yyy)) 
			{
				++ans;
				ax[cnt]=xxx;
				ay[cnt++]=yyy;
			}
			if(s2) xxx+=c2;
			else xxx+=a2;
			s2=!s2;
		}
		if(s1) yy+=b2;
		else yy+=d2;
		s1=!s1;
	}
	return ans;
}

int main()
{
	int numOfCases, h, w, a2, b2, c2, d2, ans;
	cin>>numOfCases;
	for(int i=1; i<=numOfCases; ++i)
	{
		cnt=ans=0;
		cin>>h>>w>>d;
		for(int j=0; j<h; ++j)
		{
			cin>>line;
			for(int k=0; line[k]; ++k)
				if(line[k]=='X')
				{
					a2=k*2-1;
					c2=(w-2)*2-a2;
					b2=j*2-1;
					d2=(h-2)*2-b2;
				}
		}
		d=d*d;
		ans+=cal(a2, b2, c2, d2, true);
		ans+=cal(c2, b2, a2, d2, false);
		ans+=cal(a2, d2, c2, b2, false);
		ans+=cal(c2, d2, a2, b2, true);

		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
	return 0;
}

