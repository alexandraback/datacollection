//Nakul Krishna
//Computer Science Engineering
//Amrita Vishwa Vidyapeetham

#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<climits>
#include<algorithm>
#include<sstream>
#include<queue>
#include<stack>

#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define pb push_back
#define mp make_pair

using namespace std;

unsigned long long mod=1000000007;
//WESN
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int main()
{
    
	int t,tt=1;
	scanf("%d",&t);
	while(tt<=t)
	{
		map<pair<int,int>,pair<int,int> > m;
		map<pair<int,int> ,int > vis;
		//memset(vis,0,sizeof vis);
		int px,py;
		scanf("%d%d",&px,&py);
		queue<int> q;
		queue<string> Q;
		q.push(0);
		q.push(0);
		q.push(1);
		Q.push("");
		vis[mp(0,0)]++;
		char ch[]={'W','E','S','N'};
		while(!q.empty())
		{
			int x=q.front();q.pop();
			int y=q.front();q.pop();
			int jump=q.front();q.pop();
			string ans=Q.front();Q.pop();
			if(px==x and py==y)
			{
                printf("Case #%d: ",tt);
				cout<<ans<<"\n";
				break;
			}
			for(int i=0;i<4;i++)
			{
				int cx=x+dx[i]*jump,cy=y+dy[i]*jump;
				if(cx>=-100 and cx<101 and cy>=-100 and cy<101)
				{
					if(vis.find(mp(cx,cy))==vis.end())
					{
						//m[mp(cx,cy)]=mp(tx,ty);
						vis[mp(cx,cy)]++;
						q.push(cx);
						q.push(cy);
						q.push(jump+1);
						string str=ans;
						str+=ch[i];
						Q.push(str);
					}
				}
			}
		}
		tt++;
	}
    scanf("\n");
    return 0;
}

//Nakul © Copyright 2012 - All Rights Reserved

