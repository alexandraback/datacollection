#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
map<pair<pair<int, int>, int>, pair<int, int> > p;
queue<pair<long long, long long> > q;
int b[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
stack<char> st;
long long t,x,y;
int wave(int x, int y)
{
    x+=250000; y+=250000;
    while(!q.empty()) q.pop();
    p.clear();
    q.push(make_pair(250000,1));
    q.push(make_pair(250000,1));
    while(!q.empty())
    {
        int p1=q.front().first; q.pop();
        int p2=q.front().first; int j=q.front().second; q.pop();
        for(int i=0; i<=3; i++)
        {
            int pp1=p1+b[i][0]*j;
            int pp2=p2+b[i][1]*j;
            if(pp1>=0&&pp1<=500000&&pp2>=0&&pp2<=500000)
            {
                q.push(make_pair(pp1,j+1)); q.push(make_pair(pp2,j+1));
                p[make_pair(make_pair(pp1,pp2),j)]=make_pair(p1,p2);
                if(pp1==x&&pp2==y) {return j;}
            }
        }
    }
}
int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B-small-attempt1.out","w",stdout);
	//ifstream cin;
	//ofstream cout;
	//cin.open(".in");
	//cout.open(".out");
	scanf("%lld",&t);
	for(int o=1; o<=t; o++)
	{
	    scanf("%lld%lld",&x,&y);
	    //int g=wave(x,y);
	    printf("Case #%d: ",o);
        if(x>0)
        {
            for(int i=1; i<=x; i++)
            {
                printf("WE");
            }
        }
        else if(x<0)
        {
            for(int i=1; i<=x*-1; i++)
            {
                printf("EW");
            }
        }
        if(y>0)
        {
            for(int i=1; i<=y; i++)
                printf("SN");
        }
        else if(y<0)
        {
            for(int i=1; i<=y*-1; i++)
                printf("NS");
        }
	    printf("\n");
	}
	//cin.close();
	//cout.close();
	return 0;
}
