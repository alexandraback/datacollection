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

//input & output
ifstream fin;
ofstream fout,foot;
int T,A,B;
double p[200000];

//constants
const int INF=INT_MAX/2;

//variables

//data structures

//functions
void solve()
{
	double res;

	//訂正せずに入力
	double pos=1.0;
	for(int i=0; i<A; i++)pos*=p[i];
	res=pos*(B-A+1)+(1.0-pos)*(B-A+1+B+1);

	//最初から打ち直し
	if(res>(double)B+2.0)res=(double)B+2.0;

	//i文字のバックスペース
	for(int i=1; i<=A; i++){
		double koho;
		//消去したより前が間違っていない確率
		double pp=1.0;
		for(int j=0; j<A-i; j++)pp*=p[j];
		koho=pp*(B-A+i*2+1)+(1.0-pp)*(B-A+i*2+1+B+1);
		if(koho<res)res=koho;
	}
	
	fout.precision(10);
	fout<<fixed<<res<<endl;

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

		fin>>A>>B;
		foot<<A<<" "<<B<<endl;
		for(int i=0; i<A; i++){
			fin>>p[i];
			foot<<p[i]<<" ";
		}
		foot<<endl;

		solve();
	}

	stop;
	return 0;
}