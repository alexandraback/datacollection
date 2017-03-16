#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#define eps 1e-10
#define MMM 100
using namespace std;

#define MP make_pair
#define PB push_back

int c[60],s[60],p[60];
int n,T;
vector<double> t;
int f[60][MMM],tf[60][MMM];
int M;
pair<double,double> ot[60][60];

bool overlap(int i,int j,int k){
	return t[k]>ot[i][j].first+eps&&t[k]<ot[i][j].second-eps;
	double pi=p[i]+t[k]*s[i];
	double pj=p[j]+t[k]*s[j];
	double l=max(pi,pj)-5,r=min(pi,pj);
	//if (i==2||j==2) cout<<t[k]<<' '<<pi<<' '<<pj<<' '<<r-l<<endl;
	return r-l>eps;
}
bool overlap2(int i,int j,int k){
	//if (max(ot[i][j].first,t[k-1])+eps<min(ot[i][j].second,t[k])) 		cout<<i<<' '<<j<<' '<<t[k-1]<<' '<<t[k]<<endl;
	return max(ot[i][j].first,t[k-1])+eps<min(ot[i][j].second,t[k]);
	if (overlap(i,j,k)||overlap(i,j,k+1)) return true;
	double pi1=p[i]+t[k]*s[i];
	double pj1=p[j]+t[k]*s[j];
	double pi2=p[i]+t[k+1]*s[i];
	double pj2=p[j]+t[k+1]*s[j];
	if (pi1<pj1+eps&&pi2>pj2-eps) return true;
	if (pi1>pj1-eps&&pi2<pj2+eps) return true;
	return false;
}

bool check(int i,int j,int k){
	if (j>M) return true;
	if (f[i][j]==-1){
		f[i][j]=k;
		for (int z=0;z<n;z++)if (z!=i){
			if (overlap2(i,z,j)){
				if (!check(z,j,1-k)) return false;
			}
		}
		bool canchange=true;
		for (int z=0;z<n;z++) if (z!=i) canchange&=!overlap(i,z,j);
		if (!canchange&&!check(i,j+1,k)) return false;
		return true;
	}
	else return f[i][j]==k;
}

bool check(int m){
	M=m;
	memset(f,-1,sizeof(f));
	for (int i=0;i<n;i++) if (!check(i,1,c[i])) return false;
	for (int i=0;i<n;i++)
	for (int j=1;j<=m;j++) if (f[i][j]==-1){
		memcpy(tf,f,sizeof(f));
		if (!check(i,j,0)){
			memcpy(f,tf,sizeof(f));
			if (!check(i,j,1)) return false;
		}
	}
	return true;
	printf("M= %d\n",m);
	for (int i=0;i<n;i++){
		for (int j=1;j<=m;j++) printf("%d ",f[i][j]);puts("");
	}
	return true;
}
pair<double,double> getot(double pi,double si,double pj,double sj){
	if (si<sj) swap(pi,pj),swap(si,sj);
	if (fabs(si-sj)<eps){
		if (max(pi-5,pj-5)+eps<min(pi,pj)) return MP(-1e100,1e100);
		return MP(1e100,-1e100);
	}
	return MP((pj-5-pi)/(si-sj),((pj-pi+5)/(si-sj)));
}
int main(){
	scanf("%d",&T);
	for (int ti=1;ti<=T;ti++){
		scanf("%d",&n);
		for (int i=0;i<n;i++){
			char t[10];
			scanf("%s%d%d",t,&s[i],&p[i]);
			c[i]=t[0]=='R';
		}
		for (int i=0;i<n;i++)
		for (int j=0;j<n;j++) {
			ot[i][j]=getot(p[i],s[i],p[j],s[j]);
			//printf("%d %d %.3f %.3f\n",i,j,ot[i][j].first,ot[i][j].second);
		}
		t.clear();
		t.PB(0);t.PB(0);
		t.PB(1e10);
		for (int i=0;i<n;i++)
		for (int j=0;j<n;j++) if (i!=j&&s[i]>s[j]){
			if (p[i]<p[j]-5)
				t.PB((p[j]-5-p[i])/(double)(s[i]-s[j]));
			if (p[i]-5<p[j])
				t.PB((p[j]-p[i]+5)/(double)(s[i]-s[j]));
		}
		if (t.size()>MMM) puts("TO LARGE");
		sort(t.begin(),t.end());
		int l=0,r=t.size();
		for (;l<r-1;){
			int t=(l+r)/2;
			if (check(t)) l=t;
			else r=t;
		}
		if (l==t.size()-1){
			printf("Case #%d: Possible\n",ti);
		}
		else printf("Case #%d: %.10f\n",ti,t[l]);
	}
    return 0;
}
