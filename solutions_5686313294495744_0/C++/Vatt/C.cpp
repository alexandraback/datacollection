// spnauT
//
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int _b=(b),i=(a); i<_b; ++i)
#define ROF(i,b,a) for(int _a=(a),i=(b); i>_a; --i)
#define REP(n) for(int _n=(n); --_n>=0;)
#define _1 first
#define _2 second
#define PB(x) push_back(x)
#define SZ(x) int((x).size())
#define MT(x) (x).empty()
#define ALL(x) (x).begin(), (x).end()
#define MSET(m,v) memset(m,v,sizeof(m))
#define MAX_PQ(T) priority_queue <T>
#define MIN_PQ(T) priority_queue <T,vector<T>,greater<T>>
#define IO() {ios_base::sync_with_stdio(0); cin.tie(0);}
#define nl '\n'
#define cint1(a) int a; cin>>a
#define cint2(a,b) int a,b; cin>>a>>b
#define cint3(a,b,c) int a,b,c; cin>>a>>b>>c
#define MP(a,b) make_pair((a),(b))
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI; typedef vector<LL> VL; typedef vector<PII> VP;
template<class A, class B> inline bool mina(A &x, B y) {return(y<x)?(x=y,1):0;}
template<class A, class B> inline bool maxa(A &x, B y) {return(x<y)?(x=y,1):0;}
template<class A, class B> inline A geta(A &x, const B y) {A t=x;x=y;return t;}

#define MAXN (10005)

bool bpGraph[1005][1005];
int N,M;

bool bpm(int u, bool seen[], int matchR[])
{
    // Try every job one by one
    for (int v = 0; v < N; v++)
    {
        // If applicant u is interested in job v and v is
        // not visited
        if (bpGraph[u][v] && !seen[v])
        {
            seen[v] = true; // Mark v as visited
 
            // If job 'v' is not assigned to an applicant OR
            // previously assigned applicant for job v (which is matchR[v]) 
            // has an alternate job available. 
            // Since v is marked as visited in the above line, matchR[v] 
            // in the following recursive call will not get job 'v' again
            if (matchR[v] < 0 || bpm(matchR[v], seen, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
 
// Returns maximum number of matching from M to N
int maxBPM()
{
    // An array to keep track of the applicants assigned to
    // jobs. The value of matchR[i] is the applicant number
    // assigned to job i, the value -1 indicates nobody is
    // assigned.
    int matchR[N];
 
    // Initially all jobs are available
    memset(matchR, -1, sizeof(matchR));
 
    int result = 0; // Count of jobs assigned to applicants
    for (int u = 0; u < M; u++)
    {
        // Mark all jobs as not seen for next applicant.
        bool seen[N];
        memset(seen, 0, sizeof(seen));
 
        // Find if the applicant 'u' can get a job
        if (bpm(u, seen, matchR)) {
			
	/*for(int i=0;i<N;i++) {
		printf("%d %d\n",i,matchR[i]);
	}*/
            result++;
		}
    }
    return result;
}
map<string,int> m[2];
int co[2];
int getVal(int h,string s) {
	if(m[h][s]==0) {
		int res = co[h];
		m[h][s]=co[h]+1;
		co[h]++;
		return res;
	}
	else {
		return m[h][s]-1;
	}
}
int xx;
// Driver program to test above functions
int main()
{
	cint1(t);
	while(t--) {
		xx++;
		cint1(n);
		MSET(bpGraph,0);
		string s1,s2;
		co[0]=0;
		co[1]=0;
		int a[1005],b[1005];
		for(int i=0;i<n;i++) {
			cin >> s1 >> s2;
			a[i]=getVal(0,s1);
			b[i]=getVal(1,s2);
		}
		N = co[1];
		M = co[0];
		for(int i=0;i<n;i++) {
			bpGraph[a[i]][b[i]]=1;
		}
		/*for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				printf("%d ",bpGraph[i][j]);
			}
			printf("\n");
		}
		printf("\n");*/
		printf("Case #%d: %d\n",xx,n-(N+M-maxBPM()));
		m[0].clear();
		m[1].clear();
	}
    return 0;
}
