#include<iostream>
using namespace std;
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<cmath>
#include<set>
#include<ctime>
#include<stack>
#include<list>
#include<cassert>  
typedef pair<int,int> pii;
#define rep(i,j,n) for(i=j;i<n;i++)
#define pb push_back
#define sz(a) a.size()
#define ff first
#define ss second 
#define lli long long int

int a[1000009];
const int maxn = 1000007;

int reverse(int x){
	int ans = 0;
	
	while(x){
		ans = 10*ans + x%10;
		x/=10;
	}
	return ans;
}

int main() {
		
	ios::sync_with_stdio(false);
	
	
	
	//clock_t start = std::clock();
	freopen ("inp.txt","r",stdin);
	freopen ("out.txt","w",stdout);
	//cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
	
	memset(a,-1,sizeof(a));
	
	queue<int> gg;
	gg.push(1);
	a[1] = 1;
	int cur,rev;
	while(!gg.empty()){
		cur = gg. front();
		gg.pop();
		if(cur+1 < maxn){
			if(a[cur+1] == -1){
				a[cur+1] = a[cur]+1;
				gg.push(cur+1);
			}
		}
		
		rev = reverse(cur);
		if(rev < maxn){
			if(a[rev] == -1){
				a[rev] = a[cur]+1;
				gg.push(rev);
			}
		}
		
	}
	
	int n,i,yy;
	cin>>n;
	
	rep(i,0,n){
		cin>>yy;
		cout<<"Case #"<<i+1<<": "<<a[yy]<<endl;
	}
	
	
	return 0;
}

