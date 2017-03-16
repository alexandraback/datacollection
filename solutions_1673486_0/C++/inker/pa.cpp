#include<iostream>
#include<map>
#include<math.h>
#include<vector>
#include<string>
#include<string.h>
#include<queue>
#include<algorithm>
#include<sstream>
#define all(X) (X).begin(),(X).end()
#define mem(X) memset(X,0,sizeof(X))
#define debug_v(v) for(int db=0;db<(v).size();db++)cout<<v[db]<<','<<;cout<<endl;
#define pqpush(pq,x,cmp) (pq).push_back(x);push_heap((pq).begin(),(pq).end(),cmp);
#define pqpop(pq,cmp) pop_heap((pq).begin(),(pq).end(),cmp);(pq).pop_back();
using namespace std;
typedef long long ll;
typedef vector<int>::iterator iv;
typedef map<string,int>::iterator msii;
typedef map<int,int>::iterator miii;
typedef map<int,bool>::iterator mibi;
typedef map<string,bool>::iterator msbi;
typedef map<string,int> msi;
typedef map<int,int> mii;
typedef map<int,bool> mib;
typedef map<string,bool> msb;
typedef vector<int> vi;
typedef vector<string> vs;

double am[100001],ans,pm[100001];
int t,a,b,h1,cc;

int main(){
	freopen("A-small-attempt0 (1).in","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		ans=b+2;
		
		am[0]=1;
		
		for(h1=1;h1<=a;h1++)
		{
			scanf("%lf",&pm[h1]);
			am[h1]=am[h1-1]*pm[h1];
		}
		
		for(h1=0;h1<=a;h1++)
			ans=min(ans,am[h1]*(a-h1+b-h1+1)+(1-am[h1])*(a-h1+b-h1+1+b+1));
		printf("Case #%d: %.6lf\n",++cc,ans);
		
	}
}
