#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define DEBUGx(x) cerr << #x << " = " << x << endl;
#define DEBUGxyz(x,y,z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;
#define ALL(x) x.begin(),x.end()
#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOREACH(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define PB push_back

typedef vector<int> VI; 
template<class T> inline int size(const T&c) { return c.size(); }
inline int getint() { int x; scanf("%d",&x); return x; }
inline void OPEN(string name) {
	string in = name+".in"; freopen(in.c_str(),"r",stdin);
	string out = name+".out"; freopen(out.c_str(),"w",stdout);
}

// Powered By TimoAI 2.2

VI g[64];
int N,M;
string code[64];

int compare(string &a,string &b) {
	if(size(a) != size(b))
		return size(a) - size(b);
	if(a < b) return -1;
	if(a > b) return +1;
	return 0;
}

int findNext(VI &pos, int &mask) {
	FOREACH(it,pos) if(!(mask & (1<<*it))) return *it;
	return -1;
}


bool recurse(int &index, VI &pos, int &mask) {
	int from = pos[index++];

	if(mask & (1<<from)) return false;
	mask |= (1<<from);

	if(index==N) return true;

	sort(ALL(g[from]));
	int saveIndex = index;
	int saveMask = mask;
	do {
		index = saveIndex;
		mask = saveMask;
		FOREACH(it, g[ from ]) {
			DEBUGx(from+1);
			DEBUGxyz(index,pos[index]+1,*it+1);
			if(pos[index] == (*it) && recurse(index, pos, mask)) {
				return true;
			}
		}
	}while(next_permutation(ALL(g[from])));
	return false;

}

void doit(int from, VI &pos, int &mask) {
	if(mask & (1<<from)) return ;
	mask |= (1<<from);

	FOREACH(it, g[ from ]) {
		int next = findNext(pos,mask);
		//DEBUGxyz(from,*it,next);
		if(*it==next) doit(*it, pos, mask);
	}
}

string solve() {
	VI pos;
	REP(i,N) pos.PB(i);
	string ret="";
	do {
		int mask=0;
		int index=0;

		doit(pos[0],pos,mask);
		if(mask+1 == (1<<N)) {
			string temp="";
			FOREACH(it,pos) temp += code[*it];
			if(ret.length()==0 || compare(temp,ret) < 0) {
				ret = temp;
			}
		}
		//DEBUGx(mask);

	}while(next_permutation(ALL(pos)));
	return ret;
}

int main() {
	OPEN("C");
	REP(nc,getint()) {
		N = getint();
		M = getint();
		REP(i,N) {
			g[i].clear();
			cin>>code[i];
		}
		REP(i,M) {
			int a=getint()-1;
			int b=getint()-1;
			g[a].PB(b);
			g[b].PB(a);
		}



		printf("Case #%d: %s\n",nc+1,solve().c_str());
	}
	return 0;
}
