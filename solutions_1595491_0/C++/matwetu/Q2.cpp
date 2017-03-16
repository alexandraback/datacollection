/*Q2.cpp @ 2012年04月14日 08时26分19秒 BY dOMhOW*/
/* 
 * status : AC  WA  TLE
 */
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<math.h>
#include	<map>
#include	<algorithm>
#include	<vector>
#include	<set>
#include	<iostream>
#include	<string>
using namespace std;
#define CC(x,i) do{memset(x,i,sizeof(x));}while(0)
#define inf 0x7f7f7f7f
#define PII pair<int,int>
#define VI vector<int>
#define mp make_pair
#define X first
#define Y second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(),x.end()
#define uniq(x) do{sort(all(x));x.resize(unique(all(x))-x.begin());}while(0)
#define two(x) (1ll<<(x))
typedef long long  LL;
int T;
int main ( int argc, char *argv[] )
{
	cin>>T;
	for(int i=1;i<=T;i++){
		int n,s,p,tot;
		scanf("%d%d%d",&n,&s,&p);
		tot=0;
		cout<<"Case #"<<i<<": ";
		for(int j=0;j<n;j++)
		{
			int a;scanf("%d",&a);
			if(p+p+p-2<=a){
				tot++;
			}
			else if(s&&p>1&&p+p-2+p-2<=a){
				s--;
				tot++;
			}
		}
		if(p==0){cout<<n<<endl;}
		else cout<<tot<<endl;
	}
	return EXIT_SUCCESS;
}

