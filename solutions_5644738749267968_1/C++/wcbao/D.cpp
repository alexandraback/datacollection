#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define mm 2005
#define clr(A) memset(A,0,sizeof(A))
using namespace std;
typedef long long LL;
typedef pair<double,int> P;
vector<P> by;
double a[mm],b[mm];
int p[mm];
int hash[mm];

int main()
{
//	freopen("BUAA.in","r",stdin);
//	freopen("D.out","w",stdout);
	int T,c = 0;
	scanf("%d",&T);
	while(T--){
//	    printf("Case #%d:\n",++c);
	    by.resize(0);
	    int n;
	    scanf("%d",&n);
	    for(int i = 0; i < n;i++)
	    {
	        scanf("%lf",&a[i]);
	        by.push_back(P(a[i],i));
	    }
	    for(int i = 0; i < n;i++)
	    {
	        scanf("%lf",&b[i]);
	        by.push_back(P(b[i],i+n));
	    }
	    sort(by.begin(),by.end());
	    for(int i = 0;i<by.size();i++)
	    p[by[i].second] = i;
	    sort(p,p+n);
	    sort(p+n,p+n+n);
	    clr(hash);
	    int ans2 = n;
	    for(int i = n+n-1;i>=n;i--){
             int pos = -1;
             for(int j = n-1;j>=0;j--)
             if(!hash[p[j]]&&p[j]<p[i]) {pos = j;break;}
             if(pos == -1) break;
             hash[p[pos]] = hash[p[i]] = 1;
             ans2--;
             }
        int ans1 = 0;
        int j = 0;
        for(int i = n;i<n+n;i++){
            while(p[j]<p[i]&&j<n) j++;
            if(j>=n) break;
            ans1++;
            j++;
        }
        printf("Case #%d: %d %d\n",++c,ans1,ans2);
	}
	return 0;
}

