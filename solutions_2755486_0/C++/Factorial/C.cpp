#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
#include <math.h>
#include <utility>
#include <iterator>
#include <fstream>
#include <cstdio>

using namespace std;

template<class T>
string tostring(T a){stringstream ss; ss<<a; return ss.str();}

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> II;
#define SZ(a) int((a).size()) 
#define PB push_back 
#define ALL(c) (c).begin(),(c).end() 
#define FOR(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define LOOP(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define MP(a,b) make_pair((a),(b))
#define LAST(t) (t[SZ(t)-1])


struct att{
	int day;
	int w,e;
	int s;
	att(int day, int w, int e, int s):day(day),w(w),e(e),s(s){}
	bool operator<(const att &o) const {return day<o.day;}
};

int main(){
	ifstream be("C-small-attempt0.in");
	ofstream ki("ki.txt");
	int T;
	be>>T;
	FOR(tt,T){
		int N; be>>N;
		vector<att> atts0;
		FOR(i,N){
			int d,n,w,e,s,dd,dp,ds; be>>d>>n>>w>>e>>s>>dd>>dp>>ds;
			w*=2; e*=2; dp*=2;
			FOR(i,n){
				atts0.push_back(att(d,w,e,s));
				d+=dd;
				w+=dp; e+=dp;
				s+=ds;
			}
		}
		sort(ALL(atts0));

		map<int,vector<att> > atts;
		for(att a:atts0)
			atts[a.day].push_back(a);
		
		const int wmax=1000000;
		VI wall(wmax);
		int c=0;
		const int inf=1000000000;
#define WALL(i) (wall[(i)+wmax/2])
		for(auto ad: atts){
			//int day=ad.first;

			//melyek mentek be
			for(att a: ad.second){
				//int mi=*min_element(wall.begin()+a.w, wall.begin()+a.e);
				int mi=inf;
				for(int i=a.w; i<=a.e; i++)
					mi=min(mi,WALL(i));
				if(mi<a.s)
					c++;
			}

			//ujra lejatszuk oket, es epitunk
			for(att a: ad.second){
				for(int i=a.w; i<=a.e; i++)
					WALL(i)=max(WALL(i), a.s);
			}
		}

		ki<<"Case #"<<tt+1<<": "<<c<<endl;
	}
	

	ki.close();
	return 0;
}