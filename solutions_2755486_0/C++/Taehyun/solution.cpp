#include<stdio.h>
#include<memory.h>
#include<algorithm>
FILE*in=fopen("input.txt","r");
FILE*out=fopen("output.txt","w");
struct LIST
{
	int d;
	int S,E;
	int P,s;
	bool operator()(LIST a,LIST b)
	{
		if(a.d!=b.d) return a.d<b.d;
		if(a.S!=b.S) return a.S<b.S;
		if(a.E!=b.E) return a.E<b.E;
		if(a.P!=b.E) return a.P<b.E;
		return 0;
	}
}list[501];
int N,M;
int X[501],X2[501],K,K2;
int f;
int Find(int s,int e)
{
	int m=(s+e)/2;
	if(X[m]==f) return m;
	if(X[m]<f) return Find(m+1,e);
	return Find(s,m-1);
}
int MAX[200001];
int main()
{
	int T,t;
	fscanf(in,"%d",&T);
	int i,j,k,Start=1;
	int di,ni,wi,ei,si,ddi,dpi,dsi;
	int s,e,x,y,S,E;
	int Ans,Min,flag;
	for(t=1;t<=T;t++)
	{
		fscanf(in,"%d",&M);
		K2=0;
		N=0;
		Ans=0;
		for(i=1;i<=M;i++)
		{
			fscanf(in,"%d %d %d %d %d %d %d %d",&di,&ni,&wi,&ei,&si,&ddi,&dpi,&dsi);
			for(j=0;j<ni;j++)
			{
				list[++N].d=di+j*ddi;
				list[N].S=wi+j*dpi;
				list[N].E=ei+j*dpi;
				list[N].P=si+j*dsi;
				list[N].s=0;
				X2[++K2]=list[N].S;
				X2[++K2]=list[N].E;
			}
		}
		std::sort(list+1,list+1+N,LIST());
		std::sort(X2+1,X2+1+K2);
		X[1]=X2[1]; K=1;
		Start=1;
		for(i=2;i<=K2;i++) if(X2[i]!=X2[i-1]) X[++K]=X2[i];
		while(Start<K) Start*=2;
		memset(MAX,0,sizeof(MAX));
		// memset(MaxTree,12,sizeof(MaxTree)); // 202116108
		for(i=1;i<=N;i++)
		{
			s=i;
			for(e=i;e<=N;e++) if(list[e].d!=list[s].d) break;
			e--;
			for(j=s;j<=e;j++)
			{
				f=list[j].S;
				x=Find(1,K);
				f=list[j].E;
				y=Find(1,K);
				flag=0;
				Min=202116108;
				for(k=x;k<y;k++) 
				{
					if(Min>MAX[k]) Min=MAX[k];
				}
				if(Min<list[j].P)
				{
					list[j].s=1;
					Ans++;
				}
			}
			for(j=s;j<=e;j++)
			{
				if(!list[j].s) continue;
				f=list[j].S;
				S=Find(1,K);
				f=list[j].E;
				E=Find(1,K);
				for(k=S;k<E;k++)
				{
					if(MAX[k]<list[j].P) MAX[k]=list[j].P;
				}
			}
			i=e;
		}
		fprintf(out,"Case #%d: %d\n",t,Ans);
	}
}