#include<cstdio>
#include<cstring>
#include<set>

using namespace std;

#define MX 1001
#define INF MX*MX

int H[5*MX*MX];

void setH(int id,int zac,int kon,int h,int a,int b,int oldh){
	if (oldh>H[id])
		H[id]=oldh;
	if (a<=zac&&b>=kon){
		if (h>H[id])
			H[id]=h;
	//printf("setH: %d %d %d %d\n",id,zac,kon,h);
		return;
	}
	if (a>=kon||b<=zac)
		return;
	//printf("setH: %d %d %d %d\n",id,zac,kon,h);
	int m=(zac+kon)/2;
	setH(id*2,zac,m,h,a,b,H[id]);
	setH(id*2+1,m,kon,h,a,b,H[id]);
}

int setH2(int id,int zac,int kon,int h,int x){
	if (zac==x&&zac+1==kon){
		if (h>H[id])
			H[id]=h;
		return H[id];
	}
	if (x>=kon||x<zac)
		return H[id];
	//printf("setH: %d %d %d %d\n",id,zac,kon,h);
	int m=(zac+kon)/2;
	int h1=setH2(id*2,zac,m,h,x);
	int h2=setH2(id*2+1,m,kon,h,x);
	return H[id]=min(h1,h2);
}

int getH(int id,int zac,int kon,int a,int b,int oldh){
	if (a<=zac&&b>=kon){
		//printf("getH: %d %d %d %d\n",id,zac,kon,H[id]);
		return H[id];
	}
	//printf("getH: %d %d %d %d %d\n",id,zac,kon,a,b);
	if (a>=kon||b<=zac)
		return 1<<29;
	int m=(zac+kon)/2;
	int h1=getH(id*2,zac,m,a,b,H[id]);
	int h2=getH(id*2+1,m,kon,a,b,H[id]);
	//printf("getH: %d %d %d %d\n",id,zac,kon,min(h1,h2));
	return min(h1,h2);
}

int n;
int D[MX],N[MX],W[MX],E[MX],S[MX],dD[MX],dP[MX],dS[MX];
set<pair<int,int> > q;

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;++t){
		printf("Case #%d: ",t);
		memset(H,0,sizeof H);
		scanf("%d",&n);
		q.clear();
		for(int i=0;i<n;++i){
			scanf("%d%d%d%d%d%d%d%d",D+i,N+i,W+i,E+i,S+i,dD+i,dP+i,dS+i);
			q.insert(make_pair(D[i],i));
		}
		int vys=0;
		while(q.size()){
			int dnes=q.begin()->first;
			for(set<pair<int,int> >::iterator it=q.begin();it!=q.end()&&it->first==dnes;++it){
				int id=it->second;
				int h=getH(1,-INF,INF,W[id],E[id],0);
				//printf("%d %d %d %d\n",dnes,id,S[id],h);
				if (S[id]>h) ++vys;
			}
			while(q.size()&&q.begin()->first==dnes){
				int id=q.begin()->second;
				q.erase(q.begin());
				for(int i=W[id];i<E[id];++i)
					setH2(1,-INF,INF,S[id],i);
				D[id]+=dD[id];
				S[id]+=dS[id];
				W[id]+=dP[id];
				E[id]+=dP[id];
				N[id]--;
				if (N[id]){
					q.insert(make_pair(D[id],id));
				}
			}
		}
		printf("%d\n",vys);
	}
	return 0;
}
