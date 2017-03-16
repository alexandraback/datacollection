#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<iomanip>
#include<cmath>
#include<queue>
#include<limits>
using namespace std;

/*problems
*/

/*plans
*/

//classes & definitions
typedef pair<int,int> P;
typedef long long LL;

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

//input & output
ifstream fin;
ofstream fout,foot;
int T,N;
int S[400];

//constants
const int INF=INT_MAX/2;

//variables

//data structures

//functions
bool cmp(int x, int y)
{
	return x>y;
}

double ans[400];
void solve()
{
	memset(ans,0,sizeof(ans));
	priority_queue<P,vector<P>,less<P>> que;

	int sum=0;
	for(int i=0; i<N; i++){
		sum+=S[i];
		que.push(P(S[i],i));
	}

	int memo=sum;
	int cnt=N;

	for(int i=0; i<N; i++){
		P p=que.top();
		que.pop();

		if(p.first*cnt>=sum+memo){
			ans[p.second]=0.0;
			sum-=p.first;
			cnt--;
		}
		else{
			double d=(double(sum+memo)/cnt-p.first)/memo*100.0;
			ans[p.second]=d;
		}
	}
	

	for(int i=0; i<N; i++){
		fout.precision(6);
		fout<<fixed<<ans[i]<<" ";
	}
	fout<<endl;
}

int main()
{
	fin.open("C:\\Users\\fumi\\Downloads\\A-large.in");
	fout.open("C:\\Users\\fumi\\Downloads\\A-large-answer.txt");
	foot.open("C:\\Users\\fumi\\Downloads\\AA.txt");

	fin>>T;
	for(int i=0; i<T; i++){
		fout<<"Case #"<<i+1<<": ";
		cout<<"Case #"<<i+1<<endl;
		foot<<"Case #"<<i+1<<endl;

		fin>>N;
		for(int j=0; j<N; j++){
			fin>>S[j];
			foot<<S[j]<<" ";
		}
		foot<<endl;
		solve();
	}

	stop;
	return 0;
}