#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define ALL(t) (t).begin(),(t).end()
#define sc second
#define INF ((int)5e8)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
char c[250];
string s;
int main(){
	c['a']='y';
	c['b']='h';
	c['c']='e';
	c['d']='s';
	c['e']='o';
	c['f']='c';
	c['g']='v';
	c['h']='x';
	c['i']='d';
	c['j']='u';
	c['k']='i';
	c['l']='g';
	c['m']='l';
	c['n']='b';
	c['o']='k';
	c['p']='r';
	c['q']='z';
	c['r']='t';
	c['s']='n';
	c['t']='w';
	c['u']='j';
	c['v']='p';
	c['w']='f';
	c['x']='m';
	c['y']='a';
	c['z']='q';

	int t;scanf("%d",&t);getchar();
	REP(setn,t){
		getline(cin,s);
		REP(i,s.size()) if(s[i]>='a' && s[i]<='z') s[i]=c[s[i]];
		printf("Case #%d: %s\n",setn+1,s.c_str());
	}
	return 0;
}



