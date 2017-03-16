#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#define N 10000

using namespace std;


struct qq{
	int d,w,e,s;
} q[N];

int d,n,w,e,T,ans,s,dd,dp,ds,E,kol;

int add(int d,int w,int e,int s){
	kol++;
	q[kol].d=d,q[kol].w=w,q[kol].e=e,q[kol].s=s;
}

int a[100000];           

int main(void){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> T ;
	int v=0;
	while (T--){
		cin >> E;
		kol=0;                
		memset(q,0,sizeof(q));
		memset(a,0,sizeof(a));
		for (int i=0;i<E;i++){
			cin >> d >> n >> w >> e >> s >> dd >> dp >> ds ;           
			for (int j=0;j<n;j++) add(d+dd*j,w+dp*j,e+dp*j-1,s+ds*j);
		}
		ans=0;
		for (int i=1;i<=kol;i++) for (int j=i+1;j<=kol;j++) if (q[i].d>q[j].d) swap(q[i],q[j]);

		for (int i=1;i<=kol;i++) q[i].w+=300,q[i].e+=300;

		q[kol+1].d=-1;
		for (int i=1;i<=kol;i++){

			int f=0;

			for (int j=q[i].w;j<=q[i].e;j++) if (a[j]<q[i].s) f=1;

			ans+=f;

			if (q[i].d!=q[i+1].d){
				for (int p=1;p<=kol;p++) if (q[p].d==q[i].d){
					for (int j=q[p].w;j<=q[p].e;j++) if (a[j]<q[p].s) a[j]=q[p].s;
				}
			}
		}
		v++;
		cout << "Case #" << v << ": " << ans << endl;

	}	

	return 0;
}                          