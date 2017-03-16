//Bismillahir Rahmanir Rahim
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <sstream>

using namespace std;

#define mp make_pair
#define rep(i,n) for(int i=0,_n=n;i<_n;i++)
#define reps(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define pi 2.0*acos(0.0)
#define MAX 2147483647
#define MIN -2147483647
#define torad(a) (a*pi)/180.0;
#define eps 0.000000001
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front

typedef long long ll;
typedef vector<int>VI;
typedef map<string,int> MSI;
typedef set<int>SI;
typedef pair<int,int>PAR;
typedef vector<PAR>VP;



int main()
{
	freopen("i4.txt","r",stdin);
	freopen("o4.txt","w",stdout);
	int kas,cas,d[109],n[109],w[109],e[109],s[109],dd[109],dp[109],ds[109],N;
	int intval[10000];
	cin>>kas;
	rep(cas,kas){
	    cin>>N;
	    memset(intval,0,sizeof(intval));
	    vector <pair<int,pair<PAR,int> > > range;

	    rep(i,N){
	        cin>>d[i]>>n[i]>>w[i]>>e[i]>>s[i]>>dd[i]>>dp[i]>>ds[i];
	        w[i]+=300;
	        e[i]+=300;
	        rep(j,n[i]){
	            w[i]+=dp[i];
	            e[i]+=dp[i];
	            s[i]+=ds[i];
 	            range.pb(mp(j*dd[i]+d[i],mp(mp(w[i],e[i]),s[i])));
	        }
	    }

	    sort(range.begin(),range.end());
	    int mi = 0,ret=0;
	    rep(i,range.size()){
	        int day = range[i].first;
	        vector<pair<int,PAR> > V;
	        //cout<<i<<endl;
	        //reps(it,100,500)cout<<intval[it]<<" ";cout<<endl;
	        while(range[i].first==day){

                int w = range[i].second.first.first;
                int e = range[i].second.first.second;
                int s = range[i].second.second;
                int f = 0;

                reps(j,w,e+1){
                    if(intval[j]<s)f=1;
                }
                ret+=f;
                V.pb(mp(s,mp(w,e)));
                i++;
	        }

	        rep(j,V.size()){
	            //cout<<V[j].second.first<<" ttttttt    "<<V[j].second.second+1<<endl;
	            reps(k,V[j].second.first,V[j].second.second+1){
	                intval[k]=max(intval[k],V[j].first);
	            }
	        }
	        i--;
	    }
	    cout<<"Case #"<<cas+1<<": "<<ret<<endl;
	}

return 0;
}
