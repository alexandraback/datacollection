#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <limits>
#include <queue>
#include <stdexcept>
#include <iomanip> 
#include <sstream>
using namespace std;

////////////////////////////////////////////////////
#define TRY
//#define SMALL
#define LARGE
/////////////////////////////////////////////////////
#define INF 100000000
typedef pair<int,int> PII;
#define MP make_pair
#define MAX_N 1000002
////////////////////////////////////////////////////////
void Solve();
int dfs(int C,int W);

void main() 
{
#ifdef TRY
	freopen("1.txt", "rt", stdin);
	//freopen("2.out","wt",stdout);
#endif
#ifdef SMALL
	freopen("A-small-attempt0.in","rt",stdin);
	freopen("A-small.txt","wt",stdout);
#endif
#ifdef LARGE
	freopen("A-large.in","rt",stdin);
	freopen("A-large.txt","wt",stdout);
#endif

	int Numcase;
	cin>>Numcase;

	for(int test=1;test<=Numcase;test++)
	{
		cout<<"Case #"<<test<<": ";
		//cout<<"Case #"<<test<<":"<<endl;
		Solve();
	}
}
void Solve(){
	int  R,C,W;
	cin>>R>>C>>W;
	if(R==1){
		cout<<dfs(C,W)<<endl;
	}
	else{
		int p=C/W;
		cout<<p*(R-1)+dfs(C,W)<<endl;
	}
}
int dfs(int C,int W){
	if(W==1) return C;
	if(C==W) return W;
	if(2*W>C){
		return W+1;
	}else{
		return 1+dfs(C-W,W);
	}
}