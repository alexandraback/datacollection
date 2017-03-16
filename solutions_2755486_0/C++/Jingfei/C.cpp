#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Attack{
	int S,beg,end,Day;
	bool Suc;
	bool operator<(const Attack &t)const{
		if(Day==t.Day){
			return S<t.S;
		}
		return Day<t.Day;
	}
}Att[1000010];

int Wall1[1000010];
int Wall2[1000010];

int main(){
	int T;
	scanf("%d",&T);
	for(int Case=1; Case<=T; Case++){
		int N;
		int Att_n=0;
		scanf("%d",&N);
		while(N--){
			int d,n,w,e,s,dd,dp,ds;
			scanf("%d%d%d%d%d%d%d%d",&d,&n,&w,&e,&s,&dd,&dp,&ds);
			for(int i=0; i<n; i++){
				Att[Att_n].Day=d; d+=dd;
				Att[Att_n].beg=w; w+=dp;
				Att[Att_n].end=e; e+=dp;
				Att[Att_n].S=s; s+=ds;
				Att_n++;
			}
		}
		sort(Att,Att+Att_n);
		memset(Wall1,0,sizeof(Wall1));
		memset(Wall2,0,sizeof(Wall2));
		long long int ans=0;
		int tmp_beg=0;
		bool tmp_b=false;
		for(int i=0; i<Att_n; i++){
			if(i!=Att_n-1 && Att[i].Day==Att[i+1].Day){
				if(!tmp_b){tmp_b=true; tmp_beg=i;}
				int B=Att[i].beg, E=Att[i].end, S=Att[i].S;
				int b1,b2,e1,e2;
				if(B>=0 && E>=0){ b2=B; e2=E; b1=e1=-1;}
				else if(B<=0 && E<=0){ b1=E*(-1); e1=B*(-1); b2=e2=-1;}
				else if(B<=0 && E>=0){ e1=B*(-1); b1=0; b2=0; e2=E;}
				
				int Suc=false;
				for(int j=b1+1; j<=e1; j++)
					if(Wall1[j]<S){Suc=true;}
				for(int j=b2+1; j<=e2; j++)
					if(Wall2[j]<S){Suc=true;}
				if(Suc){
//					printf("Day:%d Beg:%d End:%d S:%d\n",Att[i].Day,B,E,S);
					ans++;
				}
				continue;
			}
			if(tmp_b){
				tmp_b=false;
				for(int k=i; k>=tmp_beg; k--){		
					int B=Att[k].beg, E=Att[k].end, S=Att[k].S;
					int b1,b2,e1,e2;
					if(B>=0 && E>=0){ b2=B; e2=E; b1=e1=-1;}
					else if(B<=0 && E<=0){ b1=E*(-1); e1=B*(-1); b2=e2=-1;}
					else if(B<=0 && E>=0){ e1=B*(-1); b1=0; b2=0; e2=E;}

					int Suc=false;
					for(int j=b1+1; j<=e1; j++)
						if(Wall1[j]<S){Wall1[j]=S; Suc=true;}
					for(int j=b2+1; j<=e2; j++)
						if(Wall2[j]<S){Wall2[j]=S; Suc=true;}
					if(k==i && Suc){
						ans++;
					}
				}
				continue;
			}
			int B=Att[i].beg, E=Att[i].end, S=Att[i].S;
			int b1,b2,e1,e2;
			if(B>=0 && E>=0){ b2=B; e2=E; b1=e1=-1;}
			else if(B<=0 && E<=0){ b1=E*(-1); e1=B*(-1); b2=e2=-1;}
			else if(B<=0 && E>=0){ e1=B*(-1); b1=0; b2=0; e2=E;}
		//	if(B==0) b1=b2=e1=0;
		//	if(E==0) e1=e2=b2=0;
			int Suc=false;
			for(int j=b1+1; j<=e1; j++)
				if(Wall1[j]<S){Wall1[j]=S; Suc=true;}
			for(int j=b2+1; j<=e2; j++)
				if(Wall2[j]<S){Wall2[j]=S; Suc=true;}
			if(Suc){
//				printf("Day:%d Beg:%d End:%d S:%d\n",Att[i].Day,B,E,S);
				ans++;
			}
		}
//		for(int i=0; i<10; i++) printf("%d ",Wall1[i]); printf("\n");
		printf("Case #%d: %lld\n",Case,ans);
	}
	return 0;
}
