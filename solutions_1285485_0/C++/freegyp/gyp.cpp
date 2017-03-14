#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<string>
#include<iterator>
#include<algorithm>
using namespace std;
typedef vector<string> vstr;
typedef vector<string>::iterator vstri;
typedef set<int> sint;
typedef set<int>::iterator sinti;
sint genpossible(int d1,int d2,int s)
{
	int temp=0;
	sint ret;
	ret.insert(temp);
	while((-temp)<=s)
	{
		temp-=d1;ret.insert(temp);
		temp-=d2;ret.insert(temp);
	}
	temp=0;
	while(temp<=s)
	{
		temp+=d2;ret.insert(temp);
		temp+=d1;ret.insert(temp);
	}
	return ret;
}
int countcd(sint v,sint h,int D)
{
	set<float> pos,neg;
	int ret=2;
	for(sinti sj=h.begin();sj!=h.end();sj++)
	{
		if((*sj)!=0)
		{
			for(sinti si=v.begin();si!=v.end();si++)
			{
				if(((*si)*(*si)+(*sj)*(*sj))<=D*D)
				{
					if((*sj)>0)pos.insert(((float)(*si))/((float)(*sj)));
					else neg.insert(((float)(*si))/((float)(*sj)));
				}
			}
		}
	}
	ret+=pos.size()+neg.size();
	return ret;
}
int main()
{
	ifstream gin("D-small-attempt5.in");
	ofstream gout("gypDsmall.out");
	int T,H,W,D;
	gin>>T;
	cout<<T<<endl;
	for(int i=0;i<T;i++)
	{
		gin>>H>>W>>D;
		cout<<i+1<<endl;
		vstr graph;
		for(int j=0;j<H;j++)
		{
			string temp;gin>>temp;
			graph.push_back(temp);
		}
		int up,down,left,right;
		for(int j=0;j<H;j++)
		{
			for(int k=0;k<W;k++)
			{
				if(graph[j][k]=='X')
				{
					up=2*j-1;down=2*(H-j-1)-1;left=2*k-1;right=2*(W-k-1)-1;
				}
			}
		}
		sint vertical=genpossible(down,up,D),horizantal=genpossible(left,right,D);
		int total=countcd(vertical,horizantal,D);
		if(up>D)total-=1;
		if(down>D)total-=1;
		gout<<"Case #"<<i+1<<": "<<total<<endl;
	}
	gout.close();
	gin.close();
	return 0;
}
