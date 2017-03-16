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

#define maxn 100
using namespace std;
typedef long long ll;

int arr[maxn][maxn],a2[maxn][maxn],hmax[maxn],wmax[maxn];
int main(){
	int t,h,w;
	cin>>t;
	FOR(tt,t){
		cin>>h>>w;
		memset(hmax,-1,sizeof hmax);
		memset(wmax,-1,sizeof wmax);		
		FOR(i,h) 
			FOR(j,w){
				cin>>arr[i][j];
				a2[i][j]=150;
				hmax[i]=max(hmax[i],arr[i][j]);
				wmax[j]=max(wmax[j],arr[i][j]);
			}
		bool ok=true;
		FOR(i,h){
			FOR(j,w){
				if(hmax[i] == arr[i][j])
					FOR(k,w) a2[i][k]=min(a2[i][k],arr[i][j]); 
				if(wmax[j] == arr[i][j])
					FOR(k,h) a2[k][j]=min(a2[k][j],arr[i][j]);
			}
		}
		
		FOR(i,h)
			FOR(j,w)
				ok=(ok && (arr[i][j] == a2[i][j]));
						
		cout<<"Case #"<<tt + 1<<": "<<(ok ? "YES" : "NO")<<"\n";
	}
	return 0;
}
