#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

#define in(x,y) ( (x)>=0 && (y)>=0 && (x)<n && (y)<m )
#define MOD 1000000007
#define INF 2147483647
#define PI 3.1415926535897932384626433832795
#define all(cont) cont.begin(),cont.end()
#define init(a,val) memset(a,val,sizeof(a))
#define F first
#define S second
#define mp make_pair
#define MAX 120


int main()
{
	freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	
	int seen[2600];
	int i,j,k,n;

//_______________________________________________
	int test_cases,tesT;

	cin>>test_cases;
	for(tesT=0;tesT<test_cases;tesT++){
		cout<<"Case #"<<tesT+1<<": ";
//_______________________________________________
		init(seen,0);
		cin>>n;
		for(i=0;i<2*n-1;i++)for(j=0;j<n;j++){
			cin>>k;
			seen[k]++;
		}
		for(i=1;i<=2500;i++)if(seen[i]){
			if(seen[i]&1)cout<<i<<' ';
		}

//_______________________________________________
		done:
		cout<<endl;
	}

	cerr<<endl;
	return 0;
}