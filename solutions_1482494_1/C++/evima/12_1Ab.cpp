#include <iostream>
#include <fstream>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define EPS 1e-9
#define INF MOD
#define MOD 1000000007LL
#define fir first
#define foreach(it,X) for(it=X.begin();it!=X.end();it++)
#define iss istringstream
#define ite iterator
#define ll long long
#define mp make_pair
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<n;i++)
#define pi pair<int,int>
#define pb push_back
#define sec second
#define sh(i) (1LL<<i)
#define sst stringstream
#define sz size()
#define vi vector<int>
#define vc vector
#define vl vector<ll>
#define vs vector<string>

int N,a[1010],b[1010];

int main(){
	int T;
	cin>>T;
	
	rep(tc,T){
		cout<<"Case #"<<tc+1<<": ";
		cin>>N;
		rep(i,N)cin>>a[i]>>b[i];
		int used[1010][2]={};
		int star=0,ans=0;
		while(star<2*N){
			int next=1001,done=0;
			rep(i,N){
				if(!used[i][1] && star>=b[i]){
					if(!used[i][0])star+=2;
					else star+=1;
					used[i][0]=used[i][1]=1;
					ans++;
					done=1;
					break;
				}
				if(!used[i][0] && star>=a[i] && b[i]>b[next]){
					next=i;
				}
			}
			if(!done){
				if(next==1001)break;
				star+=1;
				used[next][0]=1;
				ans++;
			}
		}
		if(star<2*N)cout<<"Too Bad\n";
		else cout<<ans<<endl;
	}
}
