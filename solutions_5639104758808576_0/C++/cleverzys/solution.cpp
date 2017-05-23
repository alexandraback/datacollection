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
#define SMALL
//#define LARGE
/////////////////////////////////////////////////////
#define INF 100000000
typedef pair<int,int> PII;
#define MP make_pair
#define MAX_N 1000002
////////////////////////////////////////////////////////
void Solve();
void Per(int pos,int n);
string S(string a);
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
	int S;
	cin>>S;
	string seat;
	cin>>seat;
	int numpeople=0;
	int ans=0;
	for(int i=0;i<=S;i++){
		int t=seat[i]-'0';
		if(t==0) continue;
		if(i<=numpeople){
			numpeople+=t;
		}
		else{
			ans+=(i-numpeople);
			numpeople+=(i-numpeople)+t;
		}
	}
	cout<<ans<<endl;
}