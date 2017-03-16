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

//variables
ifstream fin;
ofstream foot,fout;
int T,N,X,Y;

//data structures

//functions
double dp[100][100][100];
P table[20000];

void init()
{
	memset(dp,0,sizeof(dp));
	dp[1][1][1]=1.0;

	fi(1,30){
		fj(1,30){
			fk(1,30){
				if(dp[i][j][k]==0.0)continue;

				if(j==3 && k==3)dp[i+1][j+1][k+1]+=dp[i][j][k];
				else if(j<k && k==3)dp[i+1][j+1][k]+=dp[i][j][k];
				else if(j>k && j==3)dp[i+1][j][k+1]+=dp[i][j][k];
				else if(j==8 && k==8)dp[i+1][j+1][k+1]+=dp[i][j][k];
				else if(j<k && k==8)dp[i+1][j+1][k]+=dp[i][j][k];
				else if(j>k && j==8)dp[i+1][j][k+1]+=dp[i][j][k];
				else{
					dp[i+1][j+1][k]+=0.5*dp[i][j][k];
					dp[i+1][j][k+1]+=0.5*dp[i][j][k];
				}

				dp[i+1][j][k]=min(1.0,dp[i+1][j][k]);
				dp[i+1][j+1][k]=min(1.0,dp[i+1][j+1][k]);
				dp[i+1][j][k+1]=min(1.0,dp[i+1][j][k+1]);
				dp[i+1][j+1][k+1]=min(1.0,dp[i+1][j+1][k+1]);
			}
		}
	}

	table[1]=P(0,0);
	int mx=0;
	fi(1,10000){
		int x=table[i].first,y=table[i].second;
		
		if(x==0){
			table[i+1]=P(mx+2,0);
			mx+=2;
		}
		else table[i+1]=P(x-1,y+1);
	}
}

void solve()
{
	bool r=1;
	int b=-1;

	if(X<0){
		r=0;
		X*=-1;
	}

	fi(1,10000){
		if(table[i].first==X && table[i].second==Y){
			b=i;
			break;
		}
	}

	if(b<=0 || b>20){
		fout<<0.0<<endl;
		return;
	}

	double sum=0.0;
	fi(1,20){
		fj(1,20){
			if(r && b<=j)sum+=dp[N][i][j];
			if(!r && b<=i)sum+=dp[N][i][j];
		}
	}

	fout<<sum<<endl;
}


int main()
{
	fin.open("C:\\Users\\fumi\\Downloads\\B-small-attempt0.in");
	fout.open("C:\\Users\\fumi\\Downloads\\B-small-answer.txt");
	foot.open("C:\\Users\\fumi\\Downloads\\B-small-sample.txt");

	fin>>T;
	
	init();

	fi(0,T){
		fin>>N>>X>>Y;
		fout<<"Case #"<<i+1<<":"<<" ";

		foot<<"Case #"<<i+1<<":"<<" ";
		foot<<X<<" "<<Y<<endl;

		solve();
	}

	fin.close();
	fout.close();
	foot.close();

	system("pause");
	return 0;
}