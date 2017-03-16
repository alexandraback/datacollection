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
#include<iterator>
using namespace std;

#pragma comment(linker,"/STACK:16777216")
#pragma warning(disable:4786)

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define myabs(a) ((a)<0?(-(a)):(a))
#define pi acos(-1.0)
#define inf (1<<29)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define eps 1e-9
#define i64 __int64
#define MX 32

typedef pair<int,int> pii;

int a[MX];
map<int,int> mp;

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	int n,i,cs,s,j,flag,x,y,t=1;
	cin>>cs;
	while(cs--){
		cin>>n;
		for(i=0;i<n;i++){
			cin>>a[i];
		}
		mp.clear();
		flag=0;
		for(i=1;i<(1<<n);i++){
			s=0;
			for(j=0;j<n;j++){
				if(i&(1<<j)){
					s+=a[j];
				}
			}
			if(mp.find(s)!=mp.end()){
				flag=1;
				x=mp[s];
				y=i;
				break;
			}
			else mp[s]=i;
		}
		if(flag){
			printf("Case #%d:\n",t++);
			flag=0;
			for(i=0;i<n;i++){
				if(x&(1<<i)){
					if(flag)cout<<" ";
					flag=1;
					cout<<a[i];
				}
			}
			cout<<endl;
			flag=0;
			for(i=0;i<n;i++){
				if(y&(1<<i)){
					if(flag)cout<<" ";
					flag=1;
					cout<<a[i];
				}
			}
			cout<<endl;
		}
		else{
			printf("Case #%d:\nImpossible\n",t++);
		}
	}
	return 0;
}


