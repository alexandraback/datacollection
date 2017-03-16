#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <ctime>
using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	cin>>t;
	map<int, int> mp;
	

	for (int st=0; st<t; ++st)
	{
		printf ("Case #%d:", st+1);
		
		int n;
		cin>>n;
		vector <int> v(n);

		map<int, int> mp;
		mp[1]=0;
		mp[2]=1;
		mp[4]=2;
		mp[8]=3;
		mp[16]=4;
		mp[32]=5;
		mp[64]=6;
		mp[128]=7;
		mp[256]=8;
		mp[512]=9;
		mp[1024]=10;
		mp[2048]=11;
		mp[4096]=12;
		mp[8192]=13;
		mp[8192*2]=14;
		mp[8192*4]=15;
		mp[8192*8]=16;
		mp[8192*16]=17;
		mp[8192*32]=18;
		mp[8192*64]=19;

		for (int i=0; i<n; ++i)
			cin>>v[i];

		vector <pair<int, int> > g;
		for (int k=1; k<(1<<20); ++k)
		{
			int ssum=0;
			int kk=k;
			int tl;
			while (kk)
			{
				tl=kk^(kk-1)&kk;
				if (tl==1) ssum+=v[0];
		else if (tl==2) ssum+=v[1];
		else if (tl==4) ssum+=v[2];
		else if (tl==8) ssum+=v[3];
		else if (tl==16) ssum+=v[4];
		else if (tl==32) ssum+=v[5];
		else if (tl==64) ssum+=v[6];
		else if (tl==128) ssum+=v[7];
		else if (tl==256) ssum+=v[8];
		else if (tl==512) ssum+=v[9];
		else if (tl==1024) ssum+=v[10];
		else if (tl==2048) ssum+=v[11];
		else if (tl==4096) ssum+=v[12];
		else if (tl==8192) ssum+=v[13];
		else if (tl==8192*2) ssum+=v[14];
		else if (tl==8192*4) ssum+=v[15];
		else if (tl==8192*8) ssum+=v[16];
		else if (tl==8192*16) ssum+=v[17];
		else if (tl==8192*32) ssum+=v[18];
		else if (tl==8192*64)ssum+=v[19];
		//else cout<<"ERROR"<<endl;



				
				kk^=kk^(kk-1)&kk;
			}
			g.push_back(make_pair(ssum, k));
		}

		sort(g.begin(), g.end());
		//for (int j=0; j<100; ++j) cout<<g[j].first<<" "<<g[j].second<<endl;

		for (int i=0; i<g.size()-1; ++i)
			if (g[i].first==g[i+1].first)
			{
				int kk=g[i].second;
				cout<<endl;
				while (kk)
			{
				cout<<v[mp[(kk^(kk-1)&kk)]]<<" ";
				kk^=kk^(kk-1)&kk;
			}
				cout<<endl;
				kk=g[i+1].second;
				while (kk)
			{
				cout<<v[mp[(kk^(kk-1)&kk)]]<<" ";
				kk^=kk^(kk-1)&kk;
			}
				break;
			}
		
		printf("\n");


	}


}