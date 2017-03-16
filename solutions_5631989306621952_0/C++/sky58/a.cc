#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
bool sumi[1919];
int main()
{
	int t;string s;
	//char c='A';c--;cout<<c<<endl;
	cin>>t;
	rep(i,t){
		cin>>s;
		int n=s.size(),ma=n;string ret="";
		memset(sumi,false,sizeof(sumi));
		while(1){
			int x=ma;
			rep(j,ma){
				if(x==ma || s[j]>=s[x]) x=j;
			}
			//cout<<x<<endl;
			if(x==ma) break;
			sumi[x]=true;ret+=s[x];
			ma=x;
		}
		rep(j,n){
			if(!sumi[j]) ret+=s[j];
		}
		printf("Case #%d: ",i+1);
		cout<<ret<<endl;
	}
}
