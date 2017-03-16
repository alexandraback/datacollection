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

double na[maxn],ka[maxn];
int main(){
	int t,n;
	cin>>t;
	FORR(tt,1,t + 1){
		cout<<"Case #"<<tt<<": ";
		cin>>n;
		
		FOR(i,n) cin>>na[i];
		FOR(i,n) cin>>ka[i];
		sort(na,na + n);
		sort(ka,ka + n);
		
		int a1 = 0,a2 = 0,l = 0,r = n - 1;
		FOR(i,n){
			if(na[i] > ka[l]){ a1++; l++; }
			else if(na[i] < ka[r]){ r--; }
		}
		l = 0;
		r = 0;
		
		FOR(i,n){
			while(r < n && ka[r] < na[l]) r++;
			if(r >= n) a2++;
			l++; r++;
		}
		cout<<a1<<" "<<a2<<"\n";
	}
	return 0;
}
