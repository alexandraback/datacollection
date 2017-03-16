#include<cstdio>
#define LL long long
const LL INF=(1LL<<62);
void termin(){LL a[10];for(LL i=0;;i--)a[i]=100;}
void getmin(LL &a,LL b){if(b<a)a=b;}
LL T,L,X;
char S[10001];
LL MUL[8][8]={{0,1,2,3,4,5,6,7},{1,4,3,6,5,0,7,2}
	,{2,7,4,1,6,3,0,5},{3,2,5,4,7,6,1,0}
	,{4,5,6,7,0,1,2,3},{5,0,7,2,1,4,3,6}
	,{6,3,0,5,2,7,4,1},{7,6,1,0,3,2,5,4}};
LL DIV[8][8];//?*j=i
LL POS[10001];
LL toint(char a);
LL get_DIV(LL a,LL b);
LL SEG(LL l,LL r)
{
	return get_DIV(POS[l],POS[r+1]);
}
LL logto_(LL v,LL i)
{
	LL t=v,ans=0;
	LL mul=MUL[SEG(i,L-1)][SEG(0,i-1)];
	do
	{
		if(v==1)return ans;
		v=MUL[v][mul];
		ans+=L;
		t=MUL[t][mul];
		t=MUL[t][mul];
	}while(v!=t);
	return INF;
}
LL log_to(LL v,LL i)
{
	LL t=v,ans=0;
	LL mul=MUL[SEG(i,L-1)][SEG(0,i-1)];
	do
	{
		if(v==3)return ans;
		v=MUL[mul][v];
		ans+=L;
		t=MUL[mul][t];
		t=MUL[mul][t];
	}while(v!=t);
	return INF;
}
LL pow(LL v,LL p)
{
	LL ans=0;
	while(p)
	{
		if(p&1)
		{
			ans=MUL[ans][v];
		}
		p>>=1;
		v=MUL[v][v];
	}
	return ans;
}
bool solve()
{
	if(pow(SEG(0,L-1),X)!=MUL[MUL[1][2]][3])return false;
	LL l=INF,r=INF;
	for(LL i=0;i<L;i++)getmin(l,logto_(SEG(0,i-1),i)+i);
	for(LL i=0;i<L;i++)getmin(r,log_to(SEG(L-i,L-1),i)+i);
//	printf("%lld %lld\n",l==INF?-1:l,r==INF?-1:r);
	if(l>=L*X||r>=L*X||l+r>L*X)return false;
	return true;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	for(LL i=0;i<8;i++)
		for(LL j=0;j<8;j++)
			DIV[i][j]=-1;
	scanf("%lld",&T);
	int kase=1;
	while(T--)
	{
		scanf("%lld%lld%s",&L,&X,S);
		POS[L]=0;
		for(LL i=L-1;i>=0;i--)
			POS[i]=MUL[toint(S[i])][POS[i+1]];
		printf("Case #%d: ",kase++);
		if(solve())printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
LL toint(char a)
{
	switch(a)
	{
		case 'i':return 1;
		case 'j':return 2;
		case 'k':return 3;
		default:termin();
	}
}
LL get_DIV(LL a,LL b)
{
	LL &ans=DIV[a][b];
	if(ans!=-1)return ans;
	bool found=false;
	for(LL k=0;k<8;k++)
		if(MUL[k][b]==a)
		{
			found=true;
			ans=k;
		}
	if(!found)termin();
	return ans;
}
