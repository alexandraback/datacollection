#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<ctime>
#include<climits>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<complex>
#include<set>
#include<bitset>
#include<utility>
#include<valarray>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<pair<int,int> > vpii;

#define pb push_back
#define mp make_pair
#define PI acos(-1)
#define all(a) (a).begin(),(a).end()
#define len(a) ((int)(a).size())
#define mem(a,n) memset(a,n,sizeof(a))
#define eps 1e-9
#define rep(i,n) for(int i=0;i<(n);i++)
#define repi(i,a,n) for(int i=(a);i<(n);i++)
#define repr(i,a,n) for(int i=(n);i>=(a);i--)

vs v(4);
bool chk(char ch){
	rep(i,len(v)){
		int cc=0,cc2=0;
		rep(j,len(v)){
			if(v[i][j]==ch || v[i][j]=='T')cc++;
			if(v[j][i]==ch || v[j][i]=='T')cc2++;
		}
		if(cc==4 || cc2==4)return true;
	}
	int cc=0,cc2=0;
	rep(i,len(v)){
		if(v[i][i]==ch || v[i][i]=='T')cc++;
		if(v[i][3-i]==ch || v[i][3-i]=='T')cc2++;
	}
	if(cc==4 || cc2==4)return true;
	return false;
}


int main(void){
	ios_base::sync_with_stdio(0);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int t;
	cin>>t;
	rep(k,t){
		rep(i,len(v))cin>>v[i];
		cout<<"Case #"<<k+1<<": ";
		if(chk('O'))cout<<"O won"<<endl;
		else if(chk('X'))cout<<"X won"<<endl;
		else{
			int cc=0;
			rep(i,len(v))rep(j,len(v))cc+=(v[i][j]=='.');
			if(cc)cout<<"Game has not completed"<<endl;
			else cout<<"Draw"<<endl;
		}
	}
	return 0;
}
