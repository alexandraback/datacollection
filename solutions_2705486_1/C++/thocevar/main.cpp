#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cctype>
#include <climits>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

#define all(c) (c).begin(),(c).end()
#define present(c,x) (find(c.begin(),c.end(),x) != (c).end())
#define pb push_back
#define mp make_pair
#define INIT(v,x) memset(v,x,sizeof(v))
#define REP(i,n) for (int i=0;i<(int)(n);i++)
#define traverse(v,it) for (typeof(v.begin()) it=v.begin();it!=v.end();it++)

typedef pair<int,int> PII;
typedef long long int64;

int tests;
vector<string> dict;

#define T 1200000
int t[T][30];
vector<int> next[T];
vector<int> out[30];
vector<int> prev[30];
int final[T];
int nt=0;

void add(string &s, int i=0, int x=0) {
	if (i==s.size()) {
		final[x]=1;
		return;
	}
	int c=s[i]-'a';
	if (t[x][c]==-1) {
		nt++;
		t[x][c]=nt;
		next[x].push_back(c);
		out[c].push_back(x);
		prev[c].push_back(nt);
	}
	add(s,i+1,t[x][c]);
}

#define INF 0xfefefefe
#define N 4000

int sol[100];

#include <omp.h>

char in[100][N+5];

int main() {
	fstream fin("garbled_email_dictionary.txt");
	INIT(t,-1);
	INIT(final,0);
	string w;
	while (fin >> w) add(w);
	for (int c=0;c<='z'-'a';c++) prev[c].push_back(0);

	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
    scanf("%d",&tests);
    REP (test,tests) {
    	scanf("%s",in[test]);
    }
    #pragma omp parallel for
	REP (test,tests) {
		int thr = omp_get_thread_num();
		fprintf(stderr,"%d %d\n",test,thr);
		//cerr << test << " " << thr << " " << all << endl;
		char *s = in[test];
		unsigned int f[2][6][T];
		int n=strlen(s);
		for (int g=1;g<=5;g++) {
			f[n&1][g][0]=0;
			for (int j=1;j<=nt;j++) f[n&1][g][j]=INF;
		}
		for (int i=n-1;i>=0;i--) {
			for (int g=1;g<=4;g++) { // must match
				memset(f[i&1][g],0xfe,sizeof(f[i&1][g]));
				for (int ti=0;ti<out[s[i]-'a'].size();ti++) {
					int j=out[s[i]-'a'][ti];
					int j2=t[j][s[i]-'a'];
					f[i&1][g][j]=min(f[i&1][g][j], f[(i+1)&1][g+1][j2]);
					if (final[j2]) f[i&1][g][j]=min(f[i&1][g][j], f[(i+1)&1][g+1][0]);
				}
			}
			memset(f[i&1][5],0xfe,sizeof(f[i&1][5]));
			char pc;
			if (i==0) pc=0; else pc=s[i-1]-'a';
			for (int ti=0;ti<prev[pc].size();ti++) {
				int j=prev[pc][ti];
				for (int ci=0;ci<next[j].size();ci++) {
					int c=next[j][ci];
					int j2=t[j][c];
					if (c==s[i]-'a') {
						f[i&1][5][j]=min(f[i&1][5][j], f[(i+1)&1][5][j2]);
						if (final[j2]) f[i&1][5][j]=min(f[i&1][5][j], f[(i+1)&1][5][0]);
					} else {
						f[i&1][5][j]=min(f[i&1][5][j], 1+f[(i+1)&1][1][j2]);
						if (final[j2]) f[i&1][5][j]=min(f[i&1][5][j], 1+f[(i+1)&1][1][0]);
					}
				}
			}
		}
		sol[test]=f[0][5][0];
	}
	REP (test,tests) {
		printf("Case #%d: %d\n", test+1,sol[test]);
	}
    return 0;
}
