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
int fraction[1002];
int maxcake[1002];
void main() 
{
#ifdef TRY
	freopen("1.txt", "rt", stdin);
	//freopen("2.out","wt",stdout);
#endif
#ifdef SMALL
	freopen("B-small-attempt0.in","rt",stdin);
	freopen("B-small.txt","wt",stdout);
#endif
#ifdef LARGE
	freopen("B-large.in","rt",stdin);
	freopen("B-large.txt","wt",stdout);
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
	int D;cin>>D;
	int tem;
	vector<int> P;
	for(int i=0;i<D;i++){
		cin>>tem;
		P.push_back(tem);
	}
	sort(P.begin(),P.end());
	int ans=1000;
	int sum=0;
	int div=0;
	for(int i=1;i<=1000;i++){
		sum=0;
		for(int j=0;j<D;j++){
			if(P[j]<=i) continue;
			div=P[j]/i - 1;
			if(P[j]%i != 0) div++;
			sum+=div;
		}		
		ans=min(ans,sum+i);
	}
	cout<<ans<<endl;
}