#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<ctime>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cassert>
#include<bitset>

using namespace std;
typedef long long LL;
struct SS
{
	int idb,idc,key;
	SS(){}
	SS(int idb,int idc,int key):idb(idb),idc(idc),key(key){}
};
bool operator < (const SS &a,const SS &b){
	return a.key<b.key;	
}
priority_queue<SS> q;
int ab[11][11],ac[11][11],bc[11][11];
vector<SS> vec;
int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int numcase;
	cin>>numcase;
	for(int ii=1;ii<=numcase;ii++){
		int a,b,c,k;
		scanf("%d%d%d%d",&a,&b,&c,&k);
		for(int i=1;i<=b;i++)
		for(int j=1;j<=c;j++)	
			q.push(SS(i,j,k));
		for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			ab[i][j]=k;
		for(int i=1;i<=a;i++)
		for(int j=1;j<=c;j++)
			ac[i][j]=k;
		for(int i=1;i<=b;i++)
		for(int j=1;j<=c;j++)
			bc[i][j]=k;
		vec.clear();
		for(int i=1;i<=a;i++){
			while (!q.empty()) q.pop();
			for(int r=1;r<=b;r++)
			for(int t=1;t<=c;t++)
				if(bc[r][t]) q.push(SS(r,t,bc[r][t]));
			while (!q.empty())
			{
				SS tmp = q.top();
				q.pop();
				if(ab[i][tmp.idb] && ac[i][tmp.idc]){
					ab[i][tmp.idb]--;
					ac[i][tmp.idc]--;
					bc[tmp.idb][tmp.idc]--;
					vec.push_back(SS(i,tmp.idb,tmp.idc));
				}
			}
		}
		printf("Case #%d: %d\n",ii,vec.size());
		for(int i=0;i<vec.size();i++)
			printf("%d %d %d\n",vec[i].idb,vec[i].idc,vec[i].key);
	}
	return 0;
}
