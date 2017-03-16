#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <iomanip>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

ifstream fin("C:\\Users\\Administrator\\Downloads\\A-large.in");
ofstream fout("C:\\Users\\Administrator\\Downloads\\A-large.out");

int N;
int M[1000];
int R[1000][1000];
int Count[1000];
std::vector<double> P;
double Ans;

bool myDFS(int i)
{
	int k;
	REP(k,M[i])
	{
		Count[R[i][k]]++;
		if(Count[R[i][k]]>1)
			return true;
		bool flag = myDFS(R[i][k]);
		if(flag==true)
			return true;
	}
	return false;

}

void solve()
{
	fin>>N;
	int i,j;
	REP(i,N)
	{
		fin>>M[i];
		REP(j,M[i])
		{
			fin>>R[i][j];
			R[i][j] = R[i][j]-1;
		}
	}

	REP(i,N){
		REP(j,N)
		{
			Count[j] = 0;
		}
		bool Flag = myDFS(i);
		if(Flag)
		{
			fout<<"Yes\n";
			return;
		}
	}
		fout<<"No\n";
		return;
}

int main( ){
	int T,t;
	fin >> T;
	REP(t,T){
		fout<<"Case #"<<t+1<<": ";
		solve();
	}
	fin.close();
	fout.close();
	return 0;
}