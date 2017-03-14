#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<set>
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
int T,H,W,D;

int px,py;

//variables

//data structures
char HM[30][30];
vector<int> X;
vector<int> Y;

//functions
int gcd(int a, int b)//mÇ∆nÇÕê≥Ç≈Ç»ÇØÇÍÇŒÇ¢ÇØÇ»Ç¢
{
    if(b==0)return a;
    else return gcd(b, a%b);
}

void insrt(int dx1, int dx2, int dy1, int dy2)
{
	X.clear();
	Y.clear();

	int nx=0,ny=0;
	for(int i=1; i<=50; i++){
		if(i % 2==1)nx+=dx1;
		else nx+=dx2;

		for(int j=1; j<=50; j++){
			if(j % 2==1)ny+=dy1;
		    else ny+=dy2;

			X.push_back(nx);
			Y.push_back(ny);
		}
		ny=0;
	}
}

int chk()
{
	set<P> cor;
	
	for(int i=0; i<(signed)X.size(); i++){
		if(X[i]*X[i]+Y[i]*Y[i]>D*D)continue;
		int a=abs(X[i]),b=abs(Y[i]);
		cor.insert(P(X[i]/gcd(a,b), Y[i]/gcd(a,b)));
	}

	return cor.size();
}


void solve()
{
	int ans=0;
	
	int dx[2],dy[2];
	dx[0]=px*2-1;
	dx[1]=W*2-px*2-3;
	dy[0]=py*2-1;
	dy[1]=H*2-py*2-3;
	
	insrt(dx[1],dx[0],dy[0],dy[1]);
	ans+=chk();
	
	insrt(dx[1],dx[0],-1*dy[1],-1*dy[0]);
	ans+=chk();
	
	
	insrt(-1*dx[0],-1*dx[1],dy[0],dy[1]);
	ans+=chk();

	insrt(-1*dx[0],-1*dx[1],-1*dy[1],-1*dy[0]);
	ans+=chk();

	if(dx[0]<=D)ans++;
	if(dx[1]<=D)ans++;
	if(dy[0]<=D)ans++;
	if(dy[1]<=D)ans++;

	fout<<ans<<endl;
}

int main()
{
	fin.open("C:\\Users\\fumi\\Downloads\\D-small-attempt1.in");
	fout.open("C:\\Users\\fumi\\Downloads\\D-small-answer1.txt");
	foot.open("C:\\Users\\fumi\\Downloads\\D.txt");

	fin>>T;
	for(int i=0; i<T; i++){
		fout<<"Case #"<<i+1<<": ";
		foot<<"Case #"<<i+1<<": ";

		fin>>H>>W>>D;
		foot<<H<<" "<<W<<" "<<D<<endl;

		for(int j=0; j<H; j++){
			for(int k=0; k<W; k++){
				fin>>HM[j][k];
				if(HM[j][k]=='X'){
					px=k;
					py=j;
				}
			}
		}

		solve();
	}

	system("pause");
	return 0;
}