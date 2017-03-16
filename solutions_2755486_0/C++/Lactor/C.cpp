#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAX 1000
#define CENTER 500
#define MAXT 1005

using namespace std;

struct Tribe{

bool alive;
int df;
int maxattacks;
int attacks;
int wf, ef, sf;
int dd, dp, ds;

Tribe (int dfir, int ma, int wi, int ei,int si, int ddays, int dpos, int dstr){
	alive = true;
	df = dfir;
	maxattacks = ma;
	attacks = 0;
	wf = 2*(wi) + CENTER;
	ef = 2*(ei) + CENTER;
	sf = si;
	dd = ddays;
	dp = 2*dpos;
	ds = dstr;
}


};

int main()
{
	
	FILE *in;
	FILE *out;
	in = fopen("C.in", "r");
	out = fopen("C.out", "w");


	int T;
	fscanf(in, "%d", &T);
	for(int z = 0; z<T; z++)
	{
		int height[MAX];
		vector <Tribe> trib;
		vector <pair<int,int> > days;
		int N;
		fscanf(in, "%d", &N);
		for(int i = 0; i<N; i++)
		{
			int a,b,c,d,e,f,g,h;
			fscanf(in, "%d %d %d %d %d %d %d %d",&a, &b, &c, &d, &e, &f, &g, &h);
			trib.push_back( Tribe(a,b,c,d,e,f,g,h));
			for(int o = 0; o<b; o++)
			{
				days.push_back(pair<int,int>(a+o*f, i));
			}
		}
		sort(days.begin(), days.end() );
		for(int i =0 ; i<(int)days.size(); i++)
			printf("%d %d\n", days[i].first, days[i].second);

		for(int i = 0; i< MAX; i++)
			height[i] = 0;

		int heightnew[MAX];
		int ndays = days.size();
		int total = 0;
		for(int i = 0; i<ndays; )
		{
			for(int o = 240; o<270; o++)
				printf("%d ", height[o]);
			printf("\n");
			for(int o = 0; o< MAX; o++)
				heightnew[o] = -1;
			int day = days[i].first;
			printf("DAY %d SOFAR : %d\n", day, total);

			while(i<ndays && days[i].first == day)
			{

				Tribe t = trib[days[i].second];
				bool suc = false;
				printf("STRENGTH: %d RANGE:%d %d\n",t.sf + t.ds*t.attacks, t.wf + t.attacks*t.dp - CENTER, t.ef + t.attacks*t.dp - CENTER  );
				for(int k = t.wf + t.attacks*t.dp; k<= t.ef + t.attacks*t.dp; k++)
				{
					heightnew[k] = max (t.sf + t.ds*t.attacks, heightnew[k]);
					if(height[k] < t.sf + t.ds*t.attacks )
						suc = true;
				}
				trib[days[i].second].attacks++;

				if(suc)
					total++;

				i++;
			}

			for(int o = 0; o< MAX; o++)
			{
				if(heightnew[o] != -1)
					height[o] = max(heightnew[o], height[o]);
			}
		}


		fprintf(out, "Case #%d: %d\n", z+1, total );
	}

	return 0;
}