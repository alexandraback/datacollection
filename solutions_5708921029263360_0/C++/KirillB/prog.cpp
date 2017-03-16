
#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <list>
#include <cassert>



using namespace std;
#pragma comment(linker, "/STACK:50000000")

typedef vector<int> vi; 
#define sz(a) int((a).size()) 
#define all(c) (c).begin(),(c).end() 

string problem_name = "C-small-attempt0(1)";

void init(){
  freopen((problem_name+".in").c_str(),"rt",stdin);
  freopen((problem_name+".out").c_str(),"wt",stdout);
}


int u12[5][5];
int u13[5][5];
int u23[5][5];

int k;
int J,P,S;

int rmax;
int rj[55],rp[55],rs[55];
int aj[55],ap[55],as[55];
int go(int j, int p, int s, int cur)
{
	if (s>S)
	{
		s=1;
		p++;
		if (p>P)
		{
			p=1;
			j++;
			if (j>J)
			{
				if (cur>rmax)
				{
					for (int i=1;i<=cur;i++)
					{
						aj[i] = rj[i];
						ap[i] = rp[i];
						as[i] = rs[i]; 
					}

					rmax = cur;
					
				}
				return 0;
			
			}
		}
	}

	if (u12[j][p]<k && u13[j][s]<k && u23[p][s]<k)
	{
		u12[j][p]++;
		u13[j][s]++;
		u23[p][s]++;
		rj[cur+1]=j;
		rp[cur+1]=p;
		rs[cur+1]=s;
		go(j,p,s+1,cur+1);
		u12[j][p]--;
		u13[j][s]--;
		u23[p][s]--;	
	}

	go(j,p,s+1,cur);


}

int main()
{
	init();

	int tst;
	scanf("%d\n",&tst);

	for (int cas = 1; cas<=tst;cas++)
	{

		scanf("%d%d%d%d",&J,&P,&S,&k);
		memset(u12,0,sizeof(u12));
		memset(u23,0,sizeof(u12));
		memset(u13,0,sizeof(u12));
		rmax = 0;
		go(1,1,1,0);
		printf("Case #%d: %d\n",cas,rmax);
		for (int i=1;i<=rmax;i++)
		{			
			printf("%d %d %d\n",aj[i],ap[i],as[i]);
		}	
		
	
	}


	return 0;
}
