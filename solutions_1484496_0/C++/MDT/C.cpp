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
#include<set>
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
int a[1000];

//constants
const int INF=INT_MAX/2;

//variables

//data structures

//functions
int d[3000000];
void solve()
{
	memset(d,0,sizeof(d));
	set<int> s;

	int mx=(1<<N)-1;
	for(int i=0; i<=mx; i++){
		vector<int> num;
		int sum=0;
		for(int j=0; j<N; j++){
			if(i&(1<<j)){
				num.push_back(a[j]);
				sum+=a[j];
			}
		}

		if(s.find(sum)!=s.end()){
			for(int k=0; k<(signed)num.size(); k++)fout<<num[k]<<" ";
			fout<<endl;
			for(int k=0; k<N; k++){
				if(d[sum]&(1<<k))fout<<a[k]<<" ";
			}
			fout<<endl;
			return;
		}
		else{
			d[sum]=i;
			s.insert(sum);
		}
	}

	fout<<"Impossible"<<endl;
}

int main()
{
	fin.open("C:\\Users\\fumi\\Downloads\\C-small-attempt1.in");
	fout.open("C:\\Users\\fumi\\Downloads\\C-small-answer.txt");
	foot.open("C:\\Users\\fumi\\Downloads\\CC.txt");

	fin>>T;
	for(int i=0; i<T; i++){
		fout<<"Case #"<<i+1<<":"<<endl;
		cout<<"Case #"<<i+1<<endl;
		foot<<"Case #"<<i+1<<endl;

		fin>>N;
		for(int j=0; j<N; j++){
			fin>>a[j];
			foot<<a[j]<<" ";
		}
		foot<<endl;

		solve();
	}

	stop;
	return 0;
}