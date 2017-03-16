#pragma comment(linker,"/STACK:256000000")
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <time.h>
using namespace std;
int main(){
	double ti=clock();
	//freopen("B-small-attempt0.in","r",stdin);
	freopen("B-large.in","r",stdin);
	//freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	cin>>T;
	int a[]={1,-1,0,0},b[]={0,0,1,-1};
	for(int t=0;t<T;t++){
		int h,n,m,H;
		cin>>h>>n>>m;
		H=h;
		vector<vector<int> > c(n,vector<int> (m));
		vector<vector<int> > f(n,vector<int> (m));
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>c[i][j];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>f[i][j];
		vector<vector<int> > us(n,vector<int> (m));
		us[0][0]=h;
		queue<pair<int,int> > q;
		set<pair<int,pair<int,int> > > s;
		q.push(make_pair(0,0));
		while(!q.empty()){
			int x,y;
			x=q.front().first;
			y=q.front().second;
			q.pop();
			int p=0;
			for(int k=0;k<4;k++)
				if(x+a[k]>=0 && y+b[k]>=0 && x+a[k]<n && y+b[k]<m)
					if(c[x+a[k]][y+b[k]]>=h+50 && c[x+a[k]][y+b[k]]>=f[x+a[k]][y+b[k]]+50 && c[x+a[k]][y+b[k]]>=f[x][y]+50 && c[x][y]>=f[x+a[k]][y+b[k]]+50)
						if(us[x+a[k]][y+b[k]]==0){
							p=1;
							us[x+a[k]][y+b[k]]=h;
							q.push(make_pair(x+a[k],y+b[k]));
						}
			if(p==0)
				s.insert(make_pair(-h,make_pair(x,y)));
		}
		int bad=1;
		for(;bad;h--){
			while(!s.empty() && s.begin()->first==-h){
				int x,y;
				x=s.begin()->second.first;
				y=s.begin()->second.second;
				s.erase(s.begin());
				//if(us[x][y]) continue;
				if(x+1==n && y+1==m){
					printf("Case #%d: %.6lf\n",t+1,double(H-h)/10);
					h=-1;
					bad=0;
					break;
				}
				for(int k=0;k<4;k++)
					if(x+a[k]>=0 && y+b[k]>=0 && x+a[k]<n && y+b[k]<m)
						if(c[x+a[k]][y+b[k]]>=f[x+a[k]][y+b[k]]+50 && c[x+a[k]][y+b[k]]>=f[x][y]+50 && c[x][y]>=f[x+a[k]][y+b[k]]+50)
						{
							if(us[x+a[k]][y+b[k]]==0)
							{
								if(c[x+a[k]][y+b[k]]>=h+50){
									us[x+a[k]][y+b[k]]= h- (h>=f[x][y]+20 ? 10 : 100);
									s.insert(make_pair(-(us[x+a[k]][y+b[k]]),make_pair(x+a[k],y+b[k])));
								}
								else{
									int p=c[x+a[k]][y+b[k]]-50;
									us[x+a[k]][y+b[k]]= p- (p>=f[x][y]+20 ? 10 : 100);
									s.insert(make_pair(-(us[x+a[k]][y+b[k]]),make_pair(x+a[k],y+b[k])));
								}
							}
							else
							{
								if(c[x+a[k]][y+b[k]]>=h+50){
									int u= h- (h>=f[x][y]+20 ? 10 : 100);
									if(u>us[x+a[k]][y+b[k]]){
										us[x+a[k]][y+b[k]]=u;
										s.insert(make_pair(-(us[x+a[k]][y+b[k]]),make_pair(x+a[k],y+b[k])));
									}
								}
								else{
									int p=c[x+a[k]][y+b[k]]-50;
									int u= p- (p>=f[x][y]+20 ? 10 : 100);
									if(u>us[x+a[k]][y+b[k]])
									{
										us[x+a[k]][y+b[k]]=u;
										s.insert(make_pair(-(us[x+a[k]][y+b[k]]),make_pair(x+a[k],y+b[k])));
									}
								}
							}
						}
			}
		}
	}
	//printf("%lf\n",(clock()-ti)/CLOCKS_PER_SEC);
}
