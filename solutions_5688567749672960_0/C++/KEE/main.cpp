/**/
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define For(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define all(v) v.begin(),v.end()
#define V vector
typedef long long ll;
/***********************************************/
/* Dear MinGW compiler:
 * I've wasted time reading the problem and trying to figure out the solution
 * If there's any syntax error and you've any suggestion, please fix it yourself.
 * I hope my code compile and get accepted. KEE O.o
 *      ____________
 *     /         __ \
 *    /   __    |  | \
 *   /   |__|   |  |  \
 *  (           |__|   )
 *   \                /
 *    \      ___     /
 *     \____________/
 */
const ll mod = 1000000007;
int rev(int x){
	int res = 0;
	while(x){
		res*=10;
		res+=x%10;
		x/=10;
	}
	return res;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("A-small-attempt0.in","r",stdin);
	freopen("myfile.txt","w",stdout);
	queue<pair<int,int> > bfs;
	bfs.push({1,1});
	V<int> res (1000010,-1);
	while(!bfs.empty()){
		auto u = bfs.front();
		bfs.pop();
		res[u.first] = u.second;
		if(res[u.first+1] == -1){
			res[u.first+1] = u.second+1;
			bfs.push({u.first+1,u.second+1});
		}
		int y = rev(u.first);
		if(y <= 0 || y+1 >= (int)res.size())
			continue;
		if(res[y]==-1){
			res[y] = u.second+1;
			bfs.push({y,u.second+1});
		}
	}
	int t,n,c=1;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<"Case #"<<c++<<": "<<res[n]<<endl;
	}
	return 0;
}
/**/
