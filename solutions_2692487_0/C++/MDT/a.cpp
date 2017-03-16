#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<queue>
#include<cmath>
#include<iomanip>
using namespace std;

//classes
typedef pair<int,int> P;
typedef long long LL;

//define
#define fi(a,b) for(int i=a; i<b; i++) 
#define fj(a,b) for(int j=a; j<b; j++) 
#define fk(a,b) for(int k=a; k<b; k++) 
#define clr(x) memset((x), 0, sizeof(x))
#define stop system("pause")

LL lmin(LL a, LL b)
{
	if(a<b)return a;
	else return b;
}
LL lmax(LL a, LL b)
{
	if(a>b)return a;
	else return b;
}

//constants
int INF=INT_MAX/2;
LL lim=2000000;

//variables
ifstream fin;
ofstream foot,fout;
LL T,A,N,mote[200];

//data structures
LL dp[200][200];//dp[i+1][j]‚Æ‚Íi”Ô–Ú‚Ü‚Å‚Éj‰ñg‚Á‚Ä‹zû‚µ‚½‚ÌA‚ÌÅ‘å’l

//functions
void solve()
{
	sort(mote,mote+N);

	memset(dp,-1,sizeof(dp));
	dp[0][0]=A;

	for(int i=0; i<N; i++){
		for(int j=0; j<=N; j++){
			if(dp[i][j]<0)continue;

			dp[i][j+1]=lmax(dp[i][j+1],dp[i][j]*2-1);
			dp[i][j+1]=lmin(dp[i][j+1],lim);

			if(dp[i][j]>mote[i]){
				dp[i+1][j]=lmax(dp[i+1][j],dp[i][j]+mote[i]);
				dp[i+1][j]=lmin(dp[i+1][j],lim);
			}

			if(dp[i][j]*2-1>mote[i]){
				dp[i+1][j+1]=lmax(dp[i+1][j+1],dp[i][j]*2-1+mote[i]);
				dp[i+1][j+1]=lmin(dp[i+1][j+1],lim);
			}
			else{
				dp[i+1][j+1]=lmax(dp[i+1][j+1],dp[i][j]);
                dp[i+1][j+1]=lmin(dp[i+1][j+1],lim);
			}
		}
	}

	fi(0,N+1){
		if(dp[N][i]>=0){
			fout<<i<<endl;
			return;
		}
	}
}

int main()
{
	fin.open("C:\\Users\\fumi\\Downloads\\A-small-attempt3.in");
	fout.open("C:\\Users\\fumi\\Downloads\\A-small-answer.txt");
	foot.open("C:\\Users\\fumi\\Downloads\\A-small-sample.txt");

	fin>>T;

	fi(0,T){
		fin>>A>>N;
		fj(0,N)fin>>mote[j];
	
		foot<<"Case #"<<i+1<<":"<<" ";
		foot<<A<<endl;
		fj(0,N)foot<<mote[j]<<" ";
		foot<<endl;

	    fout<<"Case #"<<i+1<<":"<<" ";
		solve();
	}

	fin.close();
	fout.close();
	foot.close();

	system("pause");
	return 0;
}