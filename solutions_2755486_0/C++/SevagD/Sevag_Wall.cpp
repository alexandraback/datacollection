#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct attack{
	int day;
	int west;
	int east;
	int strength;
	attack(int d, int w, int e, int s)
	{
		day=d; west=w; east=e; strength=s;
	}
};

map < int, vector < attack> > schedule;
int Wall[201];

int daysMark[676061];
vector <int> days;

int main()
{
	ifstream cin("C-small-attempt0.in");
	ofstream cout("sevag_wall_small.out");

	int T, N, n, d, w, e, s, delta_d, delta_p, delta_s;


	cin>>T;

	for (int t=1; t<=T; t++)
	{
		
		memset(Wall, 0, sizeof(Wall));
		memset(daysMark, 0, sizeof(daysMark));
		schedule.clear();
		days.clear();

		cin>>N;

		for (int tribe=0; tribe<N; tribe++)
		{
			cin>>d>>n>>w>>e>>s>>delta_d>>delta_p>>delta_s;

			int dd=d;
			int ss=s;
			int ww=w, ee=e;
			for (int i=0; i<n; i++)
			{
				if (daysMark[dd]==0){
					days.push_back(dd);
					daysMark[dd]=1;
				}
				attack att(dd, ww, ee, ss);
				schedule[dd].push_back(att);
				dd += delta_d;
				ww+= delta_p; ee+=delta_p;
				ss+=delta_s;
			}
		}

		int success=0;
		sort(days.begin(), days.end());
		
		for (int i=0; i<days.size(); i++)
		{
			int d = days[i];

			bool in=false;
			for (int att=0; att<schedule[d].size(); att++)
			{
				for (int p=schedule[d][att].west; p<schedule[d][att].east; p++)
				{
					if (Wall[p+100]<schedule[d][att].strength){
						in=true;
						Wall[p+100]=schedule[d][att].strength;
					}
				}
				if (in)
					success++;
			}
		}

		cout<<"Case #"<<t<<": "<<success<<endl;

	}

	return 0;
}