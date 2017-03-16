#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <climits>
#include <cassert>

#define FOR(i,n) for(int i=0,_n=n;i<_n;i++)
#define FORD(i,n) for(int i=n;i>=0;i--)
#define FORR(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define FORRD(i,n,s) for(int i=n,_s=s;i>=_s;i--)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pli pair<ll,int>
#define vi vector<int>
#define fs first
#define sec second

#define maxn 100000
using namespace std;
typedef long long ll;

bool isv[300];
int main(){
	int t,n;
	ll p;
	string line;
	
	cin>>t;
	isv['a']=isv['e']=isv['i']=isv['o']=isv['u']=true;
	FORR(ttt,1,t + 1){
		ll ans=0;
		cin>>line>>p;
		n=line.length();
		
		ll lleft=-1;
		ll ccnt=0;
		FOR(i,n){
			if(!isv[line[i]]) ccnt++;
			else ccnt=0;
			if(ccnt >= p){
				ans+=((ll)i - p + 2) * (ll)(n - i);
				ans-=(ll)(lleft + 1) * (ll)(n - i);
				lleft=i - p + 1;
			}
		}
		cout<<"Case #"<<ttt<<": "<<ans<<"\n"; 
	}
	return 0;
}
