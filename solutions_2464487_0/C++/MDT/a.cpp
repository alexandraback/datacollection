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
int T,N;
LL r,t;

//data structures

//functions
void solve()
{
	int ans=0;

	while(t>=r*2+1){
		t-=r*2+1;
		r+=2;
		ans++;
	}

	fout<<ans<<endl;
}


int main()
{
	fin.open("C:\\Users\\fumi\\Downloads\\A-small-attempt0.in");
	fout.open("C:\\Users\\fumi\\Downloads\\A-small-answer.txt");
	foot.open("C:\\Users\\fumi\\Downloads\\A-small-sample.txt");

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