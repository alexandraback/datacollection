#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#include<utility>
#include<numeric>
#include<iterator>
using namespace std;

#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define memo(a,b) memset(a,b,sizeof(a))

#define all(a) a.begin(),a.end()
#define pb push_back
#define mpp(a,b,c) make_pair(make_pair(a,b),c)

#define inf (1<<29)
#define i64 long long
#define pi (2.0*acos(0.0))
#define eps (1e-9)

typedef pair< int , int >  pii;

int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small.ans","w",stdout);
    int t,i,j,n,m,a[105][105],row[105],col[105],cs=1;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(i = 0;i<n;i++){
            row[i] = 0;
            for(j = 0;j<m;j++){
                scanf("%d",&a[i][j]);
                row[i] = max(row[i],a[i][j]);
            }
        }
        for(j = 0;j<m;j++){
            col[j] = 0;
            for(i = 0;i<n;i++){
                col[j] = max(col[j],a[i][j]);
            }
        }
        for(i = 0;i<n;i++){
            for(j = 0;j<m;j++){
                if(row[i]>a[i][j] && col[j]>a[i][j])
                    break;
            }
            if(j < m)
                break;
        }
        printf("Case #%d: ",cs++);
        if(i<n)
            printf("NO\n");
        else printf("YES\n");
    }
	return 0;
}
