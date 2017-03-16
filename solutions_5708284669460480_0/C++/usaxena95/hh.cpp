#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define fre 	freopen("0.in","r",stdin),freopen("0.out","w",stdout)
#define abs(x) ((x)>0?(x):-(x))
#define MOD 1000000007
#define lld signed long long int
#define pp pop_back()
#define ps(x) push_back(x)
#define mpa make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define scan(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define scanll(x) scanf("%lld",&x)
#define printll(x) printf("%lld\n",x)
#define boost ios_base::sync_with_stdio(0)
//vector<int> g[2*100000+5];int par[2*100000+5];
double P[299];
map<int,int>mp;
string TAR;
int K,L,S;
int where[130][29],lps[1000];
int calc(string pat)
{
	int M=pat.size();
   for(int i=1;i<=100;++i)
		lps[i]=0;
    lps[0] = 0; // lps[0] is always 0
    int len = 0;  // lenght of the previous longest prefix suffix
    int i = 1;

    // the loop calculates lps[i] for i = 1 to M-1
    while (i < M)
    {
       if (pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if (len != 0)
         {
           // This is tricky. Consider the example AAACAAAA and i = 7.
           len = lps[len-1];

           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }
    return lps[M-1];
}
void solve()
{
	for(int i=0;i<=L;++i)
	{
		for(int j=1;j<=26;++j)
		{
			string temp="";
			for(int k=1;k<=i;++k)
				temp += TAR[k];
			temp += (char)('A' + j -1);
			if(i<L and TAR[i+1]==(char)('A' + j -1))
				where[i][j]=i+1;
			else
				where[i][j]=calc(temp);
				//cout<<temp<<' '<<where[i][j]<<endl;
		}
	}
}
bool fdp[105][105];
double dp[105][105];
double rec(int s,int l)
{
	if(s==S+1)
		return l==L;
	if(fdp[s][l])
		return dp[s][l];
	fdp[s][l]=1;
	dp[s][l]=l==L;
	for(int i=1;i<=26;++i)
	{
		dp[s][l] += P[i] * rec(s+1,where[l][i]);
	}
	//cout<<s<<' '<<l<<'\t'<<dp[s][l]<<endl;
	return dp[s][l];
}
int dp2[1555],fdp2[55454];
int RR(int S,int L,int suf)
{
	if(S<L)
		return 0;
	if(fdp2[S])
		return dp2[S];
	fdp2[S]=1;
	dp2[S]=1+RR(S-L+suf,L,suf);
	return dp2[S];
}
int main()
{
	fre;
	int T;
	cin>>T;
	for(int t=1;t<=T;++t)
	{
		cin>>K>>L>>S;
		mp.clear();
		int F=0;
		for(int i=1;i<=K;++i)
		{
			char c;
			cin>>c;
			mp[c-'A'+1]++;
		}
		cin>>TAR;
		for(int i=0;i<TAR.size();++i)
		{
			if(mp[TAR[i]-'A' +1]==0)
				F=1;
		}
		TAR=" "+TAR;
		if(L>S or F==1)
		{
			printf("Case #%d: %0.6f\n",t,0.0);
			continue;
		}
		solve();

		for(int i=1;i<=26;++i)
		{
			P[i]=mp[i]*1.0/K;
		}
		double E=rec(1,0);
		int suf=calc(TAR.substr(1));
		int MAX=RR(S,L,suf);
		printf("Case #%d: %0.6f\n",t,MAX-E);
		for(int i=0;i<=100;++i)
			for(int j=0;j<=100;++j)
			fdp2[i]=fdp[i][j]=0,
			where[i][j]=0;
	}
}
