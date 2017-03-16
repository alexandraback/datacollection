#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstring>
#include <climits>

#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <forward_list>

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <cmath>

#include <utility>

using namespace std;

#define FOR(i,n1,n2) for(int i = n1; i < n2; ++i)
#define FORD(i,n1,n2) for(int i = n1; i >= n2; --i)
#define FORE(e,c) for(auto& e : c)
#define SZ(i) (int) i.size()
#define PB push_back
#define MT make_tuple
#define g(c,i) get<i>(c)

vector<long long> a,b,A,B;
map<tuple<int,int,long long,long long>, long long> m;
//long long d[5][200];
/*
long long solve(int sa, int sb) {
    tuple<int,int,long long,long long> t = MT(sa,sb,a[sa],b[sb]);
    if (m.count(t)) return m[t];
    long long r=0;
    if (sa==SZ(a) || sb==SZ(b)) {
        return 0;
    }
    if (A[sa]==B[sb]) {
        r=min(a[sa],b[sb]);
        if (a[sa]<b[sb]) {
            b[sb]-=r;
            r+=solve(sa+1,sb);
            b[sb]+=a[sa];
        } else if (a[sa]>b[sb]){
            a[sa]-=r;
            r+=solve(sa,sb+1);
            a[sa]+=b[sb];
        } else {
            r+=solve(sa+1,sb+1);
        }
    }
    long long res=r;
    long long r2=solve(sa+1,sb);
    if (r2>res) res=r2;
    r2=solve(sa,sb+1);
    if (r2>res) res=r2;
    return m[t]=res;
}
*/

long long solve(int p, int p2) {
    if (p==SZ(a)) return 0;
    long long res=0;//solve(p+1,p2);

    long long r=0,r2=0,m;
    long long ap=a[p];
    FOR(i,p2,SZ(b)+1) {
        long long r=0;
        long long aa=a[p];
        FOR(j,p2,i) {
            if (A[p]==B[j] && aa>0) {
                long long q=aa<b[j] ? aa : b[j];//min(aa,b[j]);
                r+=q;
                aa-=q;
                long long oldaa=aa+q;
                if (b[j]>oldaa) {
                    b[j]-=oldaa;
                    res=max(res,r+solve(p+1,j));
                    b[j]+=oldaa;
                }
            }
        }
        //cout << r << " " << p << " " << i << endl;
        long long w=r+solve(p+1,i);
        res=w>res ? w : res;
    }

    /*
    long long aa=a[p];
    FOR(i,p2,SZ(b)) {
        cout << r << " " << p << " " << p2 << endl;
        r2=r+solve(p+1,i);
        res=max(res,r2);
        if (a[p]<=0) break;

        if (A[p]==B[i]) {
            r+=min(a[p],b[i]);
            a[p]-=b[i];
        }
        if (b[i]>a[p]) {
            b[i]-=a[p];
            cout << r << " " << p << " " << p2 << " " << b[i] << endl;
            r2=r+solve(p+1,i);
            res=max(res,r2);
        }
    }
    a[p]=aa;
    FOR(i,p2,SZ(b)) {
        if (A[p]==B[i]) {
            r+=min(a[p],b[i]);
            a[p]-= m = min(a[p],b[i]);
            b[i]-=m;

            if (a[p]==0) {
                if (b[i]>a[p]) {
                    r2=r+solve(p+1,i);
                } else {
                    r2=r+solve(p+1,i+1);
                }
            } else {
                r2=r+solve(p+1,p2);
            }

            b[i]+=m;
            a[p]+=m;
            res=max(res,r2);
        }
    }*/
    return res;
}

int main() {
    int t;
	scanf("%d\n",&t);
	FOR(tt,1,t+1) {
		cout << "Case #" << tt << ": ";

		int n,m;
		cin >> n >> m;

        a.resize(n);
        A.resize(n);
        b.resize(m);
        B.resize(m);
		FOR(i,0,n) cin >> a[i] >> A[i];
		FOR(i,0,m) cin >> b[i] >> B[i];
		//FOR(i,0,5) FOR(j,0,200) d[i][j]=-1;
		long long res=solve(0, 0);

		cout << res << endl;
	}
    return 0;
}

