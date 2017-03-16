#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

/*problems
*/

/*plans
*/

//classes
typedef pair<int,int> P;
typedef long long LL;

//constants
ifstream fin;
ofstream fout,foot;
int T,N,S,p;

//variables

//data structures
int g[100];

//functions
void solve()
{
	int ans=0;

	sort(g,g+N);

	int i=N-1;
	while(i>=0 && p*3-2<=g[i]){
		i--;
		ans++;
	}

	for(int j=i; j>=max(i-S+1,0); j--){
		if(p<=1 && g[j]>=p)ans++;
		if(1<p && p*3<=g[j]+4)ans++;
	}

	fout<<ans<<endl;
}

int main()
{
	fin.open("C:\\Users\\fumi\\Downloads\\B-large.in");
	fout.open("C:\\Users\\fumi\\Downloads\\B-large-answer.txt");

	fin>>T;
	foot<<T<<endl;
	for(int i=0; i<T; i++){
		fout<<"Case #"<<i+1<<": ";

		fin>>N>>S>>p;
		for(int j=0; j<N; j++)fin>>g[j];

		solve();
	}

	system("pause");
	return 0;
}