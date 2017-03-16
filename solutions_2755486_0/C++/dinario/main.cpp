#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <fstream>
using namespace std;
#define fon(i,n) for(i=0;i<n;++i)
#define re return
#define ll long long
const double EPS = 1E-9;const int INF = 1000000000;const ll INF64 = (ll)1E18;const double PI = 3.1415926535897932384626433832795;

ll x,y;

typedef struct{ll d,w,e,s;}tpo;

bool tcomp(tpo a,tpo b){
	return a.d<b.d;
}

int main()
{
	//ifstream cin("input.txt");
	ifstream cin("C-small-attempt0.in");
	ofstream cout("output.txt");
	
	ll i,j,n,m,T,t,k,N;
	ll d,w,e,s,dd,dp,ds;
	cin>>T;
	tpo *all=new tpo[2000000];
	//tpo all[200];
	ll iall=0;
	int *fl=new int[2000000];
	for(t=0;t<T;++t){
		iall=0;
		cin>>N;fon(i,N){
			cin>>d>>n>>w>>e>>s>>dd>>dp>>ds;
			fon(j,n){
				all[iall].d=d;
				all[iall].w=w;
				all[iall].e=e;
				all[iall].s=s;
				d+=dd;w+=dp;e+=dp;s+=ds;iall++;
			}
		}
		sort(all,all+iall,tcomp);
		memset(fl,0,sizeof(int)*2000000);int df=1000000;ll res=0;
		fon(i,iall){
			int smin=INF;
			for(j=all[i].w;j<all[i].e;++j)
				if(fl[df+j]<smin)smin=fl[df+j];
			if(smin<all[i].s)res++;

			if(i==iall-1||all[i].d!=all[i+1].d){
				for(k=i;k>=0&&all[k].d==all[i].d;--k)if(all[k].d==all[i].d){
					for(j=all[k].w;j<all[k].e;++j){
						if(fl[df+j]<all[k].s)
							fl[df+j]=all[k].s;
					}
				}
			}
		}cout<<"Case #"<<t+1<<": "<<res<<endl;
	}
	re 0;
}