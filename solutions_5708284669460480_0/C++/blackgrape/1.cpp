#include<bits/stdc++.h>
#define rep(i,x,y) for(i=x;i<y;i++)
#define rrep(i,x,y) for(i=x;i>=y;i--)
#define trv(y,x) for(typeof(x.rbegin())y=x.rbegin();y!=x.rend();y++)
#define pb(f) push_back(f)
#define sc(a) scanf("%d",&a)
#define scs(a) scanf("%s",a)
using namespace std;
//#include<windows.h>
FILE *fin = freopen("1.in","r",stdin);
FILE *fout = freopen("1.txt","w",stdout);
int dat[100];
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< pii > vpii;
char key[103],b[103],done[103];
void preprocessing(char* pat,int M,int *lps);
int global=0;
void KMPsearch(char* pat,char* txt)
{
	int M=strlen(pat);
	int N=strlen(txt);
	int *lps=(int *)malloc(M*sizeof(int));
	preprocessing(pat,M,lps);
	int i=0; //index for txt
	int j=0; //index for pat
	while(i<N)
	{
		if(pat[j]==txt[i])
		{
			j++;
			i++;
		}
		else
		{
			//i will only increase
			if(j!=0)
			j=lps[j-1];
			else
			i++;
		}
		if(j==M)
		{
			//pattern found
			//printf("pattern found at %d",i-j);
			global++;
			j=lps[j-1];
		}
	}
	free(lps);
}
void preprocessing(char* pat,int M,int *lps)
{
	int len=0;//length of previous maximum match
	int i=1; //pat fix var
	lps[0]=0;
	while(i<M)
	{
		if(pat[i]==pat[len])
		{
			lps[i]=++len;
			i++;
		}
		else if (len==0)
		{
			lps[i]=0;
			i++;
		}
		else
		{
			//main case
			len=lps[len-1];
			// This is tricky. Consider the example AAACAAAA and i = 7.
		}
	}
}
void rec(int k,int s, int lev)
{
	int i,j,m,n;
	if(lev==s)
	{
		global=0;
		done[lev]='\0';
		KMPsearch(b,done);
		dat[global]++;
		return;
	}
	rep(i,1,k+1)
	{
		done[lev]=key[i];
		rec(k,s,lev+1);
	}
}
int main()
{
	int t;
	sc(t);
	int casse=0;
	while(t--)
	{
		int k,l,s;
		double ans;
		casse++;
		int i;
		rep(i,0,100)
		dat[i]=0;
	//	recurse
		sc(k);sc(l);sc(s);
		scs(key+1);
		scs(b);
		rec(k,s,0);
		int maxi=-999;
		rep(i,0,100)
		{//cout<<dat[i]<<" ";
			if(dat[i]!=0)
			maxi=max(maxi,i);
		}
		int sum=0;
		rep(i,0,maxi+1)
		{
			dat[i]=dat[i]*(maxi-i);
			
			sum+=dat[i];
		}
		int num=pow(k,s);
		ans=(double)sum/num;
		printf("Case #%d: %lf\n",casse,ans);
	}
}
