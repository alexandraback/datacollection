#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<cmath>
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
int T,A,B;

//variables

//data structures

//functions
void solve()
{
	int ans=0;

	for(int i=A; i<B; i++){
		int memo=i,d=0;
		while(memo>0){
			memo/=10;
			d++;
		}

		int w=10,k=(int)pow(10.0,(double)d);
		for(int j=1; j<=d; j++){
			int n=((i%w)*k+i-(i%w))/w;
			if(n<=B && i<n){
				ans++;
			}
			w*=10;
		}
	}

	fout<<ans<<endl;
}

int main()
{
	fin.open("C:\\Users\\fumi\\Downloads\\C-small-attempt0.in");
	fout.open("C:\\Users\\fumi\\Downloads\\C-small-answer.txt");
	foot.open("C:\\Users\\fumi\\Downloads\\CC.txt");

	fin>>T;
	for(int i=0; i<T; i++){
		fout<<"Case #"<<i+1<<": ";
		fin>>A>>B;
		solve();
	}

	system("pause");
	return 0;
}