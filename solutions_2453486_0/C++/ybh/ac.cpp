#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

//#define maxn 100010
//#define maxm 200010
//#define mm 1000000007LL 

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

string a[4];

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
	
	int T;
	scanf("%d",&T);
	for (int TT=1;TT<=T;TT++)
	{
		printf("Case #%d: ",TT);
		bool pointflag=false;
		for (int i=0;i<4;i++)
		{
			cin>>a[i];
			int position=a[i].find(".");
			if (position!=a[i].npos) pointflag=true;
		}
		bool findans=false;
		bool tflag,ansflag;
		int sum;
		
		for (int i=0;i<4;i++)
		{
			tflag=false,ansflag=true;
			sum=0;
			for (int j=0;j<4;j++)
				if (a[i][j]=='O') 
					sum+=0;
				else
					if (a[i][j]=='X')
						sum+=1;
					else
						if (a[i][j]=='T')
							tflag=true;
						else
							if (a[i][j]=='.')
							{
								ansflag=false;
								break;
							}
			if (ansflag && sum==0)
			{
				findans=true;
				printf("O won\n");
				break;
			}
			if (ansflag && (sum==4 || (sum==3 && tflag)))
			{
				findans=true;
				printf("X won\n");
				break;
			}
			
			tflag=false,ansflag=true;
			sum=0;
			for (int j=0;j<4;j++)
				if (a[j][i]=='O') 
					sum+=0;
				else
					if (a[j][i]=='X')
						sum+=1;
					else
						if (a[j][i]=='T')
							tflag=true;
						else
							if (a[j][i]=='.')
							{
								ansflag=false;
								break;
							}
			if (ansflag && sum==0)
			{
				findans=true;
				printf("O won\n");
				break;
			}
			if (ansflag && (sum==4 || (sum==3 && tflag)))
			{
				findans=true;
				printf("X won\n");
				break;
			}
		}
		if (findans) continue;
		
		tflag=false,ansflag=true;
		sum=0;
		for (int i=0;i<4;i++)
			if (a[i][i]=='O') 
				sum+=0;
			else
				if (a[i][i]=='X')
					sum+=1;
				else
					if (a[i][i]=='T')
						tflag=true;
					else
						if (a[i][i]=='.')
						{
							ansflag=false;
							break;
						}
		if (ansflag && sum==0)
		{
			findans=true;
			printf("O won\n");
			continue;
		}
		if (ansflag && (sum==4 || (sum==3 && tflag)))
		{
			findans=true;
			printf("X won\n");
			continue;
		}
		
		tflag=false,ansflag=true;
		sum=0;
		for (int i=0;i<4;i++)
			if (a[i][3-i]=='O') 
				sum+=0;
			else
				if (a[i][3-i]=='X')
					sum+=1;
				else
					if (a[i][3-i]=='T')
						tflag=true;
					else
						if (a[i][3-i]=='.')
						{
							ansflag=false;
							break;
						}
		if (ansflag && sum==0)
		{
			findans=true;
			printf("O won\n");
			continue;
		}
		if (ansflag && (sum==4 || (sum==3 && tflag)))
		{
			findans=true;
			printf("X won\n");
			continue;
		}
		
		if (pointflag)
			printf("Game has not completed\n");
		else
			printf("Draw\n");
	}
	
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
