/*a.cpp @ 2012年04月28日 09时10分53秒 BY dOMhOW*/
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
int n,used[1024],pot[1024];
vector<PII> div2;
vector<pair<int,PII>  > div1;
int main ( int argc, char *argv[] )
{
	int T;cin>>T;
	for(int t=1;t<=T;t++){
		cin>>n;
		div2.clear();div1.clear();
		CC(used,0);
		for(int i=0;i<n;i++){
			PII tmp;pair<int,PII> tmp1;
			cin>>tmp1.X;
			cin>>tmp.X;tmp.Y=i;
			div2.pb(tmp);
			tmp1.Y=tmp;
			tmp1.Y.X*=-1;
			div1.pb(tmp1);
			pot[i]=tmp1.X;
		}
		sort(all(div1));
		sort(all(div2));
		int pt=0,ans=0;
		for(int i=0;i<(int)div2.size();i++){
			if(div2[i].X>pt){
				if(!used[div2[i].Y]&&pot[div2[i].Y]<=pt){
					pt++;used[div2[i].Y]=1;ans++;
				}
				vector<PII> ttt;
				for(int j=i+1;j<(int)div2.size();j++)
					if(!used[div2[j].Y])ttt.pb(mp(pot[div2[j].Y],div2[j].Y));
				sort(all(ttt));
				for(int j=0;pt<div2[i].X&&j<(int)ttt.size();j++){
					if(!used[div2[i].Y]&&pot[div2[i].Y]<=pt){
						pt++;used[div2[i].Y]=1;ans++;
						if(pt>=div2[i].X)break;
					}
					if(pt>=ttt[j].X){
						used[ttt[j].Y]=1;
						ans++;
						pt++;
					}
					else break;
				}
			}
			if(div2[i].X<=pt)
			{
				if(used[div2[i].Y])pt++;
				else pt+=2;
			}
			else {
				ans=-1;
				break;
			}
		}
		cout<<"Case #"<<t<<": ";
		if(ans<0){
			cout<<"Too Bad\n";
		}
		else cout<<ans+div2.size()<<endl;
	}
	return EXIT_SUCCESS;
}

