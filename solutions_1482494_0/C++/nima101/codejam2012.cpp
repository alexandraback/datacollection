#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <set>
#include <sstream>
#include <cmath>

using namespace std;

typedef long long ll;

//*
ifstream fin("B-small-attempt4.in");
#define cin fin
ofstream fout("B-small-attempt4.out");
#define cout fout
//*/

const int maxn = 2005;
int a[maxn], b[maxn];
typedef pair<int, int> pii;

int main()
{
	int tc;
	cin>>tc;

	for(int t=1; t<=tc; t++)
	{
		int n;
		cin>>n;
		for(int i=0; i<n; i++)
			cin>>a[i]>>b[i];
		vector<int> vis(n, 0);
		vector<pii> oneStar (n);
		vector<pii> twoStar (n);

		for(int i=0; i<n; i++)
		{
			oneStar[i] = make_pair(a[i], i);
			twoStar[i] = make_pair(b[i], i);
		}
		sort(oneStar.begin(), oneStar.end());
		sort(twoStar.begin(), twoStar.end());

		int stars=0;
		bool changed=false;
		int levels = 0;
		int i1=0, i2=0;

		while(i2<twoStar.size())
		{
			changed = false;
			
			while(i2<twoStar.size() && twoStar[i2].first<=stars)
			{
				changed = true;
				int idx = twoStar[i2].second;
				levels++;
				stars += 2 - vis[idx];
				vis[idx] = 2;
				i2++;
			}
			if(i2>=twoStar.size()) break;

			if(i1<oneStar.size() && oneStar[i1].first<=stars)
			{
				changed = true;
				int bestidx = i1;
				for(int k=i1+1; k<oneStar.size() && oneStar[k].first<=stars ; k++)
					if( b[oneStar[k].second] < b[oneStar[bestidx].second] && vis[ oneStar[k].second ]==0)
						bestidx = k;

				int idx = oneStar[bestidx].second;
				if(vis[idx]==0)
				{
					levels++;
					stars++;
					vis[idx] = 1;
				}
				i1++;
			}

			if(!changed)
				break;
		}

		if (i2<twoStar.size())
			cout<<"Case #"<< t<<": "<<"Too Bad"<<endl;
		else
			cout<<"Case #"<< t<<": "<< levels <<endl;
	}
	return 0;
}
