#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

int t;
int l1, l2, s;
char appear[100]={0};
char target[200]={0};
vector<char> ready;

const double INF = 1e12;
double all_poss;
double e_cost=0;
double max1=0;
char now_str[100];

void DFS(int now, double pos)
{
	//cout<<"now: "<<now<<" pos: "<<pos<<endl;
	if(now==s+1)
	{
		//cout<<now_str<<endl;
		
		double now_sum=0;
		char *p = now_str;
		while(true)
		{
			p = strstr(p, target);
			if(p==NULL)
				break;
			p++;
			now_sum++;
		}
		//cout<<"ns: "<<now_sum<<endl;
		max1 = max(now_sum, max1);
		e_cost += now_sum * (pos/all_poss);
		return;
	}
	for(int i=0; i<ready.size(); i++)
	{
		now_str[now-1] = ready[i];
		DFS(now+1, pos * appear[ready[i]]);
		now_str[now-1] = 0;
	}
	return;
}

void init()
{
	memset(appear,0,sizeof(appear));
	memset(target,0,sizeof(target));
	max1=0;
	e_cost=0;
	all_poss=1;
	ready.clear();
}

int main()
{
	freopen("Bsmall.in","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>t;
	for(int files=1 ; files<=t; files++)
	{
		init();
		cin>>l1>>l2>>s;
		int i;
		for(i=1;i<=l1; i++)
		{
			char tmp;
			cin>>tmp;
			if(appear[tmp] == 0)
			{
				ready.push_back(tmp);
			}
			appear[tmp]++;
		}
		cin>>target;
		
		all_poss = pow(l1, s);
		
		DFS(1,1);
		printf("Case #%d: %.10lf\n", files, max1 - e_cost);
	}
	//system("pause");
	return 0;
}
















