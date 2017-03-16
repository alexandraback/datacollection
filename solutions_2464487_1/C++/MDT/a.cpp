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
int T,N;
LL r,t,lim;//r‚É‘Î‚µ‚Ä‚ÌãŒÀ

//data structures

//functions
bool chk(LL x)
{
	double xx=x,rr=r;
	if(2*xx*xx+(2*rr-1)*x>=2000000000000000000)return 0;

	if(x*x*2+(2*r-1)*x<=t)return 1;
	else return 0;
}

void solve()
{
	LL lb=0,ub=1414213563;

	for(int i=0; i<200 && ub-lb>0; i++){
		LL mid=(ub+lb)/2;
		if(chk(mid))lb=mid;
		else ub=mid;
	}

	fout<<lb<<endl;
}


int main()
{
	fin.open("C:\\Users\\fumi\\Downloads\\A-large.in");
	fout.open("C:\\Users\\fumi\\Downloads\\A-large-answer.txt");
	foot.open("C:\\Users\\fumi\\Downloads\\A-large-sample.txt");

	fin>>T;

	fi(0,T){
		fin>>r>>t;
		fout<<"Case #"<<i+1<<":"<<" ";
		solve();
	}

	fin.close();
	fout.close();
	foot.close();

	system("pause");
	return 0;
}