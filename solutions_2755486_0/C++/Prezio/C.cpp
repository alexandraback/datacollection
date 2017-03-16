#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct attack
{
	vector< pair<int, int> > interv;
	int d;
	vector<int> s;
};


bool cmp(attack a1, attack a2)
{
	return (a1.d<a2.d);
}

int N;
int result;
int Wall[1400];
vector<attack> attacks;

void add_attack(pair<int, int> p, int s, int d)
{
	for(int i=0; i<attacks.size(); i++)
	{
		if(attacks[i].d==d)
		{
			attacks[i].interv.push_back(p);
			attacks[i].s.push_back(s);
			return;
		}
	}
	attack a;
	a.d=d;
	a.interv.push_back(p);
	a.s.push_back(s);
	attacks.push_back(a);
}

void attack(int w, int e, int s)
{
	for(int i=w+300*2+1; i<=e+300*2; i++)
	{
		if(Wall[i]<s)
		{
			result++;
			return;
		}
	}
	//cout<<":"<<w<<" "<<e<<" "<<s<<"\n";
}
void repair(int w, int e, int s)
{
	for(int i=w+300*2+1; i<=e+300*2; i++)
	{
		Wall[i]=max(Wall[i], s);
	}
}

int main()
{
	cin>>N;
	int k=1;
	while(k<=N)
	{
		int n;
		cin>>n;
		for(int i=0; i<n; i++)
		{
			int d, n1, w, e, s, d_d, d_p, d_s;
			cin>>d>>n1>>w>>e>>s>>d_d>>d_p>>d_s;

			pair<int, int> inter=pair<int, int>(w, e);

			for(int j=0; j<n1; j++)
			{
				add_attack(inter, s, d);
				d+=d_d;
				s+=d_s;
				inter.first+=d_p;
				inter.second+=d_p;
			}
		}
		sort(attacks.begin(), attacks.end(), cmp);
		
		//for(int i=0; i<attacks.size(); i++)
		//	cout<<attacks[i].d<<" "<<attacks[i].interv.size()<<"\n";
		
		result=0;
		for(int i=0; i<attacks.size(); i++)
		{
			for(int j=0; j<attacks[i].interv.size(); j++)
				attack(attacks[i].interv[j].first, attacks[i].interv[j].second, attacks[i].s[j]);
			for(int j=0; j<attacks[i].interv.size(); j++)
				repair(attacks[i].interv[j].first, attacks[i].interv[j].second, attacks[i].s[j]);
		}

		cout<<"Case #"<<k<<": "<<result<<"\n";
		attacks.clear();
		for(int i=0; i<1400; i++)
			Wall[i]=0;
		k++;
	}
	return 0;
}
