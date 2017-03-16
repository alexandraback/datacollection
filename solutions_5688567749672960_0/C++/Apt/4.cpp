#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 
#include <fstream>
using namespace std;
const double eps=1e-8;
const int maxn=100005;
typedef long long ll;
typedef pair<int,int> pii;
bool vis[1000000+5];
ll d[1000000+5];
ll rev(ll d) {
	ll res=0;
	while(d) {
		res*=10;
		res+=d%10;
		d/=10;
	}
	return res;
}
void bfs() {
	queue<ll> q;
	d[1]=1;
	vis[1]=1;
	q.push(1);
	while(!q.empty()) {
		ll tmp=q.front();q.pop();
		ll res=rev(tmp);
		if(tmp+1<=1000000) {
			if(!vis[tmp+1]) {vis[tmp+1]=1;d[tmp+1]=d[tmp]+1;q.push(tmp+1);}
		}
		if(res<=1000000) {
			if(!vis[res]) {vis[res]=1;d[res]=d[tmp]+1;q.push(res);}
		}
	}
}
int main() {
	ifstream cin("input.in");
	ofstream cout("output.out");
	int t;
	cin>>t;
	int kase=1;
	//m.clear();
	bfs();
	while(t--) {
		ll n;
		cin>>n;
		cout<<"Case #"<<kase++<<": "<<d[n]<<endl;
	}


	return 0;
}
