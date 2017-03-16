#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<cmath>
#include<set>
using namespace std;

/*problems
*/

/*plans
*/

//classes

//constants
ifstream fin;
ofstream fout,foot;
int T,A,B;

//variables

//data structures
int par[2000001];

//functions
void init1()
{
	memset(par,0,sizeof(par));
	for(int i=1; i<=100000; i*=10){

		for(int j=i; j<i*10; j++){
			if(par[j]!=0)continue;

			vector<int> num;
			num.push_back(j);
			int a=(j%i)*10+(j/i);
			while(a!=j){
				num.push_back(a);
				a=(a % i)*10+(a/i);
			}

			sort(num.begin(),num.end());
			for(int k=0; k<(signed)num.size()-1; k++){
				if(num[k]<i || num[k]==num[k+1])continue;
				else par[num[k]]=num[k+1];
			}
		}
	}
}

void init2()
{
	int d=1000000;

	for(int i=1000000; i<2000000; i++){
			if(par[i]!=0)continue;

			int num[7];
			int a=i;
			for(int j=0; j<7; j++){
			    num[j]=a;
				a=(a%d)*10+(a/d);
			}

			sort(num,num+7);

			for(int j=0; j<7; j++){
				if(num[j]<i || num[j]==num[j+1] || 2000000<=num[j])continue;
				else par[num[j]]=num[j+1];
			}
	}
}

void solve()
{
	int ans=0;
	int d=1000000;

	for(int i=A; i<B; i++){
		int memo=i;
		while(par[memo]>0 && par[memo]<=B){
			ans++;
			memo=par[memo];
		}
	}

	fout<<ans<<endl;
}

int main()
{
	init1();
	init2();

	fin.open("C:\\Users\\fumi\\Downloads\\C-large.in");
	fout.open("C:\\Users\\fumi\\Downloads\\C-large-answer.txt");

	fin>>T;
	for(int i=0; i<T; i++){
		fout<<"Case #"<<i+1<<": ";
		fin>>A>>B;

		solve();
	}

	system("pause");
	return 0;
}