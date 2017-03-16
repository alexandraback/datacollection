#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define pb push_back
const int MAXN = 9;
string zip[MAXN];
int fly[MAXN][MAXN];

bool valid(vector<int> order){
	stack<int>s;
	forn(i,order.size()){
		if(i==0)s.push(order[i]);
		else{
			int y = order[i];
			bool ok = false;
			while(!s.empty() && ok==false){
				int x = s.top();
				if(fly[x][y]==1){s.push(y); ok=true;}
				else s.pop();
				if(s.empty())return false;
			}
		}
	}
	return true;
}

int main(){
	int t; cin>>t;
	//cout<<t<<endl;
	forn(tc,t){
		
		//printf("Case #%d: ", tc+1);
		int n, m; cin>>n>>m;
		forn(i,n)cin>>zip[i];
		forn(i,n)forn(j,n)fly[i][j]=0;
		forn(i,m){
			int a, b; cin>>a>>b; a--; b--;
			fly[a][b]=1;
			fly[b][a]=1;
		}
		vector <int>order;
		forn(i,n)order.pb(i);
		string res ="z";
		//cout<<res<<endl;
		do{
			string s="";
			forn(i,n)s+=zip[order[i]];
			if(valid(order))res=min(res, s);
			//cout<<res<<endl;
		}while(next_permutation(order.begin(), order.end()));
		cout<<"Case #"<<tc+1<<": "<<res<<endl;
	}
}
