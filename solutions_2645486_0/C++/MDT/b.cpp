#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<queue>
#include<iomanip>
using namespace std;

/*problems
*/

/*plans
*/

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

//variables
ifstream fin;
ofstream foot,fout;
int T,E,R,N;
int v[20000];

//data structures
int dp[20][1000];//dp[i+1][j]とはi番目までにjジュール得る時の、残っている最大のE

//functions
void solve()
{
	memset(dp,-1,sizeof(dp));
	dp[0][0]=E;

	for(int i=0; i<N; i++){
		for(int j=0; j<=1000; j++){
			int r=dp[i][j];
			for(int k=0; k<=r; k++){
				dp[i+1][j+k*v[i]]=max(dp[i+1][j+k*v[i]],min(r-k+R,E));
			}
		}
	}

	int mx=0;
	for(int i=0; i<1000; i++){
		if(dp[N][i]>=0)mx=i;
	}

	fout<<mx<<endl;
}


int main()
{
	fin.open("C:\\Users\\fumi\\Downloads\\B-small-attempt3.in");
	fout.open("C:\\Users\\fumi\\Downloads\\B-small-answer.txt");
	foot.open("C:\\Users\\fumi\\Downloads\\B-small-sample.txt");

	fin>>T;
	fi(0,T){
		fin>>E>>R>>N;
		foot<<E<<" "<<R<<" "<<N<<endl;
		fj(0,N)fin>>v[j];
		fj(0,N)foot<<v[j]<<endl;
		fout<<"Case #"<<i+1<<":"<<" ";
		solve();
	}

	fin.close();
	fout.close();
	foot.close();

	system("pause");
	return 0;
}