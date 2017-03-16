#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

typedef long long ll;

ll MOD = 1e9+7;

ll Gcd(ll a,ll b){
	ll r;
	while(1) {
		r=b%a;if(r==0) return a;
		b=a;a=r;
	}
}

ll Pow(ll a ,int b ,int Mo){
    ll ans = 1;
    for (; b; b >>= 1, a = a * a % Mo)
        if (b&1) ans = ans * a % Mo;
    return ans;
}

int dfs(std::vector<int> &edge,std::vector<int> &v,int node,int start,int &open) {
	if(node == start)
		return 0;
	if(v[node])
		return -10000;//explored
	v[node] = 1;
	int t =  1+dfs(edge,v,edge[node],start,open);
//cout<<"N"<<node<<' '<<t<<';';
	
	if(t == -10000+1) {
		//cout<<">"<<start<<" : "<<node<<endl;
		if(node == edge[edge[node]])
			{
				//cout<<'>'<<node<<endl;
				open = node;
				return 1;
			}

	}
	return t;

}
int dfsLongest	(std::vector<std::vector<int> > &edge,std::vector<int> &v,int node,int exc) {

	if(v[node] || node==exc)
		return -10000;
	v[node] = 1;
	int MAX = 0;
	for (int i = 0; i < edge[node].size(); ++i)
	{
		MAX = max(MAX,dfsLongest(edge,v,edge[node][i],exc));
	}
	return 1+MAX;
}

long solve() {
	int N;
	cin>>N;
	std::vector<int> edge(N+1);
	for (int i = 0; i < N; ++i)
	{
		cin>>edge[i+1];
	}
	for (int i = 0; i < N; ++i)
	{
	//	cout<<i+1<< " > "<<edge[i+1]<<endl;
	}
	std::map<pair<int,int>,int > soluOpen;

	int MAX = 0;
	for (int s = 1; s <= N; ++s)
	{
	//	cout<<"STARTING " <<s<<' '<<edge[s]<<";";
		std::vector<int> v(N+1,0);
		v[s] = 1;
		int open=-1;
		int ans = 1+dfs(edge,v,edge[s],s,open);
		//cout<<ans<<" ";
		MAX = max(MAX,ans);

		if(open!=-1) {
			int a =open;
			int b = edge[open];
			if(a>b)
				swap(a,b);

			pair<int,int> end = make_pair(a,b);
			soluOpen[end] = max(soluOpen[end],ans);
			//cout<<"PAIR "<<s<<": "<<a<<','<<b<<" : "<<ans<<endl;

		}
	}
	int SUM = 0;
	std::vector<std::vector<int> > inv(N+1);
	for (int i = 1; i <=N; ++i)
	{
		inv[edge[i]].push_back(i);
	}

	while(soluOpen.size()>0) {
		int largest = 0;
		pair<int,int> lindex = make_pair(-1,-1);
		for (std::map<pair<int,int>,int>::iterator it = soluOpen.begin(); it != soluOpen.end(); ++it)
		{
			//a,b pair unquie
			int a=it->first.first;
			int b=it->first.second;
			int longestPathTilla = 0;
			
			for (int i = 1; i <=N; ++i)
			{
				if(i==a || i==b)
					continue;

				std::vector<int> v(N+1,0);
				int t =  dfsLongest(inv,v,a,b);
				
				
				longestPathTilla = max(longestPathTilla,t);
			}
			int longestPathTillb = 0;
			
			for (int i = 1; i <=N; ++i)
			{
				if(i==a || i==b)
					continue;

				std::vector<int> v(N+1,0);
				int t =  dfsLongest(inv,v,b,a);
				
				
				longestPathTillb = max(longestPathTillb,t);
			}
			
			//cout<<"\nLPTA "<<a<<' '<<longestPathTilla<<endl;
			//cout<<"LPTB "<<b<<' '<<longestPathTillb<<endl;

			if(largest<longestPathTilla+longestPathTillb)
			 {
			  	largest = longestPathTilla+longestPathTillb;
			 	lindex = make_pair(a,b);
			 }
			
		}
		if(largest==0)
		{
			cerr<<"ERRRRRROR\n";
			exit(-1);
		} else {
			SUM+=largest;
			soluOpen.erase(lindex);
		}
	
	}
	//cout<<"MAX "<<MAX<<" SUM "<<SUM<<endl;
	cout<<max(MAX,SUM);
	
}

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	
	
	int T;
	cin>>T;
	for (int i = 0; i < T; ++i)
	{
			cout<<"Case #"<<i+1<<": ";
			solve();
			cout<<endl;
	}
	

	return 0;
}

