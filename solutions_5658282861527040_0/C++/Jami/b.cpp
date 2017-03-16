#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<cctype>
#include<cstdio>
#include<string>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<iterator>
#include<iostream>
#include<algorithm>

using namespace std;

#pragma comment(linker,"/STACK:16777216")
#pragma warning(disable:4786)

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define myabs(a) ((a)<0?(-(a)):(a))
#define pi acos(-1.0)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define eps 1e-9
#define root 1
#define lft 2*idx
#define rgt 2*idx+1
#define cllft lft,st,mid
#define clrgt rgt,mid+1,ed
#define inf (1<<29)
#define i64 long long
#define MX 1000002

typedef pair<int,int> pii;

int main(){
    freopen("B-small-attempt0.in","r",stdin);
	//freopen("in.in","r",stdin);
	freopen("out.txt","w",stdout);
	int cs,t=1,a,b,k,i,j,res=0;
	cin>>cs;
	while(cs--){
	    cin>>a>>b>>k;
	    res=0;
	    for(i=0;i<a;i++){
	        for(j=0;j<b;j++){
	            if((i&j)<k)res++;
	        }
	    }
	    printf("Case #%d: %d\n",t++,res);
	}
	return 0;
}


