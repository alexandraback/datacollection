#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <queue>
using namespace std;
#define   sqr(a)         ((a)*(a))
#define   rep(i,a,b)  for(int i=(a);i<(int)(b);i++)
#define   per(i,a,b)  for(int i=((a)-1);i>=(int)(b);i--)
#define   PER(i,n)     per(i,n,0)
#define   REP(i,n)     rep(i,0,n)
#define   FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define   clr(a)      memset((a),0,sizeof (a))
#define   SZ(a)         ((int)((a).size()))
#define   CLEAR(a, v)    memset((a), (v), sizeof(a))
#define   ALL(v)          (v).begin(), (v).end()
#define   mabs(a)       ((a)>0?(a):(-(a)))
#define   inf         1000000001
#define  MAXN     110
#define  eps      1e-6
#define   PB push_back
#define   FI 		first
#define   SE 		second
#define   MP 		make_pair
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
typedef long long int64;
int sum,a[123],n;
FILE *fin;
FILE *fout;
int main()
{
	int T;
	fin=fopen("A-small-attempt0.in","r");
	fout=fopen("output.txt","w");
	fscanf(fin,"%d",&T);
	REP(t,T){
		fscanf(fin,"%d%d",&sum,&n);
		REP(i,n)fscanf(fin,"%d",a+i);
		if (sum==1){
			printf("Case #%d: %d\n",t+1,n);
			fprintf(fout,"Case #%d: %d\n",t+1,n);
			continue;
		}
		sort(a,a+n);
		int ans=n,add=0,i=0;
		while (i<n){
			if (a[i]<sum) {
				ans=min(ans,add+n-i-1);sum+=a[i];i++;
			}
			else {
				ans=min(ans,add+n-i);add++;sum+=sum-1;
			}
		}
		printf("Case #%d: %d\n",t+1,ans);
		fprintf(fout,"Case #%d: %d\n",t+1,ans);
	}
	return 0;
}
