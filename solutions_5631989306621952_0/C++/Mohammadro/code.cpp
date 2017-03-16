#include<iostream>
#include<cstdio>
#include<sstream>
#include<fstream>
#include<cctype>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<string>
#include<complex>
#include<bitset>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<iomanip>
#include<utility>

#define pb push_back
#define pp pop_back
#define xx first
#define yy second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

string s;
vector<int> ans;
bool mark[2000];

int get(int last){
	int ret=0;
	for(int i=1;i<last;i++){
		if(s[i]>=s[ret]){
			ret=i;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int l=1;l<=t;l++){
		cin>>s;
		ans.clear();
		memset(mark,0,sizeof(mark));
		int last=s.size();
		while(true){
			int cur=get(last);
			ans.pb(cur);
			last=cur;
			if(cur==0)break;
		}
		cout<<"Case #"<<l<<": ";
		for(int i=0;i<ans.size();i++){
			cout<<s[ans[i]];
			mark[ans[i]]=true;
		}
		for(int i=0;i<s.size();i++){
			if(!mark[i])cout<<s[i];
		}
		cout<<endl;
	}
	return 0;
}
