#include<iostream>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<numeric>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define fr(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pi;
const int inf=(int)1e9;
const double INF=1e12,EPS=1e-9;

const char *m="yhesocvxduiglbkrztnwjpfmaq";

int main()
{
	int CS; cin>>CS; cin.ignore();
	rep(cs,CS)
	{
		string in, in2;
		getline(cin, in);
		cout<<"Case #"<<cs+1<<": ";
		rep(i,in.size()) cout << (in[i] == ' ' ? ' ' : m[in[i] - 'a']);
		cout << endl;
	}
	return 0;
}
