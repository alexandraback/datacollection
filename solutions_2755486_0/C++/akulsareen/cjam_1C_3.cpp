#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;
ifstream fin("C.in");
ofstream fout("C.out");
vector <int> wall;
int ans,dmax;
struct sched
{
	vector <int> attackers;
};
vector <sched> calendar;
struct tribe
{
	int iden,di,ni,wi,ei,si,d_di,d_pi,d_si;
	void input()
	{
		fin>>di>>ni>>wi>>ei>>si>>d_di>>d_pi>>d_si;
		dmax=max(dmax,di+((ni-1)*d_di));
		wi+=300;
		ei+=300;
	}
	void process()
	{
		int x=di;
		for(int i=0;i<ni;i++)
		{
			calendar[x].attackers.push_back(iden);
			x+=d_di;
		}
	}
	void attack(int day)
	{
		int num=(day-di)/d_di;
		int strength=si+(num*d_si);
		int lend=wi+(num*d_pi);
		int rend=ei+(num*d_pi);
		//cout<<num<<" "<<strength<<" "<<lend<<" "<<rend<<"\n";
		for(int i=lend*10;i<=rend*10;i++)
		{
			if(wall[i]<strength)
			{
				ans++;
				//cout<<"yes"<<"\n";
				break;
			}
		}
	}
	void repair(int day)
	{
		int num=(day-di)/d_di;
		int strength=si+(num*d_si);
		int lend=wi+(num*d_pi);
		int rend=ei+(num*d_pi);
		for(int i=lend*10;i<=rend*10;i++)
		{
			wall[i]=max(wall[i],strength);
		}
	}
};
int main()
{
	int t;
	vector <int> fans;
	fin>>t;
	while(t--)
	{
		int n;
		ans=0;
		dmax=0;
		vector <tribe> tribcol;
		wall.clear();
		wall.resize(6000,0);
		calendar.clear();
		fin>>n;
		tribe x;
		for(int i=0;i<n;i++)
		{
			x.iden=i;
			x.input();
			tribcol.push_back(x);
			
		}
		vector <sched> xy(dmax+1);
		calendar=xy;
		for(int i=0;i<n;i++)
		{
			tribcol[i].process();
		}
		for(int i=0;i<calendar.size();i++)
		{
			//cout<<"Day"<<i<<"\n";
			for(int j=0;j<calendar[i].attackers.size();j++)
			{
				//cout<<calendar[i].attackers[j]<<"\n";
				tribcol[calendar[i].attackers[j]].attack(i);
			}
			for(int j=0;j<calendar[i].attackers.size();j++)
			{
				tribcol[calendar[i].attackers[j]].repair(i);
			}
		}
		fans.push_back(ans);
	}
	for(int i=0;i<fans.size();i++)
	fout<<"Case #"<<i+1<<": "<<fans[i]<<"\n";
	return 0;
}
