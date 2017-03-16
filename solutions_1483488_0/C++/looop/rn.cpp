#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz size()
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define rep2(i,n,m) for(int i=n;i<(int)(m);i++)
#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define dot(a,b) ((conj(a)*(b)).X)
#define X real()
#define Y imag()
#define length(V) (hypot((V).X,(V).Y))
#define vect(a,b) ((b)-(a))
#define cross(a,b) ((conj(a)*(b)).imag())
#define normalize(v) ((v)/length(v))
#define rotate(p,about,theta) ((p-about)*exp(point(0,theta))+about)
#define pointEqu(a,b) (comp(a.X,b.X)==0 && comp(a.Y,b.Y)==0)

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;

#define SMALL
//#define LARGE

int len(int a){
	int i = 0;
	do{
		i++;
		a = a/10;
	}while(a!=0);
	return i;
}
int recycle(int a, int length, int n){
	int c = 0;
	int b = (int)(pow(10.0,length-n));
	int d = (int)(pow(10.0,n));
	c += a%b*d;
	c += a/b;
	if(len(c)<length || c == a)
		return -1;
	return c;
}
int main(){
	#ifdef SMALL
	freopen("C-small-attempt0.in","rt",stdin);
	freopen("C-small.out","wt",stdout);
	#endif
	#ifdef LARGE
	freopen("C-large.in","rt",stdin);
	freopen("C-large.out","wt",stdout);
	#endif
	int T;
	cin>>T;
	rep(i,T){
		int a,b;
		int num = 0;
		cin>>a;
		cin>>b;
		int length = len(a);
		
		rep2(j,a,b+1){
			vector<int> pairNum;
			
			rep2(k,1,length){
				bool flag = true;
				int re = recycle(j,length,length-k);
				if(re!=-1 && re>j && re <= b){
					rep(nn,pairNum.size())
						if(re==pairNum[nn]){
							flag = false;
							break;
						}
					if(flag){
						num++;
						pairNum.push_back(re);
					}					
				}
			}
		}
		cout<<"Case #"<<i+1<<": "<<num<<endl;
	}


	return 0;
}
