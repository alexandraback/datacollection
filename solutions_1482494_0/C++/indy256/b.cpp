#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <numeric>
#include <memory.h>
//#include <ctime>
//clock_t startTime=clock();
//fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-startTime));
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef pair<double, double> pdd;
typedef vector<pdd> vpdd;
typedef vector<vpii> Graph;

#define fr(i,a,b) for(int i(a),_b(b);i<=_b;++i)
#define frd(i,a,b) for(int i(a),_b(b);i>=_b;--i)
#define rep(i,n) for(int i(0),_n(n);i<_n;++i)
#define reps(i,a) fr(i,0,sz(a)-1)
#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define clr(x,a) memset(x,a,sizeof(x))
#define findx(a,x) (find(all(a),x)-a.begin())
#define two(X) (1LL<<(X))
#define contain(S,X) (((S)&two(X))!=0)

const int dr[]={0,-1,0,1,-1,1, 1,-1};
const int dc[]={1,0,-1,0, 1,1,-1,-1};
const double eps=1e-9;

template<class T> void print(const vector<T> &v){ostringstream os; for(int i=0; i<(int)v.size(); ++i){if(i)os<<' ';os<<v[i];} cout<<os.str()<<endl;}
template<class T> int sz(const T&c){return (int)c.size();}
template<class T> void srt(T&c){sort(c.begin(),c.end());}
template<class T> void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> T sqr(T x){return x*x;}
template<class T, class U> T cast (U x) { ostringstream os; os<<x; T res; istringstream is(os.str()); is>>res; return res; }
template<class T> vector<T> split(string s, string x=" ") {vector<T> res; for(int i=0;i<s.size();i++){string a; while(i<(int)s.size()&&x.find(s[i])==string::npos)a+=s[i++]; if(!a.empty())res.push_back(cast<T>(a));} return res;}
template<class T> bool inside(T r,T c,T R, T C){return r>=0 && r<R && c>=0 && c<C;}


int main( int argc, char* argv[] ) {
	string path = "B-small-attempt1";
	freopen((path+".in").c_str(),"r",stdin);
	freopen((path+".out").c_str(), "w", stdout);
	
	int testCases;
	cin>>testCases;

	for(int testCase=1;testCase<=testCases;testCase++){
		int n;
		cin>>n;

		vi a(n), b(n);
		rep(i,n)cin>>a[i]>>b[i];

		vb va(n),vb(n);
		int res = 0;
		int s=0;
		while(true){
			int cnt=0;
			rep(j,n)if(vb[j])++cnt;
			if(cnt==n)break;
			++res;
			bool ok=false;
			rep(j,n){
				if(!va[j] && !vb[j] && s>=b[j]){
					ok=true;
					va[j]=true;
					vb[j]=true;
					s+=2;
					break;
				}
			}
			if(ok)continue;
			rep(j,n){
				if(va[j] && !vb[j] && s>=b[j]){
					ok=true;
					va[j]=true;
					vb[j]=true;
					s+=1;
					break;
				}
			}
			if(ok)continue;
			int pos=-1;
			rep(j,n){
				if(!va[j] && !vb[j] && s>=a[j]){
					if(pos==-1 || b[pos] < b[j]) pos = j;
				}
			}
			if(pos>=0){
				va[pos]=true;
				s+=1;
				continue;
			}
			res=-1;
			break;
		}

		if(res==-1)
			cout << "Case #" << testCase << ": " << "Too Bad" << endl;
		else
			cout << "Case #" << testCase << ": " << res << endl;
		cout.flush();
	}

	fclose(stdout);
	return 0;
}
